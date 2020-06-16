/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AerolineaData.cpp
 * Author: fabricio
 * 
 * Created on 15 de junio de 2020, 08:11 PM
 */

#include "AerolineaData.h"

AerolineaData::AerolineaData() {
}

AerolineaData::~AerolineaData() {
}

void AerolineaData::setAerolineas(vector<Aerolinea*> aerolineas) {
    this->aerolineas = aerolineas;
}

vector<Aerolinea*> AerolineaData::getAerolineas() const {
    return aerolineas;
}

