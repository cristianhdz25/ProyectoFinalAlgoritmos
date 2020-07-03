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
    AerolineaData * aD = AerolineaData::getInstance();
    aD->initItinerarios();
    return app->run(ventana);

    /*
    AerolineaData *a=AerolineaData::getInstance();
    
    queue<Itinerario*>* itinerarios=new queue<Itinerario*>();
    
    Avion* avion=new Avion("P",10);
    
    itinerarios->push(new Itinerario(new Pais("A"),new Pais("B"), 10,20,avion));
    itinerarios->push(new Itinerario(new Pais("C"),new Pais("D"), 10,20,avion));
    itinerarios->push(new Itinerario(new Pais("E"),new Pais("F"), 10,20,avion));
    
    Aerolinea* aerolinea=new Aerolinea("Penzoil");
    aerolinea->setItinerarios(itinerarios);
    
    a->registrarAerolinea(aerolinea);
    
    Grafo* grafo=Grafo::getInstance();
    
    grafo->agregarAristaYPeso(new Vertice(new Pais("A")),new Vertice(new Pais("B")),10,10,10);
    grafo->agregarAristaYPeso(new Vertice(new Pais("C")),new Vertice(new Pais("D")),10,10,10);
    grafo->agregarAristaYPeso(new Vertice(new Pais("E")),new Vertice(new Pais("F")),10,10,10);
    */
    
    return 0;
}

