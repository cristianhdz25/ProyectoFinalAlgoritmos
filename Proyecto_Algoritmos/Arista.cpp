#include <cairomm-1.0/cairomm/context.h>
#include "Arista.h"
#include "Vertice.h"

Arista::Arista(Vertice *v1, Vertice *v2, int horaSalida, int horaLlegada, int peso) {
    this->posX = v1->getPosX();
    this->posY = v1->getPosY();
    this->posX1 = v2->getPosX();
    this->posY1 = v2->getPosY();
    this->horaSalida=horaSalida;
    this->horaLlegada=horaLlegada;
    this->peso=peso;

}

void Arista::draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    cr->set_line_width(1);
    cr->set_source_rgb(1, 1, 1);
    cr->move_to(this->posX, this->posY);
    cr->line_to(this->posX1, this->posY1);
    cr->stroke();
}

void Arista::setPeso(int peso) {
    this->peso = peso;
}

int Arista::getPeso() const {
    return peso;
}

void Arista::setHoraLlegada(int horaLlegada) {
    this->horaLlegada = horaLlegada;
}

int Arista::getHoraLlegada() const {
    return horaLlegada;
}

void Arista::setHoraSalida(int horaSalida) {
    this->horaSalida = horaSalida;
}

int Arista::getHoraSalida() const {
    return horaSalida;
}

void Arista::setPosY1(int posY1) {
    this->posY1 = posY1;
}

int Arista::getPosY1() const {
    return posY1;
}

void Arista::setPosX1(int posX1) {
    this->posX1 = posX1;
}

int Arista::getPosX1() const {
    return posX1;
}