/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowFlights.h
 * Author: cristia
 *
 * Created on 23 de junio de 2020, 04:57 PM
 */

#ifndef WINDOWFLIGHTS_H
#define WINDOWFLIGHTS_H

#include <gtkmm.h>
#include "Aerolinea.h"
#include "ClaseGrande.h"
#include "string"

using namespace std;

class WindowFlights : public Gtk::Window {
public:
    WindowFlights();
    virtual ~WindowFlights();

protected:
    //Signal handlers:
    void on_button_quit();

    //Tree model columns:

    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() {
            add(m_col_time);
            add(m_col_origin);
            add(m_col_destination);
            add(m_col_plane);
            add(m_col_spaces);
            add(m_col_airline);
            add(m_col_state);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_time;
        Gtk::TreeModelColumn<Glib::ustring> m_col_origin;
        Gtk::TreeModelColumn<Glib::ustring> m_col_destination;
        Gtk::TreeModelColumn<Glib::ustring> m_col_plane;
        Gtk::TreeModelColumn<int> m_col_spaces;
        Gtk::TreeModelColumn<Glib::ustring> m_col_airline;
        Gtk::TreeModelColumn<Glib::ustring> m_col_state;
    };

    ModelColumns m_Columns;

    //Child widgets:
    list<Aerolinea*>* aerolineas;
    tm *tm_local;
    time_t curr_time;
    ClaseGrande * claseGrande;
    Gtk::Box m_VBox;
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_Quit;
};

#endif /* WINDOWFLIGHTS_H */

