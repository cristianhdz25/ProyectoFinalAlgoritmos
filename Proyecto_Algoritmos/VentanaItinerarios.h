
#ifndef VENTANAITINERARIOS_H
#define VENTANAITINERARIOS_H
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 
#include "ClaseGrande.h"

class VentanaItinerarios : public Gtk::Window {
public:
    VentanaItinerarios();
    void init();
    void onButtonClickedAceptar();
    void onButtonClickedCancelar();
    void onButtonClickedArriba();
    void mostrarItinerario();
   

private:
    Gtk::Label lblAerolinea;
    Gtk::TextView tvMostrar;
    Gtk::Entry etHora;
    Gtk::Button btnArriba, btnAceptar, btnCancelar;    
    Glib::RefPtr<Gtk::TextBuffer> muestraItinerario;
    Gtk::Fixed fixed;
    ClaseGrande * claseGrande;    
};


#endif /* VENTANAITINERARIOS_H */

