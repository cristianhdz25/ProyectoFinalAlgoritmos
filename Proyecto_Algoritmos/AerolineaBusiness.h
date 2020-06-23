/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AerolineaBusiness.h
 * Author: fabricio
 *
 * Created on 16 de junio de 2020, 12:22 PM
 */

#ifndef AEROLINEABUSINESS_H
#define AEROLINEABUSINESS_H

#include "AerolineaData.h"


class AerolineaBusiness {
public:
    AerolineaBusiness();
    virtual ~AerolineaBusiness();
    
    void registrarAerolinea(Aerolinea* aerolinea); 
    
    list<Aerolinea*>* getAerolineas() const;
    
private:
    AerolineaData* aerolineaData;
};

#endif /* AEROLINEABUSINESS_H */

