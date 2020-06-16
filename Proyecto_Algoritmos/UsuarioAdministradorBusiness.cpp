/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioAdministradorBusiness.cpp
 * Author: fabricio
 * 
 * Created on 16 de junio de 2020, 11:38 AM
 */

#include "UsuarioAdministradorBusiness.h"

UsuarioAdministradorBusiness::UsuarioAdministradorBusiness() {
}

UsuarioAdministradorBusiness::~UsuarioAdministradorBusiness() {
}

bool UsuarioAdministradorBusiness::iniciarSesionAdministrador(UsuarioAdministrador* usuarioAdministrador){
    return this->usuarioAdministradorData.iniciarSesionAdministrador(usuarioAdministrador);
}

