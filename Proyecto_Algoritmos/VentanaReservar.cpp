
#include "VentanaReservar.h"
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include "iostream"
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 

VentanaReservar::VentanaReservar() {
    this->set_size_request(400, 300);
    this->set_title("Reservar");
    this->claseGrande = ClaseGrande::getInstance();
    init();
}

void VentanaReservar::init() {
    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 20, 40);

    this->etAerolinea.set_editable(false);
    this->fixed.put(this->etAerolinea, 90, 40);
    this->etAerolinea.set_text(this->claseGrande->mostrarAerolinea());

    this->btnReservar.set_label("Seleccionar hora");
    this->btnReservar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaReservar::onButtonClickedReservar));
    this->fixed.put(this->btnReservar, 120, 200);

    this->btnCancelar.set_label("Cancelar");
    this->btnCancelar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaReservar::onButtonClickedCancelar));
    this->fixed.put(this->btnCancelar, 260, 200);

    this->btnArriba.set_label("Subir");
    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaReservar::onButtonClickedArriba));
    this->fixed.put(this->btnArriba, 260, 40);

    this->btnAbajo.set_label("Bajar");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaReservar::onButtonClickedAbajo));
    this->fixed.put(this->btnAbajo, 320, 40);
 
    mostrarItinerario();
    this->tvMostrar.set_editable(false);
    this->fixed.put(tvMostrar, 20, 80);

    this->ventanaItinerarios = 0;

    this->add(this->fixed);
    this->show_all_children();
}

void VentanaReservar::onButtonClickedReservar() {
    if (this->ventanaItinerarios != 0)
        return;

    this->ventanaItinerarios = new VentanaItinerarios();
    this->ventanaItinerarios->signal_hide().connect(sigc::mem_fun(*this, &VentanaReservar::aboutWinClose));
    this->ventanaItinerarios->show();
    this->hide();
}

void VentanaReservar::onButtonClickedCancelar() {
    this->hide();
}

void VentanaReservar::onButtonClickedArriba() {
    this->claseGrande->arriba();
    this->etAerolinea.set_text(this->claseGrande->mostrarAerolinea());
    mostrarItinerario();
}//arrriba

void VentanaReservar::onButtonClickedAbajo() {
    this->claseGrande->abajo();
    this->etAerolinea.set_text(this->claseGrande->mostrarAerolinea());
    mostrarItinerario();
}//abajo

void VentanaReservar::mostrarItinerario() {
    this->muestraItinerario = Gtk::TextBuffer::create();
    muestraItinerario->set_text(this->claseGrande->mostrarItinerarios());
    this->tvMostrar.set_buffer(muestraItinerario);
}

void VentanaReservar::aboutWinClose() {
    this->ventanaItinerarios = 0;
}