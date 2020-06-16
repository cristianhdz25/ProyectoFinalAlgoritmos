/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UsuariosAdministrador.h
 * Author: fabricio
 *
 * Created on 16 de junio de 2020, 11:25 AM
 */

#ifndef USUARIOADMINISTRADOR_H
#define USUARIOADMINISTRADOR_H
#include <string>

using namespace std;

class UsuarioAdministrador {
public:
    UsuarioAdministrador(string userId, string password);
    virtual ~UsuarioAdministrador();
    
    void setPassword(string password);
    string getPassword() const;
    void setUserId(string userId);
    string getUserId() const;
    
private:
    string userId, password;
};

#endif /* USUARIOADMINISTRADOR_H */

