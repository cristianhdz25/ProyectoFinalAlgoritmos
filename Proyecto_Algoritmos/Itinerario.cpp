#include "Itinerario.h"
#include "iostream"
#include <string>
#include "string.h"
#include <sstream>

using namespace std;

Itinerario::Itinerario(Pais* origen, Pais* destino, int horaSalida, int horaLlegada, Avion * avion) {
    this->avion = avion;
    this->origen = origen;
    this->destino = destino;
    this->horaSalida = horaSalida;
    this->horaLlegada = horaLlegada;
}//constructor

Itinerario::~Itinerario() {

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
}

void Itinerario::setHoraSalida(int horaSalida) {
    this->horaLlegada = horaSalida;
}

int Itinerario::getHoraSalida() const {
    return horaSalida;
}

void Itinerario::setHoraLlegada(int horaLlegada) {
    this->horaLlegada = horaLlegada;
}

int Itinerario::getHoraLlegada() const {
    return horaLlegada;
}

string Itinerario::toString() {
    stringstream s;

    s << this->origen->toString() << "-" << this->destino->toString() << " -> " <<this->horaSalida<<" a "<< this->horaLlegada << "-" << this->avion->toString();
    return s.str();
}

string Itinerario::toString2() {
    stringstream s;
    s << this->origen->toString() << "-" << this->destino->toString() << " -> " << this->horaSalida<<" a "<<this->horaLlegada;
    return s.str();
}

