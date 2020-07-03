#include "RestriccionData.h"

RestriccionData::RestriccionData() {

}//constructor

void RestriccionData::registrarRestricciones(Pais* pais) {

    this->registroRestricciones.push_back(pais);
}//registrar

int RestriccionData::existePais(string nombre) {
    for (int i = 0; i<this->registroRestricciones.size(); i++) {
        if (nombre == this->registroRestricciones.at(i)->getNombre()) {
            return i;
        }//if
    }//for
    return -1;
}//existePais

void RestriccionData::anadirRestriccion(Pais* pais, int i) {
    this->registroRestricciones.at(i)->getRestricciones()->push_back(pais);
    cout <<"ANADIR"<< this->registroRestricciones.at(i)->getRestricciones()->size()<<endl;
}//anadirRestriccion

void RestriccionData::setRegistroRestricciones(vector<Pais*> registroRestricciones) {
    this->registroRestricciones = registroRestricciones;
}//setRegistroRestricciones

vector<Pais*> RestriccionData::getRegistroRestricciones() const {
    return registroRestricciones;
}//registrarRestrcciones

RestriccionData* RestriccionData::getInstance() {
    if (instance == 0) {
        instance = new RestriccionData();
    }//if
    return instance;
}//getInstance

RestriccionData* RestriccionData::instance = 0;