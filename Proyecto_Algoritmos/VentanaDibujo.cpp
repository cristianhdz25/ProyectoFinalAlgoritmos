
#include "VentanaDibujo.h"

VentanaDibujo::VentanaDibujo() {
    this->set_title("Ventana dibujar");
    this->d.show_all();
    this->add(this->d);
}//constructor
