/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AerolineaData.h
 * Author: fabricio
 *
 * Created on 15 de junio de 2020, 08:11 PM
 */

#ifndef AEROLINEADATA_H
#define AEROLINEADATA_H
#include <list>

#include "Aerolinea.h"
#include "Grafo.h"

class AerolineaData {
public:
    static AerolineaData* getInstance();
    virtual ~AerolineaData();
    
    void initItinerarios();
    void registrarAerolinea(Aerolinea* aerolinea);   
    void agregarItinerario(Itinerario* itinerario);
    void setAerolineas(list<Aerolinea*>* aerolineas);
    void eliminarAerolinea();
    list<Aerolinea*>* getAerolineas() const;
    bool existe(Aerolinea* aerolinea);
    void registrarItinerario(Itinerario* itinerario);
private:
    AerolineaData();
    Aerolinea* aerolinea;
    list<Aerolinea*>* aerolineas;
    Grafo * grafo;
    static AerolineaData* instance;
};

#endif /* AEROLINEADATA_H */

