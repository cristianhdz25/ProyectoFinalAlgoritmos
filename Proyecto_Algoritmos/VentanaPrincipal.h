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
#include "Drawing.h"
#include "VentanaDibujo.h"
#include "WindowLogin.h"
#include "WindowConfig.h"

class VentanaPrincipal : public Gtk::Window {
public:

    VentanaPrincipal();
    void init();
    void mostrarVentanaRegistrar();
    void aboutWinClose();
    void mostrarVentanaItinerario();
    void showWindowLogin();
    void showWindowConfig();
    void showWindowUpdate();
    void showWindowDelete();
    void showWindowReserve();
    void clickedOpenAdmin();
    void mostrarVentanaVuelos();
    void exit();
private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuSesion, menuGestion, menuAdmin;
    Gtk::Menu subMenuSesion, subMenuGestion, subMenuAdmin;
    Gtk::ImageMenuItem itemRegistrar, itemLogin, itemConfig, itemSalir, itemReserve, itemActualizar, itemEliminar, itemAdmin, itemVuelo;


    Gtk::Fixed fixed; // contenedor
    VentanaRegistrar* ventanaRegistrar;
    VentanaItinerarios* ventanaItinerarios;
    VentanaAdmin* ventanaAdmin;
    VentanaReservar * ventanaReservar;
    WindowLogin * windowLogin;
    Drawing* drawing;
    VentanaDibujo* ventanaDibujo;
    WindowConfig * windowConfig;
};

#endif /* VENTANAPRINCIPAL_H */

