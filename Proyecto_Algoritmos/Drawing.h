#ifndef DRAWING_H
#define DRAWING_H
#include <gtkmm.h>
#include "iostream"
#include "Vertice.h"
#include "Grafo.h"
#include "Arista.h"

using namespace std;

class Drawing :public Gtk::DrawingArea{
public:
    Drawing();
   
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    void initPosiciones();
private:
    Vertice* vertice;
    Grafo* grafo;
    vector<Arista*> * aristas;
    int x,y;
};

#endif /* DRAWING_H */

