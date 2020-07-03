#include "Pais.h"
#include <string> 
#include <iostream>
#include <iosfwd>
#include <sstream>
#include <vector>

Pais::Pais(string nombre) {
    this->nombre = nombre;
    this->restricciones=new vector<Pais*>();
}

void Pais::setRestricciones(vector<Pais*>* restricciones) {
    this->restricciones = restricciones;
}

vector<Pais*>* Pais::getRestricciones() const{
    return restricciones;
}

void Pais::setNombre(string nombre) {
    this->nombre = nombre;
}

string Pais::getNombre() const {
    return nombre;
}

string Pais::toString() {
    stringstream s;

    s << this->nombre;
    return s.str();
}
