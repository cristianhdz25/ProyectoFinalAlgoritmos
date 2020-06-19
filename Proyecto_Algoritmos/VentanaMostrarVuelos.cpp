#include "VentanaMostrarVuelos.h"

VentanaMostrarVuelos::VentanaMostrarVuelos() {
    this->set_size_request(250,250);
    this->set_title("Vuelos");
    this->claseGrande = ClaseGrande::getInstance();
    this->posicion=0;
    init();
}//constructor

void VentanaMostrarVuelos::init() {
    this->lblMostrar.set_label("Seleccione vuelo");
    this->fixed.put(this->lblMostrar, 0, 50);
    this->etMostrarVertices.set_editable(false);
    this->fixed.put(this->etMostrarVertices, 0, 70);

    this->btnMover.set_label("Subir");
    this->btnMover.signal_clicked().connect(sigc::mem_fun(*this, &VentanaMostrarVuelos::clikedDraw));
    this->fixed.put(this->btnMover, 0, 100);

    this->add(this->fixed);
    this->show_all_children();
}//init
void VentanaMostrarVuelos::clikedDraw() {
    this->posicion++;
}//clickdraw
