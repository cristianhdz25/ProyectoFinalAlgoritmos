/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowLogin.h
 * Author: cristia
 *
 * Created on 21 de junio de 2020, 08:52 PM
 */

#ifndef WINDOWLOGIN_H
#define WINDOWLOGIN_H

#include <gtkmm.h>
#include "ClaseGrande.h"

class WindowLogin : public Gtk::Window {
public:
    WindowLogin();
    void init();
    void onButtonClickedLogin();
    void onButtonClickedExit();

private:
    Gtk::Label lblPassport, lblPassword;
    Gtk::Entry etPassport, etPassword;
    ClaseGrande * claseGrande;
    
    Gtk::Button btnLogin, btnExit;
    Gtk::Fixed fixed;
};

#endif /* WINDOWLOGIN_H */

