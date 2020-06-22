/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaRegistrar.h
 * Author: cristia
 *
 * Created on 5 de junio de 2020, 07:55 PM
 */

#ifndef VENTANAREGISTRAR_H
#define VENTANAREGISTRAR_H

#include <gtkmm.h>

#include "VentanaReservar.h"

class VentanaRegistrar : public Gtk::Window {
public:

    VentanaRegistrar();
    void init();
    void onButtonClickedRegistrar();
    void onButtonClickedCancelar();
    void aboutWinClose();
   
private:
    Gtk::Label lblEdad,lblNombre,lblGenero,lblPasaporte,lblNacionalidad,lblPassword;

    Gtk::Entry etEdad,etNombre,etGenero,etPasaporte,etNacionalidad,etPassword;

    Gtk::Button btnRegistrar,btnCancelar;

    Gtk::Fixed fixed;
    VentanaReservar * ventanaReservar;
    ClaseGrande * claseGrande;
};

#endif /* VENTANAREGISTRAR_H */

