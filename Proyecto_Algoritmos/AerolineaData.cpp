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
#include <iostream>
using namespace std;

AerolineaData::AerolineaData() {
    this->aerolineas.push_back(new Aerolinea("Aerolinea VueltoPenzoil"));
    this->aerolineas.push_back(new Aerolinea("Aerolinea VueltoAchiote"));
    this->aerolineas.push_back(new Aerolinea("Aerolinea VueltoZorritone"));
    this->initItinerarios();
}

void AerolineaData::initItinerarios(){
    Aerolinea *aux= this->aerolineas.front();
    queue<Itinerario*> itinerarios1;
    itinerarios1.push(new Itinerario("CR","MX", "7am-10am"));
    itinerarios1.push(new Itinerario("CR","PT", "10am-1pm"));
    itinerarios1.push(new Itinerario("CR","CHI", "3pm-6pm"));
    itinerarios1.push(new Itinerario("CR","PN", "3pm-6pm"));
    this->aerolineas.front()->setItinerarios(itinerarios1);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
    
    aux= this->aerolineas.front();
    queue<Itinerario*> itinerarios2;
    itinerarios2.push(new Itinerario("CR","MX", "7am-10am"));
    itinerarios2.push(new Itinerario("CR","EU", "10am-1pm"));
    itinerarios2.push(new Itinerario("CR","ARG", "3pm-6pm"));
    itinerarios2.push(new Itinerario("CR","PN", "3pm-6pm"));
    this->aerolineas.front()->setItinerarios(itinerarios2);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
    
    aux= this->aerolineas.front();
    queue<Itinerario*> itinerarios3;
    itinerarios3.push(new Itinerario("CR","MX", "7am-10am"));
    itinerarios3.push(new Itinerario("CR","NIC", "10am-1pm"));
    itinerarios3.push(new Itinerario("CR","USA", "3pm-6pm"));
    itinerarios3.push(new Itinerario("CR","POR", "3pm-6pm"));
    this->aerolineas.front()->setItinerarios(itinerarios3);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
}


void AerolineaData::registrarAerolinea(Aerolinea* aerolinea){
    this->aerolineas.push_back(aerolinea);
}//registrarAerolinea

AerolineaData::~AerolineaData(){
    
}

AerolineaData* AerolineaData::getInstance() {
    if (instance == 0) {

        instance = new AerolineaData();

    }//if
    return instance;

}

void AerolineaData::setAerolineas(list<Aerolinea*> aerolineas) {
    this->aerolineas = aerolineas;
}

list<Aerolinea*> AerolineaData::getAerolineas() const {
    return aerolineas;
}


AerolineaData* AerolineaData::instance=0;