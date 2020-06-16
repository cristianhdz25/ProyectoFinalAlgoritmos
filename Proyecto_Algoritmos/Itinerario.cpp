#include "Itinerario.h"
#include "iostream"
#include <string>
#include "string.h"
#include<sstream>

using namespace std;

Itinerario::Itinerario(string ruta, string hora) {
    this->ruta = ruta;
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

void Itinerario::setRuta(string ruta) {
    this->ruta = ruta;
}

string Itinerario::getRuta() const {
    return ruta;
}

string Itinerario::toString() {
    stringstream s;

    s <<this->ruta<<" -> " << this->hora;
    return s.str();
}//toString
