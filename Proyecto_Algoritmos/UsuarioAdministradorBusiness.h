/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioAdministradorBusiness.h
 * Author: fabricio
 *
 * Created on 16 de junio de 2020, 11:38 AM
 */

#ifndef USUARIOADMINISTRADORBUSINESS_H
#define USUARIOADMINISTRADORBUSINESS_H

#include "UsuarioAdministradorData.h"


class UsuarioAdministradorBusiness {
public:
    UsuarioAdministradorBusiness();
    virtual ~UsuarioAdministradorBusiness();
    
    bool iniciarSesionAdministrador(UsuarioAdministrador* usuarioAdministrador);
    
private:
    UsuarioAdministradorData usuarioAdministradorData;
};

#endif /* USUARIOADMINISTRADORBUSINESS_H */

