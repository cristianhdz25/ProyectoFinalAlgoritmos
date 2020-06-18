/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.h
 * Author: carlos
 *
 * Created on 16 de junio de 2020, 05:16 PM
 */

#ifndef GRAFO_H
#define GRAFO_H

#include "Vertice.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Grafo {
public:
    Grafo();
    vector<Vertice*> grafo;
    
    int getPosicion(Vertice* vertice);
    void agragarAristaYPeso(Vertice* vertice1, Vertice* vertice2, int peso);
    bool existeArista(Vertice* vertice1, Vertice* vertice2);
    bool exist(Vertice* vertice);
    
    string toString();
    
private:

};

#endif /* GRAFO_H */

