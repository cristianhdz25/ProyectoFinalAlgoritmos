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
    
    Grafo grafo;
    grafo.agragarAristaYPeso(new Vertice(new Pais("CR")),new Vertice(new Pais("PN")),10);
    grafo.agragarAristaYPeso(new Vertice(new Pais("EU")),new Vertice(new Pais("PN")),52);
    grafo.agragarAristaYPeso(new Vertice(new Pais("PN")),new Vertice(new Pais("COL")),82);
    grafo.agragarAristaYPeso(new Vertice(new Pais("CR")),new Vertice(new Pais("COL")),152);
    grafo.agragarAristaYPeso(new Vertice(new Pais("CR")),new Vertice(new Pais("COL")),152);
    cout<<grafo.toString()<<endl;
    
    /*
        Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create(argc, argv, "flag2");
    
        VentanaPrincipal ventana;
        ventana.set_title("Ventana Principal");
    
        return app->run(ventana);
     */
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

