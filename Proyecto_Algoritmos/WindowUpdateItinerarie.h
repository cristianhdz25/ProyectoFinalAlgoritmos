/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowUpdateItinerarie.h
 * Author: cristia
 *
 * Created on 1 de julio de 2020, 07:57 PM
 */

#ifndef WINDOWUPDATEITINERARIE_H
#define WINDOWUPDATEITINERARIE_H
#include <gtkmm.h>
#include "ClaseGrande.h"
#include "Validaciones.h"

class WindowUpdateItinerarie :  public Gtk::Window{
public:
    WindowUpdateItinerarie();
    void init();
    void clickedActualizarAerolinea();
    void clickedUp();
    void clickedUpItineraries();
    void clickedBorrar();
    void clickedCancelar();
private:
    Gtk::Fixed fixedActualizarItinerario;
    Gtk::Label lblName, lblSalida, lblDestination, lblSchedule,
    lblItinerario, lblAvion, lblEspacios;
    Gtk::Entry etName, etSalida, etDestination, etSchedule,
    etItinerario, etAvion, etEspacios;
    Gtk::Button btCancel, btSubir,
    btSubirItinerario, btnActualizar, btnBorrar;

    ClaseGrande * claseGrande;
    Validaciones valid;

};

#endif /* WINDOWUPDATEITINERARIE_H */

