/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowAddNewAirline.h
 * Author: cristia
 *
 * Created on 1 de julio de 2020, 08:10 PM
 */

#ifndef WINDOWADDNEWAIRLINE_H
#define WINDOWADDNEWAIRLINE_H

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <queue>
#include "Itinerario.h"
#include "ClaseGrande.h"
#include "Grafo.h"
#include "Validaciones.h"
#include "RestriccionData.h"

using namespace std;

class WindowAddNewAirline : public Gtk::Window{
public:
    WindowAddNewAirline();
    void init();
    void clickedNewAirline();
    void clickedActualizar();
    void clickedAddtinerarie();
    void clickedAddAirline();
    void existe(Aerolinea* aerolinea);
private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::Menu subMenuArchivo;
    Gtk::ImageMenuItem menuNewAirline, menuActualizar;
    Gtk::Fixed fixedAirline;

    Gtk::Label lblName, lblSalida, lblDestination, lblHoraSalida,lblHoraLlegada,
    lblItinerario, lblAvion, lblEspacios, lblPeso;
    Gtk::Entry etName, etSalida, etDestination, etHoraSalida,etHoraLlegada,
    etItinerario, etAvion, etEspacios, etPeso;
    Gtk::Button btAdd, btnAddItinerarie, btCancel, btSubir,
    btSubirItinerario, btnActulizar;

    queue<Itinerario*> tempItinerario;

    ClaseGrande * claseGrande;
    Grafo * grafo;
    Validaciones valid;
    RestriccionData* restriccionData;
};

#endif /* WINDOWADDNEWAIRLINE_H */

