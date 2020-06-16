/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioAdministradorData.cpp
 * Author: fabricio
 * 
 * Created on 16 de junio de 2020, 11:31 AM
 */

#include "UsuarioAdministradorData.h"

UsuarioAdministradorData::UsuarioAdministradorData() {
    this->cuentaAdministrador=new UsuarioAdministrador("admin","admin");
}//constructor

UsuarioAdministradorData::~UsuarioAdministradorData() {
}

bool UsuarioAdministradorData::iniciarSesionAdministrador(UsuarioAdministrador* usuarioAdministrador){
    if(this->cuentaAdministrador->getUserId()==usuarioAdministrador->getUserId()
            && this->cuentaAdministrador->getPassword()==usuarioAdministrador->getPassword())
        return true;
    return false;
}//iniciarSesionAdministrador

