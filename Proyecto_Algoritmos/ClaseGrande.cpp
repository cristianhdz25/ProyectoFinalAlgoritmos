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
    this->listaCliente = new vector<Client*>();
    this->listaCompra = new vector<Compra*>();
    
    this->restriccionData = RestriccionData::getInstance();
    this->grafo = Grafo::getInstance();
   
}//constructor

ClaseGrande* ClaseGrande::getInstance() {
    if (instance == 0) {
        //if
        instance = new ClaseGrande();

    }//if
    return instance;

}//getInstance

ClaseGrande::~ClaseGrande() {
}

void ClaseGrande::usuarioReset() {
    this->usuarioActual==NULL;
}//UsuarioReset

//Método para registrar una aerolinea

void ClaseGrande::registrarAerolinea(Aerolinea* aerolinea) {
    this->aerolineaBusiness->registrarAerolinea(aerolinea);
    this->aerolineas = this->aerolineaBusiness->getAerolineas();

}//registrarAerolinea

void ClaseGrande::agregarItinerarioActualizado(Itinerario* itinerario) {
    this->aerolineaBusiness->registrarItinerario(itinerario);
}

bool ClaseGrande::existe(Aerolinea* aerolinea) {
    this->aerolineaBusiness->existe(aerolinea);
}

//método para registrar un itinerario

string ClaseGrande::mostrarAerolinea() {
    return this->aerolineas->front()->toString();
}//mostrarAerolinea

string ClaseGrande::mostrarItinerario() {
    return this->aerolineas->front()->mostrarItinerario();
}//mostrarItinerario

string ClaseGrande::mostrarItinerarios() {
    return this->aerolineas->front()->mostrarItinerarios();
}//mostrarItinerarios

void ClaseGrande::subirItinerario() {
    this->aerolineas->front()->subirItinerario();
}//subirItinerario

void ClaseGrande::arriba() {
    Aerolinea* aux = this->aerolineas->front();
    this->aerolineas->pop_front();
    this->aerolineas->push_back(aux);
}//arriba

void ClaseGrande::abajo() {
    Aerolinea* aux = this->aerolineas->back();
    this->aerolineas->pop_back();
    this->aerolineas->push_front(aux);
}//abajo

void ClaseGrande::registrarCliente(Client* client) {
    this->listaCliente->push_back(client);

    this->usuarioActual = client;
    this->listaCliente->push_back(usuarioActual);
}//registrarCliente

void ClaseGrande::agregarItinerario(Itinerario* itinerario) {
    this->aerolineas->front()->agregarItinerarioNuevo(itinerario);
}


Client* ClaseGrande::searchClient(string passport, string password) {
    if (!this->listaCliente->empty()) {
        for (int i = 0; i<this->listaCliente->size(); i++) {
            if (this->listaCliente->at(i)->GetNumPassport() == passport && this->listaCliente->at(i)->GetPassword() == password) {
                return this->listaCliente->at(i);
            }//if
        }//for
    }//if
    return NULL;
}//for

void ClaseGrande::registrarCompra() {
    this->usuarioActual->SetTravel(this->aerolineas->front()->getItinerarios().front());
    Compra* compras = new Compra(this->usuarioActual);
    this->aerolineas->front()->getItinerarios().front()->getAvion()->setQuantity(this->aerolineas->front()->getItinerarios().front()->getAvion()->getQuantity() - 1);
    this->listaCompra->push_back(compras);
}//registrarCompra

void ClaseGrande::moverVertices() {

}//moverVertices

void ClaseGrande::mostrarVertices() {

}//mostrarVertice

void ClaseGrande::setAerolineas(list<Aerolinea*>* aerolineas) {
    this->aerolineas = aerolineas;
}

list<Aerolinea*>* ClaseGrande::getAerolineas() {
    return aerolineas;
}

bool ClaseGrande::comprobarRestriccionDelQueCompraElTiquete() {

    for (int i = 0; i<this->restriccionData->getRegistroRestricciones().size(); i++) {
        for (int j = 0; j <this->restriccionData->getRegistroRestricciones().at(i)->getRestricciones()->size(); j++) {
            if (this->restriccionData->getRegistroRestricciones().at(i)->getRestricciones()->at(j)->getNombre() ==
                    this->usuarioActual->GetNationality()->getNombre()) {

                cout << "true" << endl;
                return true;
            }//if

        }//for

    }//for
    cout << "false" << endl;
    return false;

}//comprobarRestriccion

void ClaseGrande::asignarItinerario(){
    this->usuarioActual->SetTravel(this->aerolineas->front()->getItinerarios().front());
}

Client* ClaseGrande::getUsuarioActual() const{
    return usuarioActual;
}

ClaseGrande* ClaseGrande::instance = 0;
