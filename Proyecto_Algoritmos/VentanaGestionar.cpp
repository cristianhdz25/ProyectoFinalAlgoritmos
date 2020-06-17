
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

VentanaGestionar::VentanaGestionar() {
    this->set_size_request(600, 600);
    this->claseGrande = ClaseGrande::getInstance();
    init();  
}//constructor

void VentanaGestionar::init() {
    this->fixedAirline.put(menuBar, 0, 0);
    this->menuArchivo.set_label("Gestión");
    this->menuBar.append(this->menuArchivo);
    this->menuArchivo.set_submenu(this->subMenuArchivo);
    this->menuNewAirline.set_label("New Airline");
    this->menuNewItinerarie.set_label("New Itinerarie");

    this->menuNewAirline.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedNewAirline));
    this->subMenuArchivo.append(this->menuNewAirline);

    this->menuNewItinerarie.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedNewItinerarie));
    this->subMenuArchivo.append(this->menuNewItinerarie);


    this->add(this->fixedAirline);
    this->show_all_children();
}//init

void VentanaGestionar::clickedNewAirline() {
    this->lblName.set_label("New Airline");
    this->fixedAirline.put(this->lblName, 80, 90);
    this->fixedAirline.put(this->etName, 80, 110);

    this->btAdd.set_label("Add");
    this-> fixedAirline.put(this->btAdd, 80, 150);
    this->btAdd.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedAddAirline));

    this->add(this->fixedAirline);
    this->show_all_children();
}//clickedNewAirline

void VentanaGestionar::clickedNewItinerarie() {
    this->fixedAirline.~Fixed();

    this->lblSalida.set_label("Salida");
    this->fixedItineraries.put(this->lblSalida, 80, 55);
    this->fixedItineraries.put(this->etSalida, 80, 85);

    this->lblDestination.set_label("Destination");
    this->fixedItineraries.put(this->lblDestination, 80, 120);
    this->fixedItineraries.put(this->etDestination, 80, 145);

    this->lblSchedule.set_label("Schedule");
    this->fixedItineraries.put(this->lblSchedule, 80, 165);
    this->fixedItineraries.put(this->etSchedule, 80, 190);

    this->btAdd.set_label("Add");
    this->fixedItineraries.put(this->btAdd, 100, 210);
    this->btAdd.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedAddtinerarie));
    
    this->add(this->fixedItineraries);
    this->show_all_children();
}//clickedNewItinerarie

void VentanaGestionar::clickedAddAirline() {
    if(!(this->etName.get_text().empty())){
       this->claseGrande->registrarAerolinea(new Aerolinea(this->etName.get_text()));
    
    }//if
    
}//clickedAddAirline

void VentanaGestionar::clickedAddtinerarie() {

}//clickedAddtinerarie
