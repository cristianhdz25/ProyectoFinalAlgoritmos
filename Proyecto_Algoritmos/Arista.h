#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"
#include <pthread.h>
#include <unistd.h>
#include<stdlib.h>
#include <stdlib.h>    
#include <time.h> 

class Arista {
public:
    Arista(Vertice* v1, Vertice* v2, int horaSalida, int horaLlegada, int peso);
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    void setPeso(int peso);
    int getPeso() const;
    void setHoraLlegada(int horaLlegada);
    int getHoraLlegada() const;
    void setHoraSalida(int horaSalida);
    int getHoraSalida() const;
    void setPosY1(int posY1);
    int getPosY1() const;
    void setPosX1(int posX1);
    int getPosX1() const;
private:
    int posX,posY,posX1,posY1, horaSalida, horaLlegada, peso;
};

#endif /* ARISTA_H */