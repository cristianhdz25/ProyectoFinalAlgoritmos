
#include <cairomm-1.0/cairomm/context.h>

#include "Vertice.h"

Vertice::Vertice(Pais* pais) {
    this->pais = pais;
    this->posX=0;
    this->posY=0;
}//constructor

Vertice::Vertice() {
}//constructor

void Vertice::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
  
    cr->rectangle(this->posX, this->posY, 20, 20);
    cr->set_source_rgb(2, 0, 0);
    cr->fill();

}//draw

void Vertice::setPosY(int posY) {
    this->posY = posY;
}

int Vertice::getPosY() const {
    return posY;
}

void Vertice::setPosX(int posX) {
    this->posX = posX;
}

int Vertice::getPosX() const {
    return posX;
}//draw

string Vertice::toString() {
    stringstream s;
    s << this->pais->getNombre();
    return s.str();
}//toString
