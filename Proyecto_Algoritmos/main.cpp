#include <cstdlib>
#include "VentanaPrincipal.h"
#include <gtkmm.h>
#include <iostream>
#include <vector>
#include "VentanaItinerarios.h"
#include "Aerolinea.h"
#include "ClaseGrande.h"
#include "Grafo.h"
using namespace std;

int main(int argc, char** argv) {
    Glib::RefPtr<Gtk::Application> app =
            Gtk::Application::create(argc, argv, "flag2");

    VentanaPrincipal ventana;
    ventana.set_title("Ventana Principal");

    return app->run(ventana);
    return 0;
}

