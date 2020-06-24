#include "Drawing.h"

Drawing::Drawing() {
    this->set_size_request(800, 800);
    this->aristas = new vector<Arista*>();
    this->vertice = new Vertice();
    this->grafo = Grafo::getInstance();
    initPosiciones();
}//constructor

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    for (int i = 0; i < this->grafo->grafo.size(); i++) {
        this->grafo->grafo.at(i)->draw(cr);
        this->draw_text(cr, this->grafo->grafo.at(i)->getPosX(), this->grafo->grafo.at(i)->getPosY() + 20, this->grafo->grafo.at(i)->pais->getNombre());
    }//for
    for (int i = 0; i < this->aristas->size(); i++) {
       this->aristas->at(i)->draw(cr);
    }

}//on_draw

void Drawing::initPosiciones() {
    int x = 0;
    int y = 0;
    int x1 = 0;
    int y1 = 0;
    
    for (int i = 0; i<this->grafo->grafo.size(); i++) {
        if(this->grafo->grafo.at(i)->getPosX()==0 && this->grafo->grafo.at(i)->getPosY()==0){
        this->grafo->grafo.at(i)->setPosX(x += 30);
        this->grafo->grafo.at(i)->setPosY(y = 10);
        }//if i
        for (int j = 0; j< this->grafo->grafo.at(i)->listaAristas.size(); j++) {    
            if(this->grafo->grafo.at(i)->listaAristas.at(j)->getPosX()==0 
                    &&this->grafo->grafo.at(i)->listaAristas.at(j)->getPosY()==0){
            this->grafo->grafo.at(i)->listaAristas.at(j)->setPosX(x1 += 30);
            this->grafo->grafo.at(i)->listaAristas.at(j)->setPosY(y1 = 200);
            this->aristas->push_back(new Arista(grafo->grafo.at(i),this->grafo->grafo.at(i)->listaAristas.at(j)));
            }//if j
        }//for j
        
    }//for i
    
}//asignaPosiciones

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