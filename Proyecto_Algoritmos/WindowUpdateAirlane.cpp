/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowUpdateAirlane.cpp
 * Author: cristia
 * 
 * Created on 1 de julio de 2020, 07:55 PM
 */

#include "WindowUpdateAirlane.h"
#include "ClaseGrande.h"

WindowUpdateAirlane::WindowUpdateAirlane() {
    this->set_size_request(300, 230);
    this->set_title("Actualizar Aerolinea");
    this->claseGrande = ClaseGrande::getInstance();
    init();
}

void WindowUpdateAirlane::init() {
    this->lblAirline.set_label("Aerolinea");
    this->fixed.put(this->lblAirline, 20, 20);
    this->fixed.put(this->etName, 20, 60);
    this->etName.set_text(this->claseGrande->mostrarAerolinea());
    this->etName.set_editable(false);

    this->lblNewName.set_label("Nuevo nombre");
    this->fixed.put(this->lblNewName, 20, 100);
    this->fixed.put(this->etNewName, 20, 120);

    this->btnUp.set_label("Subir");
    this->fixed.put(this->btnUp, 200, 60);
    this->btnUp.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateAirlane::clickedUp));

    this->btnDelete.set_label("Eliminar Aerolinea");
    this->fixed.put(this->btnDelete, 200, 120);
    this->btnDelete.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateAirlane::clickedDelete));

    this->btnAccept.set_label("Aceptar");
    this->fixed.put(this->btnAccept, 40, 180);
    this->btnAccept.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateAirlane::clickedAccept));

    this->btnCancel.set_label("Cancelar");
    this->fixed.put(this->btnCancel, 120, 180);
    this->btnCancel.signal_clicked().connect(sigc::mem_fun(*this, &WindowUpdateAirlane::clickedCancel));

    this->add(this->fixed);
    show_all_children();
}

void WindowUpdateAirlane::clickedUp() {
    this->claseGrande->arriba();
    this->etName.set_text(this->claseGrande->mostrarAerolinea());
}

void WindowUpdateAirlane::clickedAccept() {
    if (!this->etNewName.get_text().empty()) {
        this->claseGrande->getAerolineas()->front()->setNombre(this->etNewName.get_text());
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
        dialogo.set_secondary_text("El espacio del nombre esta vacio");
        dialogo.run();
    }
}

void WindowUpdateAirlane::clickedDelete() {
    AerolineaData *aD = AerolineaData::getInstance();
    aD->eliminarAerolinea();
    Gtk::MessageDialog dialogo(
            *this,
            "Se elimino correctamente",
            false,
            Gtk::MESSAGE_INFO
            );
    dialogo.run();
    this->hide();
}

void WindowUpdateAirlane::clickedCancel() {
    this->hide();
}