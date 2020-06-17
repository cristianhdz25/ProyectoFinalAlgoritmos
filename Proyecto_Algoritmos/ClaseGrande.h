
#ifndef CLASEGRANDE_H
#define CLASEGRANDE_H
#include <list>
#include <queue> 
#include "Aerolinea.h"
#include "AerolineaBusiness.h"

using namespace std;

class ClaseGrande {
public:
    ClaseGrande();
    static ClaseGrande* getInstance();//constructor singleton
    virtual ~ClaseGrande();
    
    string mostrarAerolinea();
    string mostrarItinerario();
    string mostrarItinerarios();
    void subirItinerario();
    void arribaItinerario();
    void registrarAerolinea(Aerolinea* aerolinea);
    void registrarItinerario(Itinerario* itinerario);
    void setAerolineas(list<Aerolinea*> aerolineas);
    list<Aerolinea*> getAerolineas();
    void arriba();
    void abajo();
    
private:
    list<Aerolinea*> aerolineas;
    AerolineaBusiness* aerolineaBusiness;
    static ClaseGrande* instance;
};

#endif /* CLASEGRANDE_H */

