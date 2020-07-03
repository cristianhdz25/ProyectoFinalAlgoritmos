#include "AerolineaData.h"
#include "Avion.h"
#include "Pais.h"
#include <iostream>
#include <set>
#include <vector>
#include "RestriccionData.h"
#include "Itinerario.h"
using namespace std;

AerolineaData::AerolineaData() {
    this->aerolineas = new list<Aerolinea*>();
    this->aerolineas->push_back(new Aerolinea("VueltoPenzoil"));
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

    queue<Itinerario*> itinerarios1;
    itinerarios1.push(new Itinerario(CR, MX, 7, 10, new Avion("Boeing 737", 80)));
    itinerarios1.push(new Itinerario(CR, PR, 10, 13, new Avion("Boeing 747", 50)));
    itinerarios1.push(new Itinerario(CR, PN, 3, 6, new Avion("Boeing 787", 70)));
    itinerarios1.push(new Itinerario(CR, COL, 15, 22, new Avion("Boeing 737", 80)));

    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(MX), 7, 10, 80);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(PR), 10, 13, 50);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(PN), 3, 6, 70);
    this->grafo->agregarAristaYPeso(new Vertice(CR), new Vertice(COL), 15, 22, 80);
    this->aerolineas->front()->setItinerarios(itinerarios1);
    this->aerolineas->pop_front();
    this->aerolineas->push_back(aux);

    aux = this->aerolineas->front();
    queue<Itinerario*> itinerarios2;
    itinerarios2.push(new Itinerario(PN, MX, 7, 10, new Avion("Boeing 787", 90)));
    itinerarios2.push(new Itinerario(COL, PR, 10, 15, new Avion("Boeing 747", 70)));
    itinerarios2.push(new Itinerario(USA, PN, 3, 6, new Avion("Boeing 747", 70)));
    itinerarios2.push(new Itinerario(GUA, COL, 3, 6, new Avion("Boeing 737", 50)));

    this->grafo->agregarAristaYPeso(new Vertice(PN), new Vertice(MX), 7, 10, 90);
    this->grafo->agregarAristaYPeso(new Vertice(COL), new Vertice(PR), 10, 15, 70);
    this->grafo->agregarAristaYPeso(new Vertice(USA), new Vertice(PN), 3, 6, 70);
    this->grafo->agregarAristaYPeso(new Vertice(GUA), new Vertice(COL), 3, 6, 50);
    this->aerolineas->front()->setItinerarios(itinerarios2);
    this->aerolineas->pop_front();
    this->aerolineas->push_back(aux);
}//initItinerarios

void AerolineaData::registrarAerolinea(Aerolinea* aerolinea) {
    this->aerolineas->push_front(aerolinea);
    for (int i = 0; i < aerolinea->getItinerarios().size(); i++) {

        this->grafo->agregarAristaYPeso(new Vertice(aerolinea->getItinerario()->getOrigen()),
                new Vertice(aerolinea->getItinerario()->getDestino()), aerolinea->getItinerario()->getHoraSalida(),
                aerolinea->getItinerario()->getHoraLlegada(),
                aerolinea->getItinerario()->getHoraLlegada() - aerolinea->getItinerario()->getHoraSalida());
        aerolinea->subirItinerario();
    }//for i

}//registrarAerolinea

AerolineaData::~AerolineaData() {

}//destructor

bool AerolineaData::existe(Aerolinea* aerolinea) {

    list<Aerolinea*>* aerolineaTemp = new list<Aerolinea*>();
    aerolineaTemp = aerolineas;

    for (int i = 0; i < aerolineaTemp->size(); i++) {
        if (aerolineaTemp->front()->getNombre() == aerolinea->getNombre()) {
            return true;
        }//if
        Aerolinea * aux = this->aerolineas->front();
        aerolineaTemp->pop_front();
        aerolineaTemp->push_back(aux);
    }//for

    return false;


}//exist

AerolineaData* AerolineaData::getInstance() {
    if (instance == 0) {

        instance = new AerolineaData();

    }//if
    return instance;

}

void AerolineaData::registrarItinerario(Itinerario* itinerario) {
    this->grafo->agregarAristaYPeso(new Vertice(itinerario->getOrigen()),
            new Vertice(itinerario->getDestino()), itinerario->getHoraSalida(),
            itinerario->getHoraLlegada(),
            itinerario->getHoraLlegada() - itinerario->getHoraSalida());

}

void AerolineaData::setAerolineas(list<Aerolinea*>* aerolineas) {
    this->aerolineas = aerolineas;
}

list<Aerolinea*>* AerolineaData::getAerolineas() const {
    return aerolineas;
}

void AerolineaData::eliminarAerolinea() {
    this->aerolineas->pop_front();
}

AerolineaData* AerolineaData::instance = 0;