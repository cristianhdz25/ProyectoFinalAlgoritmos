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

class AerolineaData {
public:
    
    virtual ~AerolineaData();
    
    static AerolineaData* getInstance();
    void initItinerarios();
    void setAerolineas(list<Aerolinea*> aerolineas);
    list<Aerolinea*> getAerolineas() const;
    
private:
    AerolineaData();
    list<Aerolinea*> aerolineas;
    static AerolineaData* instance;
};

#endif /* AEROLINEADATA_H */

