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
#include "Avion.h"
#include "Pais.h"
#include <iostream>
#include <set>
using namespace std;

AerolineaData::AerolineaData() {
    this->aerolineas.push_back(new Aerolinea("VueltoPenzoil"));
    this->aerolineas.push_back(new Aerolinea("VueltoAchiote"));
    this->aerolineas.push_back(new Aerolinea("VueltoZorritone"));
    this->initItinerarios();
}//constructor

void AerolineaData::initItinerarios() {
    Aerolinea *aux = this->aerolineas.front();

    queue<Itinerario*> itinerarios1;
    itinerarios1.push(new Itinerario(new Pais("CR"), new Pais("MX"), "7am-10am", new Avion("Boeing 737", 80)));
    itinerarios1.push(new Itinerario(new Pais("CR"), new Pais("PR"), "10am-1pm", new Avion("Boeing 747", 50)));
    itinerarios1.push(new Itinerario(new Pais("CR"), new Pais("PN"), "3pm-6pm", new Avion("Boeing 787", 70)));
    itinerarios1.push(new Itinerario(new Pais("CR"), new Pais("COL"), "3pm-6pm", new Avion("Boeing 737", 80)));
    this->aerolineas.front()->setItinerarios(itinerarios1);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);

    aux = this->aerolineas.front();
    queue<Itinerario*> itinerarios2;
    itinerarios2.push(new Itinerario(new Pais("PN"), new Pais("MX"), "7am-10am", new Avion("Boeing 787", 90)));
    itinerarios2.push(new Itinerario(new Pais("COL"), new Pais("PR"), "10am-1pm", new Avion("Boeing 747", 70)));
    itinerarios2.push(new Itinerario(new Pais("USA"), new Pais("PN"), "3pm-6pm", new Avion("Boeing 747", 70)));
    itinerarios2.push(new Itinerario(new Pais("GUA"), new Pais("COL"), "3pm-6pm", new Avion("Boeing 737", 50)));
    this->aerolineas.front()->setItinerarios(itinerarios2);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);

    aux = this->aerolineas.front();
    queue<Itinerario*> itinerarios3;
    itinerarios3.push(new Itinerario(new Pais("CR"), new Pais("URU"), "7am-10am", new Avion("Boeing 747", 60)));
    itinerarios3.push(new Itinerario(new Pais("PR"), new Pais("ITA"), "10am-1pm", new Avion("Boeing 737", 80)));
    itinerarios3.push(new Itinerario(new Pais("CR"), new Pais("POR"), "3pm-6pm", new Avion("Boeing 747", 70)));
    itinerarios3.push(new Itinerario(new Pais("NIC"), new Pais("ECU"), "3pm-6pm", new Avion("Boeing 787", 90)));
    this->aerolineas.front()->setItinerarios(itinerarios3);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
}

void AerolineaData::registrarAerolinea(Aerolinea* aerolinea) {
    this->aerolineas.push_front(aerolinea);
}//registrarAerolinea

AerolineaData::~AerolineaData() {

}//destructor

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


AerolineaData* AerolineaData::instance = 0;