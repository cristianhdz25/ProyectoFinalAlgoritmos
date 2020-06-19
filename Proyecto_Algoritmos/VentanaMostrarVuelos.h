#ifndef VENTANAMOSTRARVUELOS_H
#define VENTANAMOSTRARVUELOS_H
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 
#include <string>
#include "ClaseGrande.h"
using namespace std;

class VentanaMostrarVuelos : public Gtk::Window {
public:
    VentanaMostrarVuelos();
    void init();
    void clikedDraw();
private:
    Gtk::Entry etMostrarVertices;
    Gtk::Label lblMostrar;
    Gtk::Button btnMover;
    Gtk::Fixed fixed;
    ClaseGrande * claseGrande;
    int posicion;
};

#endif /* VENTANAMOSTRARVUELOS_H */

