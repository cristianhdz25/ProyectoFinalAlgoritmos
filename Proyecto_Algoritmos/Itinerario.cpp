#include "Itinerario.h"
#include "iostream"
#include <string>
#include "string.h"
#include <sstream>

using namespace std;

Itinerario::Itinerario(Pais* origen, Pais* destino, string hora, Avion * avion) {
    this->avion = avion;
    this->origen = origen;
    this->destino = destino;    
    this->hora = hora;
}//constructor

Itinerario::~Itinerario() {

}

void Itinerario::setHora(string hora) {
    this->hora = hora;
}

string Itinerario::getHora() const {
    return hora;
}

void Itinerario::setDestino(Pais* destino) {
    this->destino = destino;
}

Pais* Itinerario::getDestino() const {
    return destino;
}

void Itinerario::setOrigen(Pais* origen) {
    this->origen = origen;
}

Pais* Itinerario::getOrigen() const {
    return origen;
}

void Itinerario::setAvion(Avion* avion) {
    this->avion = avion;
}

Avion* Itinerario::getAvion() const {
    return avion;
}//toString

string Itinerario::toString() {
    stringstream s;

    s << this->origen->toString() << "-" << this->destino->toString() <<" -> " << this->hora << "|" << this->avion->toString();
    return s.str();
}
string Itinerario::toString2() {
    stringstream s;

    s << this->origen->toString() << "-" << this->destino->toString() <<" -> " << this->hora;
    return s.str();
}

