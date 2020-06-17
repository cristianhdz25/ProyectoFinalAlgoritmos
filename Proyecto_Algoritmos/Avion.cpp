/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Avion.cpp
 * Author: cristia
 * 
 * Created on 16 de junio de 2020, 09:10 PM
 */

#include "Avion.h"
#include <string> 
#include <iostream>
#include <iosfwd>
#include <sstream>

using namespace std;

Avion::Avion(string namePlane, int quantity) {
    this->namePlane = namePlane;
    this->quantity= quantity;
}

void Avion::setQuantity(int quantity) {
    this->quantity = quantity;
}

int Avion::getQuantity() const {
    return quantity;
}

void Avion::setNamePlane(string namePlane) {
    this->namePlane = namePlane;
}

string Avion::getNamePlane() const {
    return namePlane;
}



