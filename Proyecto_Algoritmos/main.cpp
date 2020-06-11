#include <cstdlib>
#include "VentanaPrincipal.h"
#include <gtkmm.h>
#include <iostream>
#include <vector>
#include "VentanaItinerarios.h"
#include "Aerolinea.h"
#include "ClaseGrande.h"
using namespace std;

int main(int argc, char** argv) {
        Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create(argc, argv, "flag2");
    
        VentanaPrincipal ventana;
        ventana.set_title("Ventana Principal");
    
        return app->run(ventana);
//Aerolinea* aerolinea=new Aerolinea("A");
//cout<<"1"<<((Itinerario*)aerolinea->getItinerarios().front())->toString()<<endl;
//aerolinea->arribaItinerarios();
//cout<<"2"<<((Itinerario*)aerolinea->getItinerarios().front())->toString()<<endl;
//aerolinea->arribaItinerarios();
//cout<<"3"<<((Itinerario*)aerolinea->getItinerarios().front())->toString()<<endl;


//ClaseGrande* claseGrande = ClaseGrande::getInstance();
//cout<<"mostrar: "<<aerolinea->mostrarItinerario()->toString()<<endl;
//aerolinea->arribaItinerarios();
//cout<<"mostrar: "<<aerolinea->mostrarItinerario()->toString()<<endl;

return 0;
}

