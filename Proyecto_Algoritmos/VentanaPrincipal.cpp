
#include "VentanaPrincipal.h"
#include <bits/stl_tempbuf.h>
#include "iostream"
#include "VentanaAdmin.h"
#include <gtkmm.h>

VentanaPrincipal::VentanaPrincipal() {
    this->set_size_request(600, 600);
    init();
}//constructor

void VentanaPrincipal::init() {
    this->fixed.put(menuBar, 0, 0); // se agrega el menuBar al contenedor fixed
    this->menuArchivo.set_label("Reservar");
    this->menuBar.append(this->menuArchivo);
    this->menuArchivo.set_submenu(this->subMenuArchivo);
    this->menuRegistrar.set_label("Reservar");
    this->menuAdmin.set_label("Cuenta Administrador");
    this->menuVuelo.set_label("Vuelos");
    
    this->menuRegistrar.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::mostrarVentanaRegistrar));
    this->subMenuArchivo.append(this->menuRegistrar);

    this->menuVuelo.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::mostrarVentanaVuelos));
    this->subMenuArchivo.append(this->menuVuelo);

    this->menuAdmin.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::clickedOpenAdmin));
    this->subMenuArchivo.append(this->menuAdmin);

    this->ventanaMostrarVuelo = 0;
    this->ventanaDibujo = 0;
    this->ventanaAdmin = 0;
    this->ventanaRegistrar = 0;
    this->ventanaItinerarios = 0;
    this->add(fixed);
    this->show_all_children();
}//init

void VentanaPrincipal::mostrarVentanaVuelos() {
    if (this->ventanaMostrarVuelo != 0)
        return;

    this->ventanaMostrarVuelo = new VentanaMostrarVuelos();
    this->ventanaMostrarVuelo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaMostrarVuelo->show();
    
    if (this->ventanaDibujo != 0)
        return;

    this->ventanaDibujo = new VentanaDibujo();
    this->ventanaDibujo->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaDibujo->show();
    

}//mostrarVuelo

void VentanaPrincipal::mostrarVentanaRegistrar() {

    if (this->ventanaRegistrar != 0)
        return;

    this->ventanaRegistrar = new VentanaRegistrar();
    this->ventanaRegistrar->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaRegistrar->show();
}//mostrarVentanaRegistrar

void VentanaPrincipal::mostrarVentanaItinerario() {
    if (this->ventanaItinerarios != 0)
        return;

    this->ventanaItinerarios = new VentanaItinerarios();
    this->ventanaItinerarios->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaItinerarios->show();
}//mostrarVentanaItinerario

void VentanaPrincipal::clickedOpenAdmin() {
    if (this->ventanaAdmin != 0)
        return;

    this->ventanaAdmin = new VentanaAdmin();
    this->ventanaAdmin->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaAdmin->show();
}//clickedOpenAdmin

void VentanaPrincipal::aboutWinClose() {
    this->ventanaRegistrar = 0;
    this->ventanaItinerarios = 0;
    this->ventanaAdmin = 0;
    this->ventanaMostrarVuelo=0;
    this->ventanaDibujo=0;
}//aboutWinClose