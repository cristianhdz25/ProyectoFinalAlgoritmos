/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowUpdateAirlane.h
 * Author: cristia
 *
 * Created on 1 de julio de 2020, 07:55 PM
 */

#ifndef WINDOWUPDATEAIRLANE_H
#define WINDOWUPDATEAIRLANE_H

#include <gtkmm-3.0/gtkmm/entry.h>
#include <gtkmm.h>
#include "ClaseGrande.h"


class WindowUpdateAirlane : public Gtk::Window {
public:
    WindowUpdateAirlane();
    void init();
    void clickedUp();
    void clickedAccept();
    void clickedCancel();
    void clickedDelete();
private:
    ClaseGrande * claseGrande;
    Gtk::Label lblAirline, lblNewName;
    Gtk::Entry etName,etNewName;
    Gtk::Button btnAccept, btnCancel, btnUp, btnDelete;
    Gtk::Fixed fixed;
    
};

#endif /* WINDOWUPDATEAIRLANE_H */

