#include "ActualizarVuelo.h"
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include "iostream"
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 

ActualizarVuelo::ActualizarVuelo() {
    this->set_size_request(450, 500);
    this->set_title("Actualizar vuelo");
    this->claseGrande = ClaseGrande::getInstance();
    init();

}

void ActualizarVuelo::init() {
    this->lblAerolinea.set_label("Aerolinea");
    this->fixed.put(this->lblAerolinea, 20, 160);

    this->lblInformacion.set_label("Su informacion");
    this->fixed.put(this->lblInformacion, 20, 20);

    this->etAerolinea.set_editable(false);
    this->fixed.put(this->etAerolinea, 90, 180);
    this->etAerolinea.set_text(this->claseGrande->mostrarAerolinea());

    this->btnReservar.set_label("Seleccionar hora");
    this->btnReservar.signal_clicked().connect(sigc::mem_fun(*this, &ActualizarVuelo::onButtonClickedReservar));
    this->fixed.put(this->btnReservar, 120, 320);

    this->btnCancelar.set_label("Cancelar");
    this->btnCancelar.signal_clicked().connect(sigc::mem_fun(*this, &ActualizarVuelo::onButtonClickedCancelar));
    this->fixed.put(this->btnCancelar, 260, 320);

    this->btnArriba.set_label("Subir");
    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &ActualizarVuelo::onButtonClickedArriba));
    this->fixed.put(this->btnArriba, 260, 180);

    this->btnAbajo.set_label("Bajar");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &ActualizarVuelo::onButtonClickedAbajo));
    this->fixed.put(this->btnAbajo, 320, 180);

    mostrarItinerario();
    mostrarInfo();
    this->tvMostrar.set_editable(false);
    this->fixed.put(tvMostrar, 20, 220);

    this->tvMostrarInfo.set_editable(false);
    this->fixed.put(tvMostrarInfo, 20, 40);

    this->ventanaItinerarios = 0;

    this->add(this->fixed);
    this->show_all_children();
}

void ActualizarVuelo::onButtonClickedReservar() {
    this->claseGrande->getUsuarioActual()->GetTravel()->getAvion()->setQuantity(this->claseGrande->getUsuarioActual()->GetTravel()->getAvion()->getQuantity()+1);
    if (this->ventanaItinerarios != 0)
        return;

    this->ventanaItinerarios = new VentanaItinerarios();
    this->ventanaItinerarios->signal_hide().connect(sigc::mem_fun(*this, &ActualizarVuelo::aboutWinClose));
    this->ventanaItinerarios->show();
    this->hide();
}

void ActualizarVuelo::onButtonClickedCancelar() {
    this->hide();
}

void ActualizarVuelo::onButtonClickedArriba() {
    this->claseGrande->arriba();
    this->etAerolinea.set_text(this->claseGrande->mostrarAerolinea());
    mostrarItinerario();
}//arrriba

void ActualizarVuelo::onButtonClickedAbajo() {
    this->claseGrande->abajo();
    this->etAerolinea.set_text(this->claseGrande->mostrarAerolinea());
    mostrarItinerario();
}//abajo

void ActualizarVuelo::mostrarItinerario() {
    this->muestraItinerario = Gtk::TextBuffer::create();
    muestraItinerario->set_text(this->claseGrande->mostrarItinerarios());
    this->tvMostrar.set_buffer(muestraItinerario);
}

void ActualizarVuelo::mostrarInfo() {
    this->muestraInfo = Gtk::TextBuffer::create();
    muestraInfo->set_text(this->claseGrande->getUsuarioActual()->toString());
    this->tvMostrarInfo.set_buffer(muestraInfo);
}

void ActualizarVuelo::aboutWinClose() {
    this->ventanaItinerarios = 0;
}