#include "VentanaPrincipal.h"
#include <bits/stl_tempbuf.h>
#include "iostream"
#include "VentanaAdmin.h"
#include "WindowDelete.h"
#include <gtkmm.h>

VentanaPrincipal::VentanaPrincipal() {
    this->set_size_request(600, 600);
    this->claseGrande = ClaseGrande::getInstance();
    init();
}//constructor

void VentanaPrincipal::init() {
    this->fixed.put(menuBar, 0, 0); // se agrega el menuBar al contenedor fixed
    //Menus
    this->menuSesion.set_label("Sesion");
    this->menuBar.append(this->menuSesion);
    this->menuSesion.set_submenu(this->subMenuSesion);
    //-----------------//
    this->menuGestion.set_label("Gestion");
    this->menuBar.append(this->menuGestion);
    this->menuGestion.set_submenu(this->subMenuGestion);
    //-----------------//
    this->menuAdmin.set_label("Administracion");
    this->menuBar.append(this->menuAdmin);
    this->menuAdmin.set_submenu(this->subMenuAdmin);
    //-----------------//

    //Items
    this->itemRegistrar.set_label("Registrarse");
    this->itemLogin.set_label("Iniciar Sesion");
    this->itemConfig.set_label("Configurar cuenta");
    this->itemSalir.set_label("Salir");
    //-----//
    this->itemReserve.set_label("Reservar vuelo");
    this->itemShowFlights.set_label("Ver vuelos");
    this->itemActualizar.set_label("Actualizar vuelo");
    this->itemEliminar.set_label("Eliminar vuelo");
    //-----//
    this->itemAdmin.set_label("Modo administrador");
    this->itemVuelo.set_label("Trafico aereo");

    //Sesion
    this->itemRegistrar.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::mostrarVentanaRegistrar));
    this->subMenuSesion.append(this->itemRegistrar);

    this->itemLogin.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::showWindowLogin));
    this->subMenuSesion.append(this->itemLogin);

    this->itemConfig.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::showWindowConfig));
    this->subMenuSesion.append(this->itemConfig);

    this->itemSalir.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::exit));
    this->subMenuSesion.append(this->itemSalir);
    //----------------------------//
    //Gestion
    this->itemReserve.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::showWindowReserve));
    this->subMenuGestion.append(this->itemReserve);

    this->itemShowFlights.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::showWindowFlights));
    this->subMenuGestion.append(this->itemShowFlights);

    this->itemActualizar.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::showWindowUpdate));
    this->subMenuGestion.append(this->itemActualizar);

    this->itemEliminar.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::showWindowDelete));
    this->subMenuGestion.append(this->itemEliminar);

    //Administracion
    this->itemAdmin.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::clickedOpenAdmin));
    this->subMenuAdmin.append(this->itemAdmin);

    this->itemVuelo.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::mostrarVentanaVuelos));
    this->subMenuAdmin.append(this->itemVuelo);

    this->windowFlights = 0;
    this->windowConfig = 0;
    this->windowLogin = 0;
    this->ventanaReservar = 0;
    this->ventanaDibujo = 0;
    this->ventanaAdmin = 0;
    this->ventanaRegistrar = 0;
    this->ventanaItinerarios = 0;
    this->actualizarVuelo = 0;
    this->deleteWindow = 0;

    this->add(fixed);
    this->show_all_children();
}//init
//Sesion

void VentanaPrincipal::mostrarVentanaRegistrar() {



    this->ventanaRegistrar = new VentanaRegistrar();

    this->ventanaRegistrar->show();
}//mostrarVentanaRegistrar

void VentanaPrincipal::showWindowLogin() {

    this->windowLogin = new WindowLogin();

    this->windowLogin->show();
}

void VentanaPrincipal::showWindowConfig() {
    if (this->claseGrande->getUsuarioActual() != NULL) {

        this->windowConfig = new WindowConfig();

        this->windowConfig->show();

    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "NO se puede hacer esta acción sin iniciar sesión",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.run();

    }//else
}

void VentanaPrincipal::exit() {
    this->hide();
}//exit

//Gestion

void VentanaPrincipal::showWindowReserve() {

    if (this->claseGrande->getUsuarioActual() != NULL) {
        this->ventanaReservar = new VentanaReservar();
        this->ventanaReservar->show();

    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "NO se puede hacer esta acción sin iniciar sesión",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.run();

    }//else
}

void VentanaPrincipal::showWindowFlights() {

    if (this->claseGrande->getUsuarioActual() != NULL) {

        this->windowFlights = new WindowFlights();
        this->windowFlights->show();
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "NO se puede hacer esta acción sin iniciar sesión",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.run();

    }//else

}

void VentanaPrincipal::showWindowDelete() {
    if (this->claseGrande->getUsuarioActual() != NULL) {

        this->deleteWindow = new WindowDelete();
        this->deleteWindow->show();
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "NO se puede hacer esta acción sin iniciar sesión",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.run();

    }//else

}//showWindowDelete

void VentanaPrincipal::showWindowUpdate() {
    if (this->claseGrande->getUsuarioActual() != NULL) {
        this->actualizarVuelo = new ActualizarVuelo();
        this->actualizarVuelo->show();
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "NO se puede hacer esta acción sin iniciar sesión",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.run();

    }//else

}

//Administracion

void VentanaPrincipal::clickedOpenAdmin() {
   
        this->ventanaAdmin = new VentanaAdmin();
        this->ventanaAdmin->show();
  

}//clickedOpenAdmin

void VentanaPrincipal::mostrarVentanaVuelos() {
    if (this->claseGrande->getUsuarioActual() != NULL) {
        this->ventanaDibujo = new VentanaDibujo();
        this->ventanaDibujo->show();
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "NO se puede hacer esta acción sin iniciar sesión", 
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.run();

    }//else

}//mostrarVuelo

void VentanaPrincipal::aboutWinClose() {
    this->ventanaReservar = 0;
    this->ventanaRegistrar = 0;
    this->ventanaItinerarios = 0;
    this->ventanaAdmin = 0;
    this->ventanaDibujo = 0;
    this->actualizarVuelo = 0;
    this->deleteWindow = 0;
    this->windowFlights = 0;
}//aboutWinClose
