/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowConfig.h
 * Author: cristia
 *
 * Created on 21 de junio de 2020, 09:27 PM
 */

#ifndef WINDOWCONFIG_H
#define WINDOWCONFIG_H

#include <gtkmm.h>
#include "ClaseGrande.h"

class WindowConfig : public Gtk::Window  {
public:
    WindowConfig();
    void init();
    void onButtonClickedUpdate();
    void onButtonClickedExit();

private:
    Gtk::Label lblAge,lblName,lblGender,lblPassport,lblNacionality,lblPassword;
    Gtk::Entry etAge,etName,etGender,etPassport,etNacionality,etPassword;
    Gtk::Button btnUpdate,btnExit;
    Gtk::Fixed fixed;

    ClaseGrande * claseGrande;
};

#endif /* WINDOWCONFIG_H */

