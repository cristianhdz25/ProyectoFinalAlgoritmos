#ifndef ITINERARIO_H
#define ITINERARIO_H
#include "Avion.h"
#include "Pais.h"
#include <string>

using namespace std;

class Itinerario {
public:
    Itinerario(Pais* origen, Pais* destino, int horaSalida, int horaLlegada,Avion * avion);
    virtual ~Itinerario();
    void setOrigen(Pais* origen);
    Pais* getOrigen() const;
    void setDestino(Pais* destino);
    Pais* getDestino() const;
    string toString();
    string toString2();
    void setAvion(Avion* avion);
    Avion* getAvion() const;
    void setHoraSalida(int horaSalida);
    int getHoraSalida() const;
    void setHoraLlegada(int horaLlegada);
    int getHoraLlegada() const;
    
private:
    Pais* origen;
    Pais * destino;
    int horaSalida;
    int horaLlegada;
    Avion * avion;
};

#endif /* ITINERARIO_H */

