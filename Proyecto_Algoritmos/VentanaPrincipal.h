#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <gtkmm.h>

#include "VentanaRegistrar.h"
#include "VentanaAdmin.h"
#include "Drawing.h"
#include "VentanaDibujo.h"
#include "WindowLogin.h"
#include "WindowConfig.h"
#include "ActualizarVuelo.h"
#include "DeleteWindow.h"
#include "WindowFlights.h"
#include "WindowDelete.h"
#include "ClaseGrande.h"
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
    void showWindowFlights();
    void clickedOpenAdmin();
    void mostrarVentanaVuelos();
    void exit();
private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuSesion, menuGestion, menuAdmin;
    Gtk::Menu subMenuSesion, subMenuGestion, subMenuAdmin;
    Gtk::ImageMenuItem itemRegistrar, itemLogin, itemConfig, itemSalir, 
            itemReserve, itemActualizar, itemEliminar, itemAdmin, itemVuelo, itemShowFlights;


    Gtk::Fixed fixed; // contenedor
    VentanaRegistrar* ventanaRegistrar;
    VentanaItinerarios* ventanaItinerarios;
    VentanaAdmin* ventanaAdmin;
    VentanaReservar * ventanaReservar;
    WindowLogin * windowLogin;
    Drawing* drawing;
    VentanaDibujo* ventanaDibujo;
    WindowConfig * windowConfig;
    ActualizarVuelo* actualizarVuelo;
    WindowDelete* deleteWindow;
    WindowFlights * windowFlights;
    ClaseGrande* claseGrande;
};

#endif /* VENTANAPRINCIPAL_H */


