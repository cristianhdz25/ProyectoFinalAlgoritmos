/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pais.h
 * Author: cristia
 *
 * Created on 16 de junio de 2020, 10:50 PM
 */

#ifndef PAIS_H
#define PAIS_H
#include <string> 
#include <iostream>
#include <iosfwd>
#include <sstream>
#include <vector>

using namespace std;

class Pais {
public:
    Pais(string nombre);
    void setRestricciones(vector<Pais*>* restricciones);
    vector<Pais*>* getRestricciones() const;
    void setNombre(string nombre);
    string getNombre() const;
    string toString();

private:
    string nombre;
    vector<Pais*>* restricciones;
};

#endif /* PAIS_H */

