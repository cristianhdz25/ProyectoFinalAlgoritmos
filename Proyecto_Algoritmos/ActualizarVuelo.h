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
    void mostrarInfo();
        
private:
    Gtk::Label lblAerolinea, lblInformacion;
    Gtk::Entry etAerolinea;
    Gtk::Button btnArriba, btnAbajo, btnReservar, btnCancelar;
    Gtk::Fixed fixed;
    Glib::RefPtr<Gtk::TextBuffer> muestraItinerario, muestraInfo;
    Gtk::TextView tvMostrar, tvMostrarInfo;
    VentanaItinerarios * ventanaItinerarios;
    ClaseGrande * claseGrande;
};
#endif /* ACTUALIZARVUELO_H */

