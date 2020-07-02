

#ifndef VENTANAGESTIONAR_H
#define VENTANAGESTIONAR_H
#include <gtkmm.h>

#include "AerolineaBusiness.h"
#include "ClaseGrande.h"
#include "WindowAddNewAirline.h"
#include "WindowUpdateAirlane.h"
#include "WindowUpdateItinerarie.h"

class VentanaGestionar : public Gtk::Window {
public:
    VentanaGestionar();
    void init();
    void clickedNewAirline();
    void clickedUpdateAirline();
    void clickedUpdateItinerarie();
    void aboutWinClose();

private:
    Gtk::MenuBar menuBar;
    Gtk::MenuItem menuArchivo;
    Gtk::Menu subMenuArchivo;
    Gtk::ImageMenuItem imageMenuNewAirline, imageMenuActualizar, imageMenuUpdateAirline;
    Gtk::Fixed fixed;
    
    WindowAddNewAirline * windowNewAirline;
    WindowUpdateAirlane * windowUpdateAirlane;
    WindowUpdateItinerarie * windowUpdateItinerarie;
    
};

#endif /* VENTANAGESTIONAR_H */

