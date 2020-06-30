/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   WindowDelete.h
 * Author: cristia
 *
 * Created on 29 de junio de 2020, 07:31 PM
 */

#ifndef WINDOWDELETE_H
#define WINDOWDELETE_H

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h>
#include "VentanaItinerarios.h"
#include "ClaseGrande.h"

class WindowDelete : public Gtk::Window {
public:
    WindowDelete();
    void init();
    void mostrarInfo();
    void onButtonClickedBorrar();
    void onButtonClickedCancelar();
private:
    Gtk::Label lblInformacion;
    Glib::RefPtr<Gtk::TextBuffer> muestraInfo;
    Gtk::TextView tvMostrar;
    Gtk::Button btnEliminar, btnCancelar;
    Gtk::Fixed fixed;
    ClaseGrande * claseGrande;
};

#endif /* WINDOWDELETE_H */

