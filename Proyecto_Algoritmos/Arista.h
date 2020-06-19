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
    Arista(Vertice *v1, Vertice *v2);
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
private:
    int posX,posY,posX1,posY1;
};

#endif /* ARISTA_H */

