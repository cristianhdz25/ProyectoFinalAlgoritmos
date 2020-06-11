#include "Aerolinea.h"
#include <string> 
#include <iostream>
#include <iosfwd>
#include <sstream>
using namespace std;
Aerolinea::Aerolinea(string nombre) {
    this->nombre = nombre;   
}//constructor

void Aerolinea::subirItinerario(){
    Itinerario* aux=this->itinerarios.front();
    this->itinerarios.pop();
    this->itinerarios.push(aux);
}

string Aerolinea::mostrarItinerario() {
    if(!this->itinerarios.empty())
        return this->itinerarios.front()->toString();
    else
        return "No hay";
}

string Aerolinea::mostrarItinerarios() {
    if(this->itinerarios.empty())
        return "No hay";
    queue<Itinerario*> aux=this->itinerarios;
    stringstream s;
    for (int i = 0; i < this->itinerarios.size(); i++) {
        s<<aux.front()->toString()<<endl;
        aux.pop();
    }//for i
    return s.str();
}//mostrarItinerarios


Aerolinea::~Aerolinea() {
}

void Aerolinea::setItinerarios(queue<Itinerario*> itinerarios) {
    this->itinerarios = itinerarios;
}

queue<Itinerario*> Aerolinea::getItinerarios() {
    return itinerarios;
}

void Aerolinea::setNombre(string nombre) {
    this->nombre = nombre;
}

string Aerolinea::getNombre() const {
    return nombre;
}

string Aerolinea::toString(){
    return this->nombre;
}
