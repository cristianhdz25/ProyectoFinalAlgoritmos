#include "Drawing.h"
#include <stdio.h>      /* puts, printf */
#include <time.h> 

Drawing::Drawing() {
    this->set_size_request(800, 800);
    this->aristas = new vector<Arista*>();
    this->vertice = new Vertice();
    this->grafo = Grafo::getInstance();
    
}//constructor

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    this->curr_time = time(NULL);
    this->tm_local = localtime(&this->curr_time);
    
    this->hora = (this->tm_local->tm_hour);
    for (int i = 0; i < this->grafo->grafo.size(); i++) {
        this->grafo->grafo.at(i)->draw(cr);
        this->draw_text(cr, this->grafo->grafo.at(i)->getPosX(),
                this->grafo->grafo.at(i)->getPosY() + 20,
                this->grafo->grafo.at(i)->pais->getNombre());
    }//for
    
    for (int i = 0; i < this->grafo->aristas.size(); i++) {
        
        if (this->grafo->aristas.at(i)->getHoraSalida() <= this->hora 
                && this->grafo->aristas.at(i)->getHoraLlegada() >this->hora ) {
            
            this->grafo->aristas.at(i)->draw(cr);
        }//if
    }// for i
    this->queue_draw();
}//on_draw


void Drawing::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int posX, int posY, string text) {
    Pango::FontDescription font;

    font.set_size(10 * Pango::SCALE);
    font.set_family("Mukti Narrow");
    font.set_weight(Pango::WEIGHT_BOLD);

    Glib::RefPtr<Pango::Layout> layout = create_pango_layout(text);

    layout->set_font_description(font);

    int text_width;
    int text_height;

    layout->get_pixel_size(text_width, text_height);

    cr->move_to(posX, posY);

    layout->show_in_cairo_context(cr);
}