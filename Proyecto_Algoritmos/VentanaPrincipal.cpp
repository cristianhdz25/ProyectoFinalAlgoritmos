
#include "VentanaPrincipal.h"
#include <bits/stl_tempbuf.h>
#include "iostream"
#include <gtkmm.h>

VentanaPrincipal::VentanaPrincipal() {
    this->set_size_request(600, 600);
    init();
}

void VentanaPrincipal::init() {
    this->fixed.put(menuBar, 0, 0); // se agrega el menuBar al contenedor fixed
    this->menuArchivo.set_label("Reservar");
    this->menuBar.append(this->menuArchivo);
    this->menuArchivo.set_submenu(this->subMenuArchivo);
    this->menuRegistrar.set_label("Reservar");
    
    this->menuRegistrar.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::mostrarVentanaRegistrar));           
    this->subMenuArchivo.append(this->menuRegistrar);
    
    this->ventanaRegistrar=0;
    this->ventanaItinerarios=0;
    this->add(fixed);
    this->show_all_children();
}

void VentanaPrincipal::mostrarVentanaRegistrar() {

        if (this->ventanaRegistrar != 0)
            return;

        this->ventanaRegistrar = new VentanaRegistrar();
        this->ventanaRegistrar->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
        this->ventanaRegistrar->show();
}

void VentanaPrincipal::mostrarVentanaItinerario() {
    if (this->ventanaItinerarios != 0)
            return;

        this->ventanaItinerarios = new VentanaItinerarios();
        this->ventanaItinerarios->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
        this->ventanaItinerarios->show();
}

void VentanaPrincipal::aboutWinClose(){
    this->ventanaRegistrar = 0;
    this->ventanaItinerarios=0;
}