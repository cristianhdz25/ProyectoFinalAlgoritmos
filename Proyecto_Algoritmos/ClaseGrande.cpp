#include "ClaseGrande.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

ClaseGrande::ClaseGrande() {
    this->aerolineas.push_back(new Aerolinea("Aerolinea VueltoPenzoil"));
    this->aerolineas.push_back(new Aerolinea("Aerolinea VueltoAchiote"));
    this->aerolineas.push_back(new Aerolinea("Aerolinea VueltoZorritone"));
    this->initItinerarios();
}//constructor

ClaseGrande* ClaseGrande::getInstance() {
    if (instance == 0) {

        instance = new ClaseGrande();

    }//if
    return instance;

}

ClaseGrande::~ClaseGrande() {
}

void ClaseGrande::initItinerarios(){
    Aerolinea *aux= this->aerolineas.front();
    queue<Itinerario*> itinerarios1;
    itinerarios1.push(new Itinerario("CR-MX", "7am-10am"));
    itinerarios1.push(new Itinerario("CR-PT", "10am-1pm"));
    itinerarios1.push(new Itinerario("CR-CHI", "3pm-6pm"));
    itinerarios1.push(new Itinerario("CR-PN", "3pm-6pm"));
    this->aerolineas.front()->setItinerarios(itinerarios1);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
    
    aux= this->aerolineas.front();
    queue<Itinerario*> itinerarios2;
    itinerarios2.push(new Itinerario("CR-MX", "7am-10am"));
    itinerarios2.push(new Itinerario("CR-EU", "10am-1pm"));
    itinerarios2.push(new Itinerario("CR-ARG", "3pm-6pm"));
    itinerarios2.push(new Itinerario("CR-PN", "3pm-6pm"));
    this->aerolineas.front()->setItinerarios(itinerarios2);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
    
    aux= this->aerolineas.front();
    queue<Itinerario*> itinerarios3;
    itinerarios3.push(new Itinerario("CR-MX", "7am-10am"));
    itinerarios3.push(new Itinerario("CR-NIC", "10am-1pm"));
    itinerarios3.push(new Itinerario("CR-USA", "3pm-6pm"));
    itinerarios3.push(new Itinerario("CR-POR", "3pm-6pm"));
    this->aerolineas.front()->setItinerarios(itinerarios3);
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
}

string ClaseGrande::mostrarAerolinea() {
    return this->aerolineas.front()->toString();
}//mostrarAerolinea

string ClaseGrande::mostrarItinerario(){
    return this->aerolineas.front()->mostrarItinerario();
}//mostrarItinerario

string ClaseGrande::mostrarItinerarios(){
    return this->aerolineas.front()->mostrarItinerarios();
}//mostrarItinerarios

void ClaseGrande::subirItinerario(){
    this->aerolineas.front()->subirItinerario();
}//subirItinerario

void ClaseGrande::arriba() {
    Aerolinea* aux = this->aerolineas.front();
    this->aerolineas.pop_front();
    this->aerolineas.push_back(aux);
}//arriba

void ClaseGrande::abajo() {
    Aerolinea* aux = this->aerolineas.back();
    this->aerolineas.pop_back();
    this->aerolineas.push_front(aux);
}//abajo



void ClaseGrande::setAerolineas(list<Aerolinea*> aerolineas) {
    this->aerolineas = aerolineas;
}

list<Aerolinea*> ClaseGrande::getAerolineas() const {
    return aerolineas;
}

ClaseGrande* ClaseGrande::instance=0;