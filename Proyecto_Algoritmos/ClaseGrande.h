
#ifndef CLASEGRANDE_H
#define CLASEGRANDE_H
#include <list>
#include <queue> 
#include "Aerolinea.h"

using namespace std;

class ClaseGrande {
public:
    ClaseGrande();
    static ClaseGrande* getInstance();//constructor singleton
    virtual ~ClaseGrande();
    
    void setAerolineas(list<Aerolinea*> aerolineas);
    list<Aerolinea*> getAerolineas();
    void arriba();
    void abajo();

    string mostrarAerolinea();
    string mostrarItinerario();
    string mostrarItinerarios();
    void subirItinerario();
    
   
    void arribaItinerario();

private:
    list<Aerolinea*> aerolineas;
    static ClaseGrande* instance;
};

#endif /* CLASEGRANDE_H */

