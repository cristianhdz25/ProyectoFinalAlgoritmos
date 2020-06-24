/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AerolineaBusiness.cpp
 * Author: fabricio
 * 
 * Created on 16 de junio de 2020, 12:22 PM
 */

#include "AerolineaBusiness.h"

AerolineaBusiness::AerolineaBusiness() {
    this->aerolineaData=AerolineaData::getInstance();
}

AerolineaBusiness::~AerolineaBusiness() {
}

void AerolineaBusiness::registrarAerolinea(Aerolinea* aerolinea){
    this->aerolineaData->registrarAerolinea(aerolinea);
}//registrarAerolinea

list<Aerolinea*> AerolineaBusiness::getAerolineas() const{
    return this->aerolineaData->getAerolineas();
}
