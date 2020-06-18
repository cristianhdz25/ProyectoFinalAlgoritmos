/* * To change this template file, choose Tools | Templates

 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.cpp
 * Author: carlos
 * 
 * Created on 16 de junio de 2020, 05:16 PM
 */

#include "Grafo.h"

Grafo::Grafo() {
}

int Grafo::getPosicion(Vertice* vertice) {
    for (int i = 0; i < this->grafo.size(); i++) {
        if (vertice->pais->getNombre() == this->grafo.at(i)->pais->getNombre())
            return i;
    }//for i
    return -1;
}//getPosicion

bool Grafo::existeArista(Vertice* vertice1, Vertice* vertice2){
    for (int i = 0; i < vertice1->listaAristas.size(); i++) {
        if (vertice1->listaAristas.at(i)->pais->getNombre()==vertice2->pais->getNombre()) {
            return true;
        }


    }
    return false;
}

bool Grafo::exist(Vertice* vertice) {
    if (this->grafo.empty()) {
        cout << "no existen vertices" << endl;

    }//if
    for (int i = 0; i < this->grafo.size(); i++) {
        if (this->grafo.at(i)->pais->getNombre() == vertice->pais->getNombre()) {

            return true;

        }//if
    }//for

    return false;

}//exist

void Grafo::agragarAristaYPeso(Vertice* vertice1, Vertice* vertice2, int peso) {
    if (!this->exist(vertice1) && !this->exist(vertice2)) {
        vertice1->listaAristas.push_back(vertice2);
        vertice1->listaPesos.push_back(peso);
        this->grafo.push_back(vertice1);
        this->grafo.push_back(vertice2);

    } else if (this->exist(vertice1) && this->exist(vertice2) 
            && !this->existeArista(this->grafo.at(this->getPosicion(vertice1)), vertice2)) {
        this->grafo.at(this->getPosicion(vertice1))->listaAristas.push_back(vertice2);
        this->grafo.at(this->getPosicion(vertice1))->listaPesos.push_back(peso);

    } else if (!this->exist(vertice1) && this->exist(vertice2)) {
        vertice1->listaAristas.push_back(this->grafo.at(this->getPosicion(vertice2))); //this.get
        vertice1->listaPesos.push_back(peso);
        this->grafo.push_back(vertice1);

    } else if (this->exist(vertice1) && !this->exist(vertice2)) {
        this->grafo.at(this->getPosicion(vertice1))->listaAristas.push_back(vertice2);
        this->grafo.at(this->getPosicion(vertice1))->listaPesos.push_back(peso);
        this->grafo.push_back(vertice2);

    }

}//agragarAristaYPeso

string Grafo::toString() {
    stringstream s;
    for (int i = 0; i < this->grafo.size(); i++) {
        s << this->grafo.at(i)->pais->getNombre() << " :" << endl;
        for (int j = 0; j < this->grafo.at(i)->listaAristas.size(); j++) {
            s << this->grafo.at(i)->listaAristas.at(j)->pais->getNombre() << endl;

        }

    }


    return s.str();

}