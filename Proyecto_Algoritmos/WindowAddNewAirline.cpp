/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowAddNewAirline.cpp
 * Author: cristia
 * 
 * Created on 1 de julio de 2020, 08:10 PM
 */

#include "WindowAddNewAirline.h"

WindowAddNewAirline::WindowAddNewAirline() {
    this->set_size_request(500, 500);
    this->set_title("Registrar Aerolinea");
    this->claseGrande = ClaseGrande::getInstance();
    this->grafo = Grafo::getInstance();
    init();
}

void WindowAddNewAirline::init() {
    this->lblName.set_label("Nueva Aerolinea");
    this->fixedAirline.put(this->lblName, 20, 20);
    this->fixedAirline.put(this->etName, 20, 40);

    this->btAdd.set_label("Guardar");
    this-> fixedAirline.put(this->btAdd, 300, 400);
    this->btAdd.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddNewAirline::clickedAddAirline));

    this->btnAddItinerarie.set_label("Añadir Itinerario");
    this->fixedAirline.put(this->btnAddItinerarie, 400, 400);
    this->btnAddItinerarie.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddNewAirline::clickedAddtinerarie));

    this->lblAvion.set_label("Nombre de Avion");
    this->fixedAirline.put(this->lblAvion, 300, 260);
    this->fixedAirline.put(this->etAvion, 300, 280);

    this->lblEspacios.set_label("Espacios del avión");
    this->fixedAirline.put(this->lblEspacios, 300, 320);
    this->fixedAirline.put(this->etEspacios, 300, 340);

    this->lblSalida.set_label("Salida");
    this->fixedAirline.put(this->lblSalida, 300, 20);
    this->fixedAirline.put(this->etSalida, 300, 40);

    this->lblDestination.set_label("Destination");
    this->fixedAirline.put(this->lblDestination, 300, 80);
    this->fixedAirline.put(this->etDestination, 300, 100);

    this->lblSchedule.set_label("Horarios");
    this->fixedAirline.put(this->lblSchedule, 300, 140);
    this->fixedAirline.put(this->etSchedule, 300, 160);

    this->lblPeso.set_label("Duración del vuelo");
    this->fixedAirline.put(this->lblPeso, 300, 200);
    this->fixedAirline.put(this->etPeso, 300, 220);

    this->add(this->fixedAirline);
    this->show_all_children();
}

void WindowAddNewAirline::clickedAddtinerarie() {
    if (!(this->etSalida.get_text().empty()) &&
            !(this->etDestination.get_text().empty())&&
            !(this->etSchedule.get_text().empty())) {

        if (this->valid.COMPROBARNUMEROS(this->etEspacios.get_text())) {

            Avion* tempA = new Avion(this->etAvion.get_text(), stoi(this->etEspacios.get_text()));

            tempItinerario.push(new Itinerario(new Pais(this->etSalida.get_text()), (new Pais(this->etDestination.get_text())),
                    this->etSchedule
                    .get_text(), tempA));

            this->etSalida.set_text("");
            this->etDestination.set_text("");
            this->etSchedule.set_text("");

        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error al agregar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Los espacios del avion es un numero");
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
}//clickedAddtinerariew

void WindowAddNewAirline::clickedAddAirline() {
    if (!(this->etName.get_text().empty())) {
        if(this->valid.COMPROBARNUMEROS(this->etEspacios.get_text())){
        Aerolinea* temp = new Aerolinea(this->etName.get_text());
        temp->setItinerarios(tempItinerario);
        this->claseGrande->registrarAerolinea(temp);
        Gtk::MessageDialog dialogo(
                    *this,
                    "Se registro correctamente",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.run();
        }else{
        Gtk::MessageDialog dialogo(
                    *this,
                    "Error al registrar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("La duracion es un numero");
            dialogo.run();
        }
    }else{
         Gtk::MessageDialog dialogo(
                    *this,
                    "Error al registrar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Espacio del nombre en blanco");
            dialogo.run();
    }
}//clickedAddAirline



