#ifndef DRAWING_H
#define DRAWING_H
#include <gtkmm.h>
#include "iostream"
#include "Vertice.h"
#include "Grafo.h"
#include "Arista.h"
#include <stdio.h>      /* puts, printf */
#include <time.h> 

using namespace std;

class Drawing :public Gtk::DrawingArea{
public:
    Drawing();
   
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
    void draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int posX, int posY, string text);
    void initPosiciones();
private:
    tm *tm_local;
    time_t curr_time;
    Vertice* vertice;
    Grafo* grafo;
    vector<Arista*> * aristas;
    int x,y,hora;
};

#endif /* DRAWING_H */

