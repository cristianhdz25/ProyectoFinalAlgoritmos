/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowFlights.cpp
 * Author: cristia
 * 
 * Created on 23 de junio de 2020, 04:57 PM
 */

#include <iostream>
#include "WindowFlights.h"
#include "ClaseGrande.h"
#include <gtkmm-3.0/gtkmm.h>

WindowFlights::WindowFlights()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
m_Button_Quit("Salir") {
    set_title("Vuelos");
    set_border_width(5);
    set_default_size(480, 350);

    this->claseGrande = ClaseGrande::getInstance();
    this->aerolineas = this->claseGrande->getAerolineas();
    add(m_VBox);

    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TreeView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_VBox.pack_start(m_ScrolledWindow);
    m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

    m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
    m_ButtonBox.set_border_width(5);
    m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
    m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
            &WindowFlights::on_button_quit));

    //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);


    //Fill the TreeView's model
    Gtk::TreeModel::Row row;
    for (int i = 0; i < this->aerolineas.size(); i++) {
        Aerolinea* temp = this->aerolineas.front();
        queue<Itinerario*> itinerarios = this->aerolineas.front()->getItinerarios();
        queue<Itinerario*> aux = itinerarios;
        for (int i = 0; i < itinerarios.size(); i++) {
            row = *(m_refTreeModel->append());
            row[m_Columns.m_col_time] = aux.front()->getHora();
            row[m_Columns.m_col_origin] = aux.front()->getOrigen()->getNombre();
            row[m_Columns.m_col_destination] = aux.front()->getDestino()->getNombre();
            row[m_Columns.m_col_plane] = aux.front()->getAvion()->getNamePlane();
            row[m_Columns.m_col_spaces] = aux.front()->getAvion()->getQuantity();
            row[m_Columns.m_col_airline] = temp->getNombre();
            aux.pop();
        }
        this->aerolineas.pop_front();
        this->aerolineas.push_back(temp);
    }
    
    m_TreeView.append_column("Tiempo", m_Columns.m_col_time);
    m_TreeView.append_column("Origen", m_Columns.m_col_origin);
    m_TreeView.append_column("Destino", m_Columns.m_col_destination);
    m_TreeView.append_column("Avion", m_Columns.m_col_plane);
    m_TreeView.append_column("Espacios", m_Columns.m_col_spaces);
    m_TreeView.append_column("Aerolinea", m_Columns.m_col_airline);


    for (guint i = 0; i < 2; i++) {
        auto column = m_TreeView.get_column(i);
        column->set_reorderable();
    }

    show_all_children();
}

WindowFlights::~WindowFlights() {
}

void WindowFlights::on_button_quit() {
    hide();
}

