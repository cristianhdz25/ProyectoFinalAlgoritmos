#include "Grafo.h"

Grafo::Grafo() {
}

Grafo* Grafo::getInstance() {
    if (instance == 0) {
        instance = new Grafo();
    }//if
    return instance;
}//getInstance

int Grafo::getPosicion(Vertice* vertice) {
    for (int i = 0; i < this->grafo.size(); i++) {
        if (vertice->pais->getNombre() == this->grafo.at(i)->pais->getNombre())
            return i;
    }//for i
    return -1;
}//getPosicion

bool Grafo::existeArista(Vertice* vertice1, Vertice* vertice2) {
    for (int i = 0; i < vertice1->listaAristas.size(); i++) {
        if (vertice1->listaAristas.at(i)->pais->getNombre() == vertice2->pais->getNombre()) {
            return true;
        }//if
    }//for
    return false;
}//existe arista

bool Grafo::exist(Vertice* vertice) {
    if (this->grafo.empty()) {
        cout << "no existen vertices" << endl;
    }//if
    for (int i = 0; i < this->grafo.size(); i++) {
        if (this->grafo.at(i)->pais->getNombre() == vertice->pais->getNombre()) {
            return true;
        }//if
    }//for
    return false;
}//exist

void Grafo::agregarAristaYPeso(Vertice* vertice1, Vertice* vertice2, int peso) {
    if (!this->exist(vertice1) && !this->exist(vertice2)) {
        vertice1->listaAristas.push_back(vertice2);
        vertice1->listaPesos.push_back(peso);
        this->grafo.push_back(vertice1);
        this->grafo.push_back(vertice2);

    } else if (this->exist(vertice1) && this->exist(vertice2)
            && !this->existeArista(this->grafo.at(this->getPosicion(vertice1)), vertice2)) {
        this->grafo.at(this->getPosicion(vertice1))->listaAristas.push_back(vertice2);
        this->grafo.at(this->getPosicion(vertice1))->listaPesos.push_back(peso);

    } else if (!this->exist(vertice1) && this->exist(vertice2)) {
        vertice1->listaAristas.push_back(this->grafo.at(this->getPosicion(vertice2)));
        vertice1->listaPesos.push_back(peso);
        this->grafo.push_back(vertice1);

    } else if (this->exist(vertice1) && !this->exist(vertice2)) {
        this->grafo.at(this->getPosicion(vertice1))->listaAristas.push_back(vertice2);
        this->grafo.at(this->getPosicion(vertice1))->listaPesos.push_back(peso);
        this->grafo.push_back(vertice2);

    }//else if
    cout<<this->toString()<<endl;
}//agragarAristaYPeso

string Grafo::mostrarVertices(int posicion) {

    return grafo.at(posicion)->toString();
    
}//mostrarVertices

void Grafo::moverVertices(int posicion) {

    if (posicion < grafo.size()) {

        grafo.at(posicion);
        cout << grafo.at(posicion)->toString() << endl;
        cout << posicion << endl;
    }//if
    if (posicion == grafo.size()) {
        posicion = 0;
    }//if
}//moverVertices

void Grafo::draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    
   

}//draw


string Grafo::toString() {
    stringstream s;
    for (int i = 0; i < this->grafo.size(); i++) {
        s << this->grafo.at(i)->pais->getNombre() << " :";
        for (int j = 0; j < this->grafo.at(i)->listaAristas.size(); j++) {
            s << this->grafo.at(i)->listaAristas.at(j)->pais->getNombre()<<" ";
        }//for
        s<<endl;
    }//for
    return s.str();
}//toString

Grafo * Grafo::instance = 0;