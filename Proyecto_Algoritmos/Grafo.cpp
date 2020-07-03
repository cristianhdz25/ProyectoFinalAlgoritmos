#include "Grafo.h"

Grafo::Grafo() {
    this->constposX = 5;
    this->constposY = 5;
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
    for (int i = 0; i < vertice1->listaVertices.size(); i++) {
        if (vertice1->listaVertices.at(i)->pais->getNombre() == vertice2->pais->getNombre()) {
            return true;
        }//if
    }//for
    return false;
}//existe arista

bool Grafo::exist(Vertice* vertice) {
    if (this->grafo.empty()) {
        
    }//if
    for (int i = 0; i < this->grafo.size(); i++) {
        if (this->grafo.at(i)->pais->getNombre() == vertice->pais->getNombre()) {
            return true;
        }//if
    }//for
    return false;
}//exist

void Grafo::agregarAristaYPeso(Vertice* vertice1, Vertice* vertice2, int horaSalida, int horaLlegada, int peso) {
    if (!this->exist(vertice1) && !this->exist(vertice2)) {
        
        vertice1->setPosX(this->constposX += 60);
        vertice1->setPosY(this->constposY+=60);

        vertice2->setPosX(this->constposX+=20);
        vertice2->setPosY(this->constposY += 60);

        vertice1->listaVertices.push_back(vertice2);
        vertice1->listaPesos.push_back(peso);
        this->grafo.push_back(vertice1);
        this->grafo.push_back(vertice2);
        this->aristas.push_back(new Arista(this->grafo.at(this->getPosicion(vertice1))
                , this->grafo.at(this->getPosicion(vertice2)), horaSalida, horaLlegada, peso));

    } else if (this->exist(vertice1) && this->exist(vertice2)
            && !this->existeArista(this->grafo.at(this->getPosicion(vertice1)), vertice2)) {
        
        this->grafo.at(this->getPosicion(vertice1))->listaVertices.push_back(vertice2);
        this->grafo.at(this->getPosicion(vertice1))->listaPesos.push_back(peso);
        this->aristas.push_back(new Arista(this->grafo.at(this->getPosicion(vertice1))
                , this->grafo.at(this->getPosicion(vertice2)), horaSalida, horaLlegada, peso));

    } else if (!this->exist(vertice1) && this->exist(vertice2)) {
        
        vertice1->setPosX(this->constposX += 40);
        vertice1->setPosY(this->constposY);

       
        vertice1->listaVertices.push_back(this->grafo.at(this->getPosicion(vertice2)));
        vertice1->listaPesos.push_back(peso);
        this->grafo.push_back(vertice1);
        this->aristas.push_back(new Arista(this->grafo.at(this->getPosicion(vertice1))
                , this->grafo.at(this->getPosicion(vertice2)), horaSalida, horaLlegada, peso));

    } else if (this->exist(vertice1) && !this->exist(vertice2)) {
        
        vertice2->setPosX(this->constposX += 60);
        vertice2->setPosY(this->constposY += 60);

      
        this->grafo.at(this->getPosicion(vertice1))->listaVertices.push_back(vertice2);
        this->grafo.at(this->getPosicion(vertice1))->listaPesos.push_back(peso);
        this->grafo.push_back(vertice2);
        this->aristas.push_back(new Arista(this->grafo.at(this->getPosicion(vertice1))
                , this->grafo.at(this->getPosicion(vertice2)), horaSalida, horaLlegada, peso));
    }//else if
    
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
        for (int j = 0; j < this->grafo.at(i)->listaVertices.size(); j++) {
            s << this->grafo.at(i)->listaVertices.at(j)->pais->getNombre() << " ";
        }//for
        s << endl;
    }//for
    return s.str();
}

void Grafo::setAristas(vector<Arista*> aristas) {
    this->aristas = aristas;
}

vector<Arista*> Grafo::getAristas() const {
    return aristas;
}//toString

Grafo * Grafo::instance = 0;