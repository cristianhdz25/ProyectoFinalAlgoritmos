#include "Itinerario.h"
#include "iostream"
#include <string>
#include "string.h"
#include<sstream>

using namespace std;

Itinerario::Itinerario(string origen, string destino, string hora) {
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

void Itinerario::setDestino(string destino) {
    this->destino = destino;
}

string Itinerario::getDestino() const {
    return destino;
}

void Itinerario::setOrigen(string origen) {
    this->origen = origen;
}

string Itinerario::getOrigen() const {
    return origen;
}

string Itinerario::toString() {
    stringstream s;

    s << this->origen << "-" << this->destino <<" -> " << this->hora;
    return s.str();
}//toString
