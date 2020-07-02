/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowUpdateItinerarie.cpp
 * Author: cristia
 * 
 * Created on 1 de julio de 2020, 07:57 PM
 */

#include "WindowUpdateItinerarie.h"
#include "WindowUpdateAirlane.h"
#include "WindowAddNewAirline.h"
#include "Validaciones.h"

WindowUpdateItinerarie::WindowUpdateItinerarie() {
    this->set_size_request(500, 400);
    this->set_title("Actualizar Itinerario");
    this->claseGrande = ClaseGrande::getInstance();
    init();
}

void WindowUpdateItinerarie::init() {
    this->lblName.set_label("Seleccione aerolinea para actualizar");
    this->etName.set_text(this->claseGrande->mostrarAerolinea());
    this->fixedActualizarItinerario.put(this->lblName, 20, 20);
    this->fixedActualizarItinerario.put(this->etName, 20, 40);
    this->etName.set_editable(false);

    this->lblItinerario.set_label("Seleccione itinerario para actualizar");
    this->fixedActualizarItinerario.put(this->lblItinerario, 20, 120);
    this->fixedActualizarItinerario.put(this->etItinerario, 20, 140);
    this->etItinerario.set_editable(false);
    this->etItinerario.set_text(this->claseGrande->mostrarItinerario());

    this->lblSalida.set_label("Salida");
    this->fixedActualizarItinerario.put(this->lblSalida, 300, 20);
    this->fixedActualizarItinerario.put(this->etSalida, 300, 40);

    this->lblDestination.set_label("Destination");
    this->fixedActualizarItinerario.put(this->lblDestination, 300, 80);
    this->fixedActualizarItinerario.put(this->etDestination, 300, 100);

    this->lblSchedule.set_label("Horarios");
    this->fixedActualizarItinerario.put(this->lblSchedule, 300, 140);
    this->fixedActualizarItinerario.put(this->etSchedule, 300, 160);

    this->lblAvion.set_label("Nombre de Avión");
    this->fixedActualizarItinerario.put(this->lblAvion, 300, 200);
    this->fixedActualizarItinerario.put(this->etAvion, 300, 220);

    this->lblEspacios.set_label("Espacios del avión");
    this->fixedActualizarItinerario.put(this->lblEspacios, 300, 260);
    this->fixedActualizarItinerario.put(this->etEspacios, 300, 280);

    this->btSubir.set_label("Subir");
    this-> fixedActualizarItinerario.put(this->btSubir, 20, 80);
    this->btSubir.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateItinerarie::clickedUp));

    this->btSubirItinerario.set_label("Subir itinerario");
    this-> fixedActualizarItinerario.put(this->btSubirItinerario, 20, 180);
    this->btSubirItinerario.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateItinerarie::clickedUpItineraries));

    this->btnActualizar.set_label("Actualizar");
    this-> fixedActualizarItinerario.put(this->btnActualizar, 300, 320);
    this->btnActualizar.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateItinerarie::clickedActualizarAerolinea));

    this->btCancel.set_label("Cancelar");
    this-> fixedActualizarItinerario.put(this->btCancel, 400, 320);
    this->btCancel.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateItinerarie::clickedCancelar));

    this->btnBorrar.set_label("Eliminar itinerario");
    this->fixedActualizarItinerario.put(this->btnBorrar, 20, 220);
    this->btnBorrar.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateItinerarie::clickedBorrar));

    this->add(this->fixedActualizarItinerario);
    this->show_all_children();
}

void WindowUpdateItinerarie::clickedActualizarAerolinea() {

    if (!this->etSalida.get_text().empty() && !this->etDestination.get_text().empty() && !this->etSchedule.get_text().empty()
            && !this->etAvion.get_text().empty() && !this->etEspacios.get_text().empty()) {

        if (this->valid.COMPROBARNUMEROS(this->etEspacios.get_text())) {
            this->claseGrande->getAerolineas()->front()->getItinerarios().front()->setOrigen(new Pais(this->etSalida.get_text()));
            this->claseGrande->getAerolineas()->front()->getItinerarios().front()->setDestino(new Pais(this->etDestination.get_text()));
            this->claseGrande->getAerolineas()->front()->getItinerarios().front()->setHora(this->etSchedule.get_text());
            this->claseGrande->getAerolineas()->front()->getItinerarios().front()->setAvion(new Avion(this->etAvion.get_text(), stoi(this->etEspacios.get_text())));
            Gtk::MessageDialog dialogo(
                    *this,
                    "Se actualizo correctamente",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.run();
            this->hide();

        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error al actualizar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Los espacios del avion es un numero");
            dialogo.run();
        }
    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "Error al actualizar",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.set_secondary_text("Verifique que no hayan espacios en blanco");
        dialogo.run();
    }
}

void WindowUpdateItinerarie::clickedUpItineraries() {
    this->claseGrande->subirItinerario();
    this->etItinerario.set_text(this->claseGrande->mostrarItinerario());

}

void WindowUpdateItinerarie::clickedBorrar() {
    this->claseGrande->getAerolineas()->front()->eliminarItinerario();
    Gtk::MessageDialog dialogo(
            *this,
            "Se elimino correctamente",
            false,
            Gtk::MESSAGE_INFO
            );
    dialogo.run();
    this->hide();
}

void WindowUpdateItinerarie::clickedUp() {
    this->claseGrande->arriba();
    this->etName.set_text(this->claseGrande->mostrarAerolinea());
    this->etItinerario.set_text(this->claseGrande->mostrarItinerario());
}

void WindowUpdateItinerarie::clickedCancelar() {
    this->hide();
}

