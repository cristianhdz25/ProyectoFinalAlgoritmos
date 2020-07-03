
#include "RestrictionWindow.h"
#include "Pais.h"

RestrictionWindow::RestrictionWindow() {
    this->set_size_request(400, 400);
    this->set_title("Ventana de retricciones");
    init();
    this->claseGrande = ClaseGrande::getInstance();
    this->restriccionData = RestriccionData::getInstance();
}//constructor

void RestrictionWindow::init() {
    this->lblRestriction.set_text("Pais con restriciones");
    this->fixed.put(this->lblRestriction, 10, 10);
    this->fixed.put(this->etRestriciones, 10, 30);

    this->lblPaises.set_text("Paises restringidos");
    this->fixed.put(this->lblPaises, 10, 70);
    this->fixed.put(this->etPais, 10, 90);

    this->btnAdd.set_label("Añadir país");
    this->fixed.put(this->btnAdd, 10, 115);
    this->btnAdd.signal_clicked().connect(sigc::mem_fun(*this, &RestrictionWindow::addRestriction));


    this->btnAddAll.set_label("Añadir Restricción");
    this->fixed.put(this->btnAddAll, 90, 115);
    this->btnAddAll.signal_clicked().connect(sigc::mem_fun(*this, &RestrictionWindow::addAll));


    this->add(this->fixed);
    this->show_all_children();
}//init

void RestrictionWindow::addRestriction() {
    if (!(this->etRestriciones.get_text().empty()) &&
            !(this->etPais.get_text().empty())) {

        int indice = this->restriccionData->existePais(this->etRestriciones.get_text());
        if (indice != -1) {
            this->restriccionData->anadirRestriccion(new Pais(this->etPais.get_text()),indice);
           
            cout<<"entra"<<endl;
        
        } else {

            Pais* tempP = new Pais(this->etRestriciones.get_text());
            tempP->getRestricciones()->push_back(new Pais(this->etRestriciones.get_text()));
            this->restriccionData->registrarRestricciones(tempP);

        }//else
    }//if
   

}//addAll

void RestrictionWindow::addAll() {

    if (!(this->etRestriciones.get_text().empty())) {


    }//if
}//addRestriction
