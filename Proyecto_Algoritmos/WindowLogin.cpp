/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowLogin.cpp
 * Author: cristia
 * 
 * Created on 21 de junio de 2020, 08:52 PM
 */

#include "WindowLogin.h"

#include <gtkmm.h>
#include "Client.h"

WindowLogin::WindowLogin() {
    this->set_size_request(200, 200);
    this->set_title("Ingresar");
    init();
}

void WindowLogin::init() {
    this->lblPassport.set_label("Pasaporte");
    this->fixed.put(this->lblPassport, 20, 20);
    this->fixed.put(this->etPassport, 20, 40);

    this->lblPassword.set_label("Contraseña");
    this->fixed.put(this->lblPassword, 20, 80);
    this->fixed.put(this->etPassword, 20, 100);

    this->btnLogin.set_label("Ingresar");
    this->btnLogin.signal_clicked().connect(sigc::mem_fun(*this, &WindowLogin::onButtonClickedLogin));
    this->fixed.put(this->btnLogin, 50, 140);

    this->btnExit.set_label("Salir");
    this->btnExit.signal_clicked().connect(sigc::mem_fun(*this, &WindowLogin::onButtonClickedExit));
    this->fixed.put(this->btnExit, 135, 140);

    
    this->claseGrande=ClaseGrande::getInstance();
    this->add(this->fixed);
    this->show_all_children();
}//init()

void WindowLogin::onButtonClickedLogin() {
    if (!this->etPassport.get_text().empty() && !this->etPassword.get_text().empty()) {
          cout << "clicked Entro" << endl;
          
        Client * client = this->claseGrande->searchClient(this->etPassport.get_text(), this->etPassword.get_text());
        
        if (client != NULL) {
            
            Gtk::MessageDialog dialogo(
                    *this,
                    "Se ha iniciado sesion exitosamente",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.run();
              cout << "if clicked Entro" << endl;
        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error al iniciar sesion",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Datos no existen");
            dialogo.run();
        }//if-else

    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "Error al iniciar sesion",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.set_secondary_text("Espacios en blanco");
        dialogo.run();
    }//else
}//

void WindowLogin::onButtonClickedExit() {
    this->hide();
}


