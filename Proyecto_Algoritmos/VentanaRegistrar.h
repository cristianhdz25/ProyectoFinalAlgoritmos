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
    Gtk::Label lblEdad;
    Gtk::Label lblNombre;
    Gtk::Label lblGenero;
    Gtk::Label lblPasaporte;
    Gtk::Label lblNacionalidad;

    Gtk::Entry etEdad;
    Gtk::Entry etNombre;
    Gtk::Entry etGenero;
    Gtk::Entry etPasaporte;
    Gtk::Entry etNacionalidad;

    Gtk::Button btnRegistrar;
    Gtk::Button btnCancelar;

    Gtk::Fixed fixed;
    VentanaReservar * ventanaReservar;
};

#endif /* VENTANAREGISTRAR_H */

