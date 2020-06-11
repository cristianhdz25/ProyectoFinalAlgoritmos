/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.h
 * Author: fabricio
 *
 * Created on 5 de junio de 2020, 10:26 PM
 */

#ifndef ITINERARIO_H
#define ITINERARIO_H
#include <string>

using namespace std;

class Itinerario {
public:
    Itinerario(string ruta, string hora);
    virtual ~Itinerario();
    void setHora(string hora);
    string getHora() const;
    void setRuta(string ruta);
    string getRuta() const;
    string toString();
private:
    string ruta;
    string hora;
};

#endif /* ITINERARIO_H */

