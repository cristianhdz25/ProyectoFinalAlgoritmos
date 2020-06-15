#include "VentanaItinerarios.h"
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 
#include <sstream>
#include "string.h"
#include <iostream>
using namespace std;

VentanaItinerarios::VentanaItinerarios() {
    this->set_size_request(350, 300);
    this->set_title("Reservar");
    
    this->claseGrande = ClaseGrande::getInstance();
    init();
}//constructor

void VentanaItinerarios::init() {
    this->lblAerolinea.set_label("Aerolinea seleccionada: " + this->claseGrande->mostrarAerolinea());
    this->fixed.put(this->lblAerolinea, 20, 20);

    this->etHora.set_editable(false);
    this->fixed.put(this->etHora, 20, 140);
    if(!this->claseGrande->getAerolineas().front()->getItinerarios().empty())
        this->etHora.set_text(this->claseGrande->mostrarItinerario());

    this->btnAceptar.set_label("Aceptar");
    this->btnAceptar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerarios::onButtonClickedAceptar));
    this->fixed.put(this->btnAceptar, 180, 250);

    this->btnCancelar.set_label("Cancelar");
    this->btnCancelar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerarios::onButtonClickedCancelar));
    this->fixed.put(this->btnCancelar, 260, 250);

    this->btnArriba.set_label("Subir");
    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaItinerarios::onButtonClickedArriba));
    this->fixed.put(this->btnArriba, 200, 140);

    mostrarItinerario();
    this->tvMostrar.set_editable(false);
    this->fixed.put(tvMostrar, 20, 40);
   
    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaItinerarios::onButtonClickedAceptar() {
    
}

void VentanaItinerarios::onButtonClickedCancelar() {
    this->hide();
}

void VentanaItinerarios::mostrarItinerario() {
    this->muestraItinerario = Gtk::TextBuffer::create();
    muestraItinerario->set_text(this->claseGrande->mostrarItinerarios());
    this->tvMostrar.set_buffer(muestraItinerario);
}

void VentanaItinerarios::onButtonClickedArriba() {
    this->claseGrande->subirItinerario();
    this->etHora.set_text(this->claseGrande->mostrarItinerario());
}//un button
