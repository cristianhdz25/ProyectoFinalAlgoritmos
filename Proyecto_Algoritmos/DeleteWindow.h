

#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include "gtkmm.h" 
class DeleteWindow : public Gtk::Window{
public:
    DeleteWindow();
    void init();
    void clickedIn();
private:

    Gtk::Entry etConsulta;
    Gtk::Button btnEliminar;
    Gtk::Fixed fixed;
    Gtk::Label lblConsulta;
    
};

#endif /* DELETEWINDOW_H */

