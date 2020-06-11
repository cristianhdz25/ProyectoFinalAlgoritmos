/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Validaciones.cpp
 * Author: cristia
 * 
 * Created on 11 de junio de 2020, 03:40 PM
 */

#include "Validaciones.h"
#include "string"

using namespace std;

Validaciones::Validaciones() {

}

bool Validaciones::COMPROBARNUMEROS(string stg) {
    for (int i = 0; i < stg.size(); i++) {
        if (!(stg.at(i) == '0' || stg.at(i) == '1' || stg.at(i) == '2' || stg.at(i) == '3'
                || stg.at(i) == '4' || stg.at(i) == '5' || stg.at(i) == '6' || stg.at(i) == '7'
                || stg.at(i) == '8' || stg.at(i) == '9')) {
            return false;
        } // if
    } // for
    return true;
}//comprobarnumeros

