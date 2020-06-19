/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaPrincipal.h
 * Author: cristia
 *
 * Created on 3 de junio de 2020, 10:18 PM
 */

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <gtkmm.h>

#include "VentanaRegistrar.h"
#include "VentanaAdmin.h"
#include "VentanaMostrarVuelos.h"
#include "Drawing.h"
#include "VentanaDibujo.h"

class VentanaPrincipal : public Gtk::Window {
public:
    
    VentanaPrincipal();
    void init();
    void mostrarVentanaRegistrar();
    void aboutWinClose();
    void mostrarVentanaItinerario();
    void clickedOpenAdmin();
    void mostrarVentanaVuelos();
private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::Menu subMenuArchivo;
    Gtk::ImageMenuItem menuRegistrar,menuAdmin,menuVuelo;   
    
    
    Gtk::Fixed fixed; // contenedor
    VentanaRegistrar* ventanaRegistrar;
    VentanaItinerarios* ventanaItinerarios;
    VentanaAdmin* ventanaAdmin;
    VentanaMostrarVuelos* ventanaMostrarVuelo;
    Drawing* drawing;
    VentanaDibujo* ventanaDibujo;
};

#endif /* VENTANAPRINCIPAL_H */

