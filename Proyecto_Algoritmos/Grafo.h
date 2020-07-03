#ifndef GRAFO_H
#define GRAFO_H

#include "Vertice.h"
#include "Arista.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Grafo {
public:
    Grafo();
    vector<Vertice*> grafo;
    vector<Arista*> aristas;
    static Grafo* getInstance(); //constructor singleton
    int getPosicion(Vertice* vertice);
    void agregarAristaYPeso(Vertice* vertice1, Vertice* vertice2, int horaSalida, int horaLlegada, int peso);
    bool existeArista(Vertice* vertice1, Vertice* vertice2);
    bool exist(Vertice* vertice);
    void moverVertices(int posicion);
    string mostrarVertices(int posicion);
    void draw(const Cairo::RefPtr<Cairo::Context>& cr);
    string toString();
    void setAristas(vector<Arista*> aristas);
    vector<Arista*> getAristas() const;
    

private:
    static Grafo* instance;
    int constposX, constposY;
};

#endif /* GRAFO_H */