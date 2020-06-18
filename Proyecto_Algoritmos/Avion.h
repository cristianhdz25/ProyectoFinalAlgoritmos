/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Avion.h
 * Author: cristia
 *
 * Created on 16 de junio de 2020, 09:10 PM
 */

#ifndef AVION_H
#define AVION_H
#include <string> 
#include <iostream>
#include <iosfwd>
#include <sstream>

using namespace std;

class Avion {
public:
    Avion(string namePlane, int quantity);
    void setQuantity(int quantity);
    int getQuantity() const;
    void setNamePlane(string namePlane);
    string getNamePlane() const;  
    string toString();
private:
    string namePlane;
    int quantity;
};

#endif /* AVION_H */

