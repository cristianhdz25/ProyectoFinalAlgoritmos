#include "ClaseGrande.h"
#include "AerolineaData.h"
#include "Compra.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ClaseGrande::ClaseGrande() {
    this->aerolineaBusiness = new AerolineaBusiness();
    this->aerolineas = this->aerolineaBusiness->getAerolineas();
    this->grafo = Grafo::getInstance();
}//constructor

ClaseGrande* ClaseGrande::getInstance() {
    if (instance == 0) {
        instance = new ClaseGrande();
    }//if
    return instance;

}//getInstance

ClaseGrande::~ClaseGrande() {
}

//Método para registrar una aerolinea

void ClaseGrande::registrarAerolinea(Aerolinea* aerolinea) {
    this->aerolineaBusiness->registrarAerolinea(aerolinea);
    this->aerolineas = this->aerolineaBusiness->getAerolineas();
}//registrarAerolinea

//método para registrar un itinerario

string ClaseGrande::mostrarAerolinea() {
    return this->aerolineas.front()->toString();
}//mostrarAerolinea

string ClaseGrande::mostrarItinerario() {
    return this->aerolineas.front()->mostrarItinerario();
}//mostrarItinerario

string ClaseGrande::mostrarItinerarios() {
    return this->aerolineas.front()->mostrarItinerarios();
}//mostrarItinerarios

void ClaseGrande::subirItinerario() {
    this->aerolineas.front()->subirItinerario();
}//subirItinerario

void ClaseGrande::arriba() {
    Aerolinea* aux = this->aerolineas.front();
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
}//arriba

void ClaseGrande::abajo() {
    Aerolinea* aux = this->aerolineas.back();
    this->aerolineas.pop_back();
    this->aerolineas.push_front(aux);
}//abajo

void ClaseGrande::registrarCliente(Client* client) {
    this->listaCliente.push_back(client);
}//registrarCliente

Client* ClaseGrande::searchClient(string passport, string password) {
    if (!this->listaCliente.empty()) {
         cout << "search Entro" << endl;
        for (int i = 0; i<this->listaCliente.size(); i++) {
            cout << "for Entro" << endl;
            if (this->listaCliente.at(i)->GetNumPassport() == passport && this->listaCliente.at(i)->GetPassword() == password) {
                 cout << this->listaCliente.at(i)->toString()<< endl;
                return this->listaCliente.at(i);
            }//if
        }//for
    }//if
    cout<<"NULL"<<endl;
    return NULL;
}//searchClient

void ClaseGrande::registrarCompra() {
    this->usuarioActual->SetTravel(this->aerolineas.front()->getItinerarios().front());
    Compra* compras = new Compra(this->usuarioActual);
    this->listaCompra.push_back(compras);
}//registrarCompra

void ClaseGrande::moverVertices() {

}//moverVertices

void ClaseGrande::mostrarVertices() {

}//mostrarVertice

void ClaseGrande::setAerolineas(list<Aerolinea*> aerolineas) {
    this->aerolineas = aerolineas;
}

list<Aerolinea*> ClaseGrande::getAerolineas() {
    return aerolineas;
}

ClaseGrande* ClaseGrande::instance = 0;