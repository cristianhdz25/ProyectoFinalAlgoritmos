
#include "VentanaAdmin.h"
#include "UsuarioAdministradorBusiness.h"
#include "UsuarioAdministrador.h"
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

VentanaAdmin::VentanaAdmin() {
    this->set_size_request(220, 200);
    this->set_title("Administrador");
    init();
}//constructor

void VentanaAdmin::init() {
    this->lblPassword.set_text("Password");
    this->fixed.put(this->lblPassword, 20, 80);
    this->fixed.put(this->etPassword, 20, 100);

    this->btAceptar.set_label("Ingresar");
    this->btAceptar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAdmin::clickedIn));
    this->fixed.put(this->btAceptar, 125, 140);
    this->ventanaGestionar = 0;

    this->lblUserName.set_label("UserName");
    this->fixed.put(this->lblUserName, 20, 20);
    this->fixed.put(this->etUserName, 20, 40);

    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaAdmin::clickedIn() {

    if (!this->etPassword.get_text().empty() &&!this->etUserName.get_text().empty()) {

        UsuarioAdministrador* uA = new UsuarioAdministrador(this->etPassword.get_text(), this->etUserName.get_text());
        UsuarioAdministradorBusiness uBusiness;
        
        if (uBusiness.iniciarSesionAdministrador(uA)) {

            if (this->ventanaGestionar != 0)
                return;

            this->ventanaGestionar = new VentanaGestionar();
            this->ventanaGestionar->signal_hide().connect(sigc::mem_fun(*this, &VentanaAdmin::aboutWinClose));
            this->ventanaGestionar->show();

            this->hide();
        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error al registrar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Usuario o contraseña invalido");
            dialogo.run();
        }
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "Error al registrar",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.set_secondary_text("Espacios en blanco");
        dialogo.run();
    }
}//clickedIn

void VentanaAdmin::aboutWinClose() {
    this->ventanaGestionar = 0;
}//aboutWInClose
