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
#include <vector>
#include <bits/stl_vector.h>

#include "Aerolinea.h"

class AerolineaData {
public:
    AerolineaData();
    virtual ~AerolineaData();
    void setAerolineas(vector<Aerolinea*> aerolineas);
    vector<Aerolinea*> getAerolineas() const;
private:
    
    vector<Aerolinea*> aerolineas;
};

#endif /* AEROLINEADATA_H */

