/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuarioAdministradorData.h
 * Author: fabricio
 *
 * Created on 16 de junio de 2020, 11:31 AM
 */

#ifndef USUARIOADMINISTRADORDATA_H
#define USUARIOADMINISTRADORDATA_H

#include "UsuarioAdministrador.h"


class UsuarioAdministradorData {
public:
    UsuarioAdministradorData();
    virtual ~UsuarioAdministradorData();
    
    bool iniciarSesionAdministrador(UsuarioAdministrador* usuarioAdministrador);
    
private:
    UsuarioAdministrador* cuentaAdministrador;
};

#endif /* USUARIOADMINISTRADORDATA_H */

