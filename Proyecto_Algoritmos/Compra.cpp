/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Compra.cpp
 * Author: cristia
 * 
 * Created on 22 de junio de 2020, 08:57 PM
 */

#include "Compra.h"

#include "Compra.h"

Compra::Compra(Client* client/*, Itinerario* itinerario*/) {
    this->client=client;
    this->itinerario=itinerario;
}

void Compra::SetItinerario(Itinerario* itinerario) {
this->itinerario = itinerario;
}

Itinerario* Compra::GetItinerario() const {
return itinerario;
}

void Compra::SetClient(Client* client) {
this->client = client;
}

Client* Compra::GetClient() const {
return client;
}//compra

string Compra::toString() {

    stringstream s;
   
    s<<this->client->toString()<<","<<this->itinerario->toString();
    
    return s.str();
}//toString

