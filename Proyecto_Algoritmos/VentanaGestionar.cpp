#include "VentanaGestionar.h"
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm.h>
#include <bits/stl_tempbuf.h>
#include <gtkmm-3.0/gtkmm/widget.h>
#include <string>
#include <gtkmm-3.0/gtkmm/textbuffer.h> 
#include <sstream>
#include "string.h"
#include "AerolineaBusiness.h"
#include "ClaseGrande.h"
#include "Pais.h"
#include "WindowUpdateItinerarie.h"
#include <queue>

VentanaGestionar::VentanaGestionar() {
    this->set_size_request(600, 600);
    init();
}//constructor

void VentanaGestionar::init() {
    this->fixed.put(menuBar, 0, 0);
    this->menuArchivo.set_label("Gestión");
    this->menuBar.append(this->menuArchivo);
    this->menuArchivo.set_submenu(this->subMenuArchivo);
    this->imageMenuNewAirline.set_label("Nueva Aerolinea");

    this->imageMenuNewAirline.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedNewAirline));
    this->subMenuArchivo.append(this->imageMenuNewAirline);

    this->imageMenuActualizar.set_label("Actualizar Itinerario");
    this->imageMenuActualizar.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedUpdateItinerarie));
    this->subMenuArchivo.append(this->imageMenuActualizar);

    this->imageMenuUpdateAirline.set_label("Actualizar Aerolinea");
    this->imageMenuUpdateAirline.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedUpdateAirline));
    this->subMenuArchivo.append(this->imageMenuUpdateAirline);

    this->windowNewAirline = 0;
    this->windowUpdateAirlane = 0;
    this->windowUpdateItinerarie = 0;

    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaGestionar::clickedNewAirline() {
    if (this->windowNewAirline != 0)
        return;

    this->windowNewAirline = new WindowAddNewAirline();
    this->windowNewAirline->signal_hide().connect(sigc::mem_fun(*this, &VentanaGestionar::aboutWinClose));
    this->windowNewAirline->show();
}//clickedNewAirline

void VentanaGestionar::clickedUpdateAirline() {
    if (this->windowUpdateAirlane != 0)
        return;

    this->windowUpdateAirlane = new WindowUpdateAirlane();
    this->windowUpdateAirlane->signal_hide().connect(sigc::mem_fun(*this, &VentanaGestionar::aboutWinClose));
    this->windowUpdateAirlane->show();
}//clickedUpdateAirline

void VentanaGestionar::clickedUpdateItinerarie() {
    if (this->windowUpdateItinerarie != 0)
        return;

    this->windowUpdateItinerarie = new WindowUpdateItinerarie();
    this->windowUpdateItinerarie->signal_hide().connect(sigc::mem_fun(*this, &VentanaGestionar::aboutWinClose));
    this->windowUpdateItinerarie->show();
}//clickedUpdateItinerarie

void VentanaGestionar::aboutWinClose() {
    this->windowNewAirline = 0;
    this->windowUpdateAirlane = 0;
    this->windowUpdateItinerarie = 0;
}//aboutWinClose

