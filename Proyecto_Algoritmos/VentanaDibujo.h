
#ifndef VENTANADIBUJO_H
#define VENTANADIBUJO_H

#include "iostream"
#include "Drawing.h" 
#include <gtkmm/window.h>
#include <gtkmm/box.h>
class VentanaDibujo : public Gtk::Window {
public:
    VentanaDibujo();
  
private:
    Drawing d;
};

#endif /* VENTANADIBUJO_H */

