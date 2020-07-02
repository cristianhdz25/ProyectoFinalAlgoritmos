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
    this->aerolineas=new list<Aerolinea*>();
    this->aerolineas->push_back(new Aerolinea("VueltoPenzoil"));
    this->aerolineas->push_back(new Aerolinea("VueltoAchiote"));
    this->aerolineas->push_back(new Aerolinea("VueltoZorritone"));
    this->grafo = Grafo::getInstance();
   this->initItinerarios();
}//constructor

void AerolineaData::initItinerarios() {
    Aerolinea *aux = this->aerolineas->front();

    Pais* CR = new Pais("CR");
    Pais* MX = new Pais("MX");
    Pais* PR = new Pais("PR");
    Pais* PN = new Pais("PN");
    Pais* COL = new Pais("COL");
    Pais* USA = new Pais("USA");
    Pais* GUA = new Pais("GUA");
    Pais* URU = new Pais("URU");
    Pais* ITA = new Pais("ITA");
    Pais* POR = new Pais("POR");
    Pais* ECU = new Pais("ECU");
    Pais* NIC = new Pais("NIC");
    
    vector<Pais*> restriccion;
    restriccion.push_back(MX);
    restriccion.push_back(CR);
    USA->setRestricciones(restriccion);
    
    queue<Itinerario*> itinerarios1;
    itinerarios1.push(new Itinerario(CR, MX, "7am-10am", new Avion("Boeing 737", 80)));
    itinerarios1.push(new Itinerario(CR, PR, "10am-1pm", new Avion("Boeing 747", 50)));
    itinerarios1.push(new Itinerario(CR, PN, "3pm-6pm", new Avion("Boeing 787", 70)));
    itinerarios1.push(new Itinerario(CR, COL, "3pm-6pm", new Avion("Boeing 737", 80)));

    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(MX), 3);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(PR), 3);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(PN), 3);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(COL), 3);
    this->aerolineas->front()->setItinerarios(itinerarios1);
    this->aerolineas->pop_front();
    this->aerolineas->push_back(aux);

    aux = this->aerolineas->front();
    queue<Itinerario*> itinerarios2;
    itinerarios2.push(new Itinerario(PN, MX, "7am-10am", new Avion("Boeing 787", 90)));
    itinerarios2.push(new Itinerario(COL, PR, "10am-1pm", new Avion("Boeing 747", 70)));
    itinerarios2.push(new Itinerario(USA, PN, "3pm-6pm", new Avion("Boeing 747", 70)));
    itinerarios2.push(new Itinerario(GUA, COL, "3pm-6pm", new Avion("Boeing 737", 50)));

    this->grafo->agregarAristaYPeso(new Vertice(PN), new Vertice(MX), 3);
    this->grafo->agregarAristaYPeso(new Vertice(COL), new Vertice(PR), 3);
    this->grafo->agregarAristaYPeso(new Vertice(USA), new Vertice(PN), 3);
    this->grafo->agregarAristaYPeso(new Vertice(GUA), new Vertice(COL), 3);
    this->aerolineas->front()->setItinerarios(itinerarios2);
    this->aerolineas->pop_front();
    this->aerolineas->push_back(aux);

    aux = this->aerolineas->front();
    queue<Itinerario*> itinerarios3;
    itinerarios3.push(new Itinerario(CR, URU, "7am-10am", new Avion("Boeing 747", 60)));
    itinerarios3.push(new Itinerario(PR, ITA, "10am-1pm", new Avion("Boeing 737", 80)));
    itinerarios3.push(new Itinerario(CR, USA, "3pm-6pm", new Avion("Boeing 747", 70)));
    itinerarios3.push(new Itinerario(NIC, ECU, "3pm-6pm", new Avion("Boeing 787", 90)));
    
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(URU), 3);
    this->grafo->agregarAristaYPeso(new Vertice(PR), new Vertice(ITA), 3);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(POR), 3);
    this->grafo->agregarAristaYPeso(new Vertice(NIC), new Vertice(ECU), 3);
    this->aerolineas->front()->setItinerarios(itinerarios3);
    this->aerolineas->pop_front();
    this->aerolineas->push_back(aux);
}
    
void AerolineaData::registrarAerolinea(Aerolinea* aerolinea) {
    for (int i = 0; i < aerolinea->getItinerarios().size(); i++) {
        
        this->grafo->agregarAristaYPeso(new Vertice(aerolinea->getItinerario()->getOrigen()),
                new Vertice(aerolinea->getItinerario()->getDestino()), atoi(aerolinea->getItinerario()->getHora().c_str()));
    }//for i
    this->aerolineas->push_front(aerolinea);
}//registrarAerolinea

AerolineaData::~AerolineaData() {

}//destructor

AerolineaData* AerolineaData::getInstance() {
    if (instance == 0) {

        instance = new AerolineaData();

    }//if
    return instance;

}

void AerolineaData::setAerolineas(list<Aerolinea*>* aerolineas) {
    this->aerolineas = aerolineas;
}

list<Aerolinea*>* AerolineaData::getAerolineas() const {
    return aerolineas;
}

void AerolineaData::eliminarAerolinea(){
    this->aerolineas->pop_front();
}

AerolineaData* AerolineaData::instance = 0;