/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuariosAdministrador.cpp
 * Author: fabricio
 * 
 * Created on 16 de junio de 2020, 11:25 AM
 */

#include "UsuarioAdministrador.h"

UsuarioAdministrador::UsuarioAdministrador(string userId, string password) {
    this->userId=userId;
    this->password=password;
}

UsuarioAdministrador::~UsuarioAdministrador() {
}

void UsuarioAdministrador::setPassword(string password) {
    this->password = password;
}

string UsuarioAdministrador::getPassword() const {
    return password;
}

void UsuarioAdministrador::setUserId(string userId) {
    this->userId = userId;
}

string UsuarioAdministrador::getUserId() const {
    return userId;
}

