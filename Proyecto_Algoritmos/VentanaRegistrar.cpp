

#include "VentanaRegistrar.h"
#include <bits/stl_tempbuf.h>
#include "iostream"
#include <gtkmm.h>

VentanaRegistrar::VentanaRegistrar() {
    this->set_size_request(400, 300);
    this->set_title("Registrar");
    init();
}

void VentanaRegistrar::init() {

    this->lblEdad.set_label("Edad");
    this->fixed.put(this->lblEdad, 20, 20);
    this->fixed.put(this->etEdad, 120, 20);

    this->lblNombre.set_label("Nombre");
    this->fixed.put(this->lblNombre, 20, 60);
    this->fixed.put(this->etNombre, 120, 60);

    this->lblGenero.set_label("Genero");
    this->fixed.put(this->lblGenero, 20, 100);
    this->fixed.put(this->etGenero, 120, 100);

    this->lblPasaporte.set_label("Pasaporte");
    this->fixed.put(this->lblPasaporte, 20, 140);
    this->fixed.put(this->etPasaporte, 120, 140);

    this->lblNacionalidad.set_label("Nacionalidad");
    this->fixed.put(this->lblNacionalidad, 20, 180);
    this->fixed.put(this->etNacionalidad, 120, 180);

    this->btnRegistrar.set_label("Registrar");
    this->btnRegistrar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaRegistrar::onButtonClickedRegistrar));
    this->fixed.put(this->btnRegistrar, 150, 220);

    this->btnCancelar.set_label("Cancelar");
    this->btnCancelar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaRegistrar::onButtonClickedCancelar));
    this->fixed.put(this->btnCancelar, 250, 220);

    this->ventanaReservar = 0;

    this->add(this->fixed);
    this->show_all_children();
}

void VentanaRegistrar::onButtonClickedRegistrar() {


    if (this->ventanaReservar != 0)
        return;

    this->ventanaReservar = new VentanaReservar();
    this->ventanaReservar->signal_hide().connect(sigc::mem_fun(*this, &VentanaRegistrar::aboutWinClose));
    this->ventanaReservar->show();
    this->hide();
}

void VentanaRegistrar::onButtonClickedCancelar() {
    this->hide();
}

void VentanaRegistrar::aboutWinClose() {
    this->ventanaReservar = 0;
}
