#ifndef ACTUALIZARVUELO_H
#define ACTUALIZARVUELO_H

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h>
#include "VentanaItinerarios.h"
#include "ClaseGrande.h" 

class ActualizarVuelo : public Gtk::Window {
public:
    ActualizarVuelo();
    void init();
    void onButtonClickedReservar();
    void onButtonClickedCancelar();
    void onButtonClickedArriba();
    void onButtonClickedAbajo();
    void mostrarItinerario();
    void aboutWinClose();
        
private:
    Gtk::Label lblAerolinea;
    Gtk::Entry etAerolinea;
    Gtk::Button btnArriba, btnAbajo, btnReservar, btnCancelar;
    Gtk::Fixed fixed;
    Glib::RefPtr<Gtk::TextBuffer> muestraItinerario;
    Gtk::TextView tvMostrar;
    VentanaItinerarios * ventanaItinerarios;
    ClaseGrande * claseGrande;
};
#endif /* ACTUALIZARVUELO_H */

