
#include "VentanaAdmin.h"
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 
#include <sstream>
#include "string.h"
#include <iostream>
using namespace std;

VentanaAdmin::VentanaAdmin() {
    this->set_size_request(350, 300);
    this->set_title("Cuenta de Administrador");
    init();
}//constructor

void VentanaAdmin::init() {
    this->lblPassword.set_text("Password");
    this->fixed.put(this->lblPassword, 125, 50);

    this->fixed.put(this->etPassword, 125, 95);

    this->btAceptar.set_label("get in");
    this->btAceptar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAdmin::clickedIn));
    this->fixed.put(this->btAceptar, 125, 140);
    this->ventanaGestionar = 0;

    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaAdmin::clickedIn() {
    if (this->ventanaGestionar != 0)
        return;

    this->ventanaGestionar = new VentanaGestionar();
    this->ventanaGestionar->signal_hide().connect(sigc::mem_fun(*this, &VentanaAdmin::aboutWinClose));
    this->ventanaGestionar->show();
}//clickedIn

void VentanaAdmin::aboutWinClose() {
    this->ventanaGestionar = 0;
}//aboutWInClose
