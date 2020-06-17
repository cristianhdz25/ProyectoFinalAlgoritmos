/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertice.h
 * Author: carlos
 *
 * Created on 16 de junio de 2020, 05:16 PM
 */

#ifndef VERTICE_H
#define VERTICE_H

#include <vector>

#include "Pais.h"

class Vertice {
public:
    Vertice(Pais* pais);
    Pais* pais;
    vector<Vertice*> listaAristas;
    vector<int> listaPesos;
private:

};

#endif /* VERTICE_H */

