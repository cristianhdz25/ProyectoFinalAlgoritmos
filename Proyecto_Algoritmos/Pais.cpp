/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pais.cpp
 * Author: cristia
 * 
 * Created on 16 de junio de 2020, 10:50 PM
 */

#include "Pais.h"
#include <string> 
#include <iostream>
#include <iosfwd>
#include <sstream>

Pais::Pais(string nombre) {
    this->nombre = nombre;
    this->restricciones = new vector<string>();
}

void Pais::setRestricciones(vector<string>* restricciones) {
    this->restricciones = restricciones;
}

vector<string>* Pais::getRestricciones() const{
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
