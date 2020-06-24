#include "Drawing.h"

Drawing::Drawing() {
    this->set_size_request(800, 800);
    this->aristas = new vector<Arista*>();
    this->vertice = new Vertice();
    this->grafo = Grafo::getInstance();
    cout<<"Size constructor drawing "<<this->grafo->grafo.size()<<endl;
    initPosiciones();
}//constructor

bool Drawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    for (int i = 0; i < this->grafo->grafo.size(); i++) {
        this->grafo->grafo.at(i)->draw(cr);
        
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