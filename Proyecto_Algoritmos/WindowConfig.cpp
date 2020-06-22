/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowConfig.cpp
 * Author: cristia
 * 
 * Created on 21 de junio de 2020, 09:27 PM
 */

#include "WindowConfig.h"
#include "VentanaRegistrar.h"
#include <bits/stl_tempbuf.h>
#include "iostream"
#include "Validaciones.h"
#include <gtkmm.h>
#include "Client.h"

WindowConfig::WindowConfig() {
    this->set_size_request(350, 350);
    this->set_title("Actualizar");
    this->claseGrande = ClaseGrande::getInstance();
    init();
}

void WindowConfig::init() {

    this->lblAge.set_label("Edad");
    this->fixed.put(this->lblAge, 20, 20);
    this->fixed.put(this->etAge, 120, 20);

    this->lblName.set_label("Nombre");
    this->fixed.put(this->lblName, 20, 60);
    this->fixed.put(this->etName, 120, 60);

    this->lblGender.set_label("Genero");
    this->fixed.put(this->lblGender, 20, 100);
    this->fixed.put(this->etGender, 120, 100);

    this->lblPassport.set_label("Pasaporte");
    this->fixed.put(this->lblPassport, 20, 140);
    this->fixed.put(this->etPassport, 120, 140);

    this->lblNacionality.set_label("Nacionalidad");
    this->fixed.put(this->lblNacionality, 20, 180);
    this->fixed.put(this->etNacionality, 120, 180);

    this->lblPassword.set_label("Contraseña");
    this->fixed.put(this->lblPassword, 20, 220);
    this->fixed.put(this->etPassword, 120, 220);

    this->btnUpdate.set_label("Registrar");
    this->btnUpdate.signal_clicked().connect(sigc::mem_fun(*this, &WindowConfig::onButtonClickedUpdate));
    this->fixed.put(this->btnUpdate, 150, 260);

    this->btnExit.set_label("Cancelar");
    this->btnExit.signal_clicked().connect(sigc::mem_fun(*this, &WindowConfig::onButtonClickedExit));
    this->fixed.put(this->btnExit, 250, 260);

    this->add(this->fixed);
    this->show_all_children();
}

void WindowConfig::onButtonClickedUpdate() {

    Validaciones val;

    if (!this->etAge.get_text().empty() &&!this->etGender.get_text().empty() && !this->etNacionality.get_text().empty()
            && !this->etName.get_text().empty()
            && !this->etPassport.get_text().empty() && !this->etPassword.get_text().empty()) {

        if (val.COMPROBARNUMEROS(this->etAge.get_text()) && val.COMPROBARNUMEROS(this->etAge.get_text())) {

            Client* client = new Client(this->etAge.get_text(),
                    this->etName.get_text(), this->etGender.get_text(),
                    this->etPassport.get_text() ,this->etPassword.get_text(),new Pais(this->etNacionality.get_text()));
            this->claseGrande->registrarCliente(client);
        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error al registrar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("La edad y el pasaporte son numeros");
            dialogo.run();
        }
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "Error al registrar",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.set_secondary_text("Verifique que no hayan espacios en blanco");
        dialogo.run();
    }
}//registrar

void WindowConfig::onButtonClickedExit() {
    this->hide();
}





