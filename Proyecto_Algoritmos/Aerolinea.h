#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <string>
#include <queue>

#include "Itinerario.h"

using namespace std;
//Estoy probando branch Colochos
//Esto tiene que aparecer en el master
//probando branch Carlos
//segunda prueba Carlos
class Aerolinea {
public:
    Aerolinea(string nombre);
    virtual ~Aerolinea();

    void setItinerarios(queue<Itinerario*> itinerarios);
    queue<Itinerario*> getItinerarios();

    void subirItinerario();

    void setNombre(string nombre);

    string getNombre() const;
    string mostrarItinerario();
    string mostrarItinerarios();

    string toString();
private:
    string nombre;
    queue<Itinerario*> itinerarios;
};

#endif /* AEROLINEA_H */

