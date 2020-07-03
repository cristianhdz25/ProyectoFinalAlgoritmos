#include "WindowAddNewAirline.h"

WindowAddNewAirline::WindowAddNewAirline() {
    this->set_size_request(600, 600);
    this->set_title("Registrar Aerolinea");
    this->claseGrande = ClaseGrande::getInstance();
    this->grafo = Grafo::getInstance();
    this->restriccionData = RestriccionData::getInstance();
    init();
}//constructor

void WindowAddNewAirline::init() {
    this->lblName.set_label("Nueva Aerolinea");
    this->fixedAirline.put(this->lblName, 20, 20);
    this->fixedAirline.put(this->etName, 20, 40);

    this->btAdd.set_label("Guardar");
    this-> fixedAirline.put(this->btAdd, 300, 500);
    this->btAdd.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddNewAirline::clickedAddAirline));

    this->btnAddItinerarie.set_label("Añadir Itinerario");
    this->fixedAirline.put(this->btnAddItinerarie, 400, 500);
    this->btnAddItinerarie.signal_clicked().connect(sigc::mem_fun(*this, &WindowAddNewAirline::clickedAddtinerarie));

    this->lblAvion.set_label("Nombre de Avion");
    this->fixedAirline.put(this->lblAvion, 300, 260);
    this->fixedAirline.put(this->etAvion, 300, 280);

    this->lblEspacios.set_label("Espacios del avión");
    this->fixedAirline.put(this->lblEspacios, 300, 320);
    this->fixedAirline.put(this->etEspacios, 300, 340);

    this->lblSalida.set_label("Salida");
    this->fixedAirline.put(this->lblSalida, 300, 20);
    this->fixedAirline.put(this->etSalida, 300, 40);

    this->lblDestination.set_label("Destination");
    this->fixedAirline.put(this->lblDestination, 300, 80);
    this->fixedAirline.put(this->etDestination, 300, 100);

    this->lblHoraSalida.set_label("Hora de salida");
    this->fixedAirline.put(this->lblHoraSalida, 300, 140);
    this->fixedAirline.put(this->etHoraSalida, 300, 160);

    this->lblHoraLlegada.set_label("Hora de llegada");
    this->fixedAirline.put(this->lblHoraLlegada, 300, 200);
    this->fixedAirline.put(this->etHoraLlegada, 300, 220);

    this->add(this->fixedAirline);
    this->show_all_children();
}//INIT

void WindowAddNewAirline::clickedAddtinerarie() {
    if (!(this->etSalida.get_text().empty()) &&
            !(this->etDestination.get_text().empty())&&
            !(this->etHoraSalida.get_text().empty()) &&
            !(this->etHoraLlegada.get_text().empty()) &&
        !(this->etAvion.get_text().empty())) {

        Avion* tempA = new Avion(this->etAvion.get_text(), stoi(this->etEspacios.get_text()));

        int indice = this->restriccionData->existePais(this->etDestination.get_text());


        if (indice != -1) {

            this->tempItinerario.push(new Itinerario(new Pais(this->etSalida.get_text()), this->restriccionData->getRegistroRestricciones().at(indice),
                    atoi(this->etHoraSalida.get_text().c_str()), atoi(this->etHoraLlegada.get_text().c_str()), tempA));

        } else {
            int ultimaPosicion = this->restriccionData->getRegistroRestricciones().size();
            Pais* tempP = new Pais(this->etDestination.get_text());
            this->restriccionData->registrarRestricciones(tempP);
            this->tempItinerario.push(new Itinerario(new Pais(this->etSalida.get_text()), this->restriccionData->getRegistroRestricciones().at(ultimaPosicion),
                    atoi(this->etHoraSalida.get_text().c_str()), atoi(this->etHoraLlegada.get_text().c_str()), tempA));

        }//if

        this->etSalida.set_text("");
        this->etDestination.set_text("");
        this->etHoraLlegada.set_text("");
        this->etAvion.set_text("");
        this->etEspacios.set_text("");
        this->etHoraSalida.set_text("");
    }
}//clickedAddtinerariew

void WindowAddNewAirline::clickedAddAirline() {
    if (!(this->etName.get_text().empty())) {
        if (this->valid.COMPROBARNUMEROS(this->etEspacios.get_text())) {
            Aerolinea* temp = new Aerolinea(this->etName.get_text());
            if (!this->claseGrande->existe(temp)) {

                temp->setItinerarios(this->tempItinerario);

                this->claseGrande->registrarAerolinea(temp);
                Gtk::MessageDialog dialogo(
                        *this,
                        "Se registro correctamente",
                        false,
                        Gtk::MESSAGE_INFO
                        );
                dialogo.run();
                this->etName.set_text("");

          } 
            else {
                Gtk::MessageDialog dialogo(
                        *this,
                        "Ya existe esa aerolinea, cambia el nombre",
                        false,
                        Gtk::MESSAGE_INFO
                        );
                dialogo.run();


            }
        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error al registrar",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("La duracion es un numero");
            dialogo.run();
        }

    } else {
        Gtk::MessageDialog dialogo(
                *this,
                "Error al registrar",
                false,
                Gtk::MESSAGE_INFO
                );
        dialogo.set_secondary_text("Espacio del nombre en blanco");
        dialogo.run();
    }
}//clickedAddAirline



