/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Compra.h
 * Author: cristia
 *
 * Created on 22 de junio de 2020, 08:57 PM
 */

#ifndef COMPRA_H
#define COMPRA_H

#include "Client.h"
#include <string>
#include <sstream>
using namespace std;
class Compra {
public:
    Compra(Client* client/*,Itinerario* itinerario*/);
    void SetItinerario(Itinerario* itinerario);
    Itinerario* GetItinerario() const;
    void SetClient(Client* client);
    Client* GetClient() const;
    string toString();
private:
    Client* client;
    Itinerario* itinerario;    
};

#endif /* COMPRA_H */

