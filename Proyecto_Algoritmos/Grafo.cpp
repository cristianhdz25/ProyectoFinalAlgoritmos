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
    

int Grafo::getPosicion(Vertice* vertice){
    return 0;
}

void Grafo::agragarAristaYPeso(Vertice* vertice1, Vertice* vertice2, int peso){
    vertice1->listaAristas.push_back(vertice2);
    vertice1->listaPesos.push_back(peso);
    this->grafo.push_back(vertice1);
}

string Grafo::toString(){
    stringstream s;
    for (int i = 0; i < this->grafo.size(); i++) {
        s<<this->grafo.at(i)->pais->getNombre()<<" -> ";
        for (int j = 0; j < this->grafo.at(i)->listaAristas.size(); j++) {
            s<<this->grafo.at(i)->listaAristas.at(j)->pais->getNombre()<<endl;

        }

    }

    
    return s.str();
    
}