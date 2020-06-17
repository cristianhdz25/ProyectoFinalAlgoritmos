

#ifndef VENTANAGESTIONAR_H
#define VENTANAGESTIONAR_H
#include <gtkmm.h>

#include "AerolineaBusiness.h"
#include "ClaseGrande.h"
class VentanaGestionar : public Gtk::Window{
public:
    VentanaGestionar();
    void init();
    void clickedNewAirline();
    void clickedNewItinerarie();
    void clickedAddtinerarie();
    void clickedAddAirline();
private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::Menu subMenuArchivo;
    Gtk::ImageMenuItem menuNewAirline,menuNewItinerarie;
    Gtk::Fixed fixedAirline,fixedItineraries;
    
    Gtk::Label lblName,lblSalida,lblDestination,lblSchedule;
    Gtk::Entry etName,etSalida,etDestination,etSchedule;
    Gtk::Button btAdd,btnAddItinerarie;
    
    ClaseGrande * claseGrande; 
};

#endif /* VENTANAGESTIONAR_H */

