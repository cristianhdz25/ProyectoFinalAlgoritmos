

#ifndef VENTANAGESTIONAR_H
#define VENTANAGESTIONAR_H
#include <gtkmm.h>

#include "AerolineaBusiness.h"
#include "ClaseGrande.h"

class VentanaGestionar : public Gtk::Window {
public:
    VentanaGestionar();
    void init();
    void clickedNewAirline();
    void clickedActualizar();
    void clickedAddtinerarie();
    void clickedAddAirline();
    void clickedUp();
    void clickedActualizarAerolinea();
    void clickedUpItineraries();
private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::Menu subMenuArchivo;
    Gtk::ImageMenuItem menuNewAirline, menuActualizar;
    Gtk::Fixed fixedAirline, fixedActualizar;

    Gtk::Label lblName, lblSalida, lblDestination, lblSchedule,
    lblItinerario, lblAvion, lblEspacios;
    Gtk::Entry etName, etSalida, etDestination, etSchedule,
    etItinerario, etAvion, etEspacios;
    Gtk::Button btAdd, btnAddItinerarie, btCancel, btSubir,
    btSubirItinerario, btnActulizar;

    queue<Itinerario*> tempItinerario;

    ClaseGrande * claseGrande;
    Grafo * grafo;
};

#endif /* VENTANAGESTIONAR_H */

