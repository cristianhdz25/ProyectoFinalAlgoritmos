
#ifndef VENTANAADMIN_H
#define VENTANAADMIN_H

#include <gtkmm.h>

#include "VentanaGestionar.h"

class VentanaAdmin :public Gtk::Window  {
public:
    VentanaAdmin();
    void init();
    void clickedIn();
    void aboutWinClose();
private:
    Gtk::Entry etPassword,etUserName;
    Gtk::Button btAceptar;
    Gtk::Label lblPassword,lblUserName;
    Gtk::Fixed fixed;
    VentanaGestionar* ventanaGestionar;
};

#endif /* VENTANAADMIN_H */

