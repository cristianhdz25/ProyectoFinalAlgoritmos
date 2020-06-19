
#ifndef VERTICE_H
#define VERTICE_H

#include <vector>
#include <gtkmm.h>
#include "Pais.h"
#include <pthread.h>
#include <unistd.h>
#include<stdlib.h>
#include <stdlib.h>    
#include <time.h>     
#include <string>
using namespace std;

class Vertice {
public:
    Vertice(Pais* pais);
    Vertice();
    Pais* pais;
    vector<Vertice*> listaAristas;
    vector<int> listaPesos;
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    void setPosY(int posY);
    int getPosY() const;
    void setPosX(int posX);
    int getPosX() const;
    string toString();
private:
    int posX=0;
    int posY=0;
};

#endif /* VERTICE_H */

