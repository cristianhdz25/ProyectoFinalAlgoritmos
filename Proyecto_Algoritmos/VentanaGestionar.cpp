
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
#include <queue>

VentanaGestionar::VentanaGestionar() {
    this->set_size_request(600, 600);
    this->claseGrande = ClaseGrande::getInstance();
    this->grafo = Grafo::getInstance();
    init();
}//constructor

void VentanaGestionar::init() {
    this->fixedAirline.put(menuBar, 0, 0);
    this->menuArchivo.set_label("Gestión");
    this->menuBar.append(this->menuArchivo);
    this->menuArchivo.set_submenu(this->subMenuArchivo);
    this->menuNewAirline.set_label("New Airline");

    this->menuNewAirline.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedNewAirline));
    this->subMenuArchivo.append(this->menuNewAirline);

    this->menuActualizar.set_label("Actualizar");
    this->menuActualizar.signal_activate().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedActualizar));
    this->subMenuArchivo.append(this->menuActualizar);

    this->add(this->fixedAirline);
    this->show_all_children();
}//init

void VentanaGestionar::clickedNewAirline() {
    this->lblName.set_label("New Airline");
    this->fixedAirline.put(this->lblName, 80, 90);
    this->fixedAirline.put(this->etName, 80, 115);

    this->btAdd.set_label("Add");
    this-> fixedAirline.put(this->btAdd, 300, 400);
    this->btAdd.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedAddAirline));

    this->btnAddItinerarie.set_label("Add itinerarie");
    this-> fixedAirline.put(this->btnAddItinerarie, 350, 400);
    this->btnAddItinerarie.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedAddtinerarie));

    this->lblAvion.set_label("Nombre de Avion");
    this->fixedAirline.put(this->lblAvion, 300, 230);
    this->fixedAirline.put(this->etAvion, 300, 250);

    this->lblEspacios.set_label("Espacios del avión");
    this->fixedAirline.put(this->lblEspacios, 300, 280);
    this->fixedAirline.put(this->etEspacios, 300, 300);

    this->lblSalida.set_label("Salida");
    this->fixedAirline.put(this->lblSalida, 300, 55);
    this->fixedAirline.put(this->etSalida, 300, 90);
    
    this->lblDestination.set_label("Destination");
    this->fixedAirline.put(this->lblDestination, 300, 120);
    this->fixedAirline.put(this->etDestination, 300, 145);
    
    this->lblSchedule.set_label("Horarios");
    this->fixedAirline.put(this->lblSchedule, 300, 175);
    this->fixedAirline.put(this->etSchedule, 300, 200);

      
    this->lblPeso.set_label("Duración del vuelo");
    this->fixedAirline.put(this->lblPeso, 300, 325);
    this->fixedAirline.put(this->etPeso, 300, 350);
    
    this->lblName.set_label("New Airline");
    this->fixedAirline.put(this->lblName, 80, 90);
    this->fixedAirline.put(this->etName, 80, 115);


    this->add(this->fixedAirline);
    this->show_all_children();
}//clickedNewAirline

void VentanaGestionar::clickedAddtinerarie() {
    if (!(this->etSalida.get_text().empty()) &&
            !(this->etDestination.get_text().empty())&&
            !(this->etSchedule.get_text().empty())) {

        Avion* tempA = new Avion(this->etAvion.get_text(), stoi(this->etEspacios.get_text()));

        tempItinerario.push(new Itinerario(new Pais(this->etSalida.get_text()), (new Pais(this->etDestination.get_text())),
                this->etSchedule.get_text(), tempA));

        this->etSalida.set_text("");
        this->etDestination.set_text("");
        this->etSchedule.set_text("");
    }//if

}//clickedAddtinerariew

void VentanaGestionar::clickedAddAirline() {
    if (!(this->etName.get_text().empty())) {
        Aerolinea* temp = new Aerolinea(this->etName.get_text());

        temp->setItinerarios(tempItinerario);
        this->claseGrande->registrarAerolinea(temp);

    }//if

}//clickedAddAirline

void VentanaGestionar::clickedUp() {
    this->claseGrande->arriba();
    this->etName.set_text(this->claseGrande->mostrarAerolinea());

}//clickedUp

void VentanaGestionar::clickedActualizarAerolinea() {

}//clickedActualizarAerolinea

void VentanaGestionar::clickedUpItineraries() {
    this->claseGrande->subirItinerario();

}//clickedUpItineraries

void VentanaGestionar::clickedActualizar() {
    this->fixedAirline.~Fixed();


    this->lblName.set_label("Seleccione aerolinea para actualizar");
    this->fixedActualizar.put(this->lblName, 50, 90);
    this->fixedActualizar.put(this->etName, 50, 115);

    this->lblItinerario.set_label("Seleccione itinerario para actualizar");
    this->fixedActualizar.put(this->lblItinerario, 50, 195);
    this->fixedActualizar.put(this->etItinerario, 50, 220);

    this->btnActulizar.set_label("Actualizar");
    this-> fixedActualizar.put(this->btnActulizar, 300, 400);
    this->btnActulizar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedActualizarAerolinea));

    this->lblAvion.set_label("Nombre de Avión");
    this->fixedActualizar.put(this->lblAvion, 300, 230);
    this->fixedActualizar.put(this->etAvion, 300, 250);
    this->etAvion.set_editable(false);
    this->lblEspacios.set_label("Espacios del avión");
    this->fixedActualizar.put(this->lblEspacios, 300, 280);
    this->fixedActualizar.put(this->etEspacios, 300, 300);

    this->btSubir.set_label("Subir");
    this-> fixedActualizar.put(this->btSubir, 50, 150);
    this->btSubir.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedUp));

    this->btSubirItinerario.set_label("Subir itinerario");
    this-> fixedActualizar.put(this->btSubirItinerario, 50, 260);
    this->btSubirItinerario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaGestionar::clickedUpItineraries));

    this->lblSalida.set_label("Salida");
    this->fixedActualizar.put(this->lblSalida, 300, 55);
    this->fixedActualizar.put(this->etSalida, 300, 85);

    this->lblDestination.set_label("Destination");
    this->fixedActualizar.put(this->lblDestination, 300, 120);
    this->fixedActualizar.put(this->etDestination, 300, 145);

    this->lblSchedule.set_label("Schedule");
    this->fixedActualizar.put(this->lblSchedule, 300, 175);
    this->fixedActualizar.put(this->etSchedule, 300, 200);

    this->add(this->fixedActualizar);
    this->show_all_children();

}//clickedActualizar
