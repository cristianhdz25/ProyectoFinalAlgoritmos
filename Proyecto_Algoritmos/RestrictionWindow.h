

#ifndef RESTRICTIONWINDOW_H
#define RESTRICTIONWINDOW_H
#include "gtkmm.h"
#include "ClaseGrande.h"
#include <vector>

class RestrictionWindow : public Gtk::Window {
public:
    RestrictionWindow();
    void init();
    void addRestriction();
    void addAll();
private:
    Gtk::Label lblRestriction, lblPaises;
    Gtk::Entry etPais, etRestriciones;
    Gtk::Button btnAdd, btnAddAll;
    Gtk::Fixed fixed;
    vector<Pais*> tempRestricciones;
    RestriccionData* restriccionData;
    ClaseGrande * claseGrande;
};

#endif /* RESTRICTIONWINDOW_H */

