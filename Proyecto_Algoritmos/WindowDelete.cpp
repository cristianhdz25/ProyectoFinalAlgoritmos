/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowDelete.cpp
 * Author: cristia
 * 
 * Created on 29 de junio de 2020, 07:31 PM
 */

#include "WindowDelete.h"

WindowDelete::WindowDelete() {
    this->set_size_request(360, 250);
    this->set_title("Eliminar vuelo");
    this->claseGrande = ClaseGrande::getInstance();
    init();
}

void WindowDelete::init() {
    this->lblInformacion.set_label("Su informacion");
    this->fixed.put(this->lblInformacion, 20, 20);

    mostrarInfo();
    this->tvMostrar.set_editable(false);
    this->fixed.put(tvMostrar, 20, 40);
    
    this->btnEliminar.set_label("Eliminar");
    this->btnEliminar.signal_clicked().connect(sigc::mem_fun(*this, &WindowDelete::onButtonClickedBorrar));
    this->fixed.put(this->btnEliminar, 180, 180);

    this->btnCancelar.set_label("Cancelar");
    this->btnCancelar.signal_clicked().connect(sigc::mem_fun(*this, &WindowDelete::onButtonClickedCancelar));
    this->fixed.put(this->btnCancelar, 260, 180);
    
    this->add(this->fixed);
    this->show_all_children();
}

void WindowDelete::onButtonClickedCancelar() {
    this->hide();
}

void WindowDelete::onButtonClickedBorrar() {
    this->claseGrande->getUsuarioActual()->GetTravel()->getAvion()->setQuantity(this->claseGrande->getUsuarioActual()->GetTravel()->getAvion()->getQuantity()+1);
    Itinerario * vacio = NULL;
    this->claseGrande->getUsuarioActual()->SetTravel(vacio);
    Gtk::MessageDialog dialogo(
                    *this,
                    "Se ha eliminado con exito",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.run();
    this->hide();   
}

void WindowDelete::mostrarInfo() {
    this->muestraInfo = Gtk::TextBuffer::create();
    muestraInfo->set_text(this->claseGrande->getUsuarioActual()->toString());
    this->tvMostrar.set_buffer(muestraInfo);
}

