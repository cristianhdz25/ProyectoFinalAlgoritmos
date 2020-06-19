/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arista.cpp
 * Author: carlos
 * 
 * Created on 16 de junio de 2020, 05:16 PM
 */
#include <cairomm-1.0/cairomm/context.h>
#include "Arista.h"
#include "Vertice.h"

Arista::Arista(Vertice * v1, Vertice * v2) {
    this->posX = v1->getPosX()+20;
    this->posY = v1->getPosY()+20;
    this->posX1 = v2->getPosX()+20;
    this->posY1 = v2->getPosY()+20;

}

void Arista::draw(const Cairo::RefPtr<Cairo::Context>& cr) {

    cr->set_line_width(1);
    cr->set_source_rgb(1, 1, 1);
    cr->move_to(this->posX, this->posY);
    cr->line_to(this->posX1, this->posY1);
    cr->stroke();
}

