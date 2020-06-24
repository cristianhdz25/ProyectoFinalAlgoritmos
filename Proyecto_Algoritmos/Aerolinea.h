#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <string>
#include <queue>

#include "Itinerario.h"

using namespace std;
 
class Aerolinea {
public:
    Aerolinea(string nombre);
    virtual ~Aerolinea();
    
    void subirItinerario();
    string mostrarItinerario();
    string mostrarItinerarios();
    void agregarItinerario(Itinerario* itinerario);
    
    void setItinerarios(queue<Itinerario*> itinerarios);
    queue<Itinerario*> getItinerarios();
    void setNombre(string nombre);
    string getNombre() const;
    string toString();
private:
    string nombre;
    queue<Itinerario*> itinerarios;
};

#endif /* AEROLINEA_H */

