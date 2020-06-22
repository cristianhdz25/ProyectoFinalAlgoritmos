#ifndef ITINERARIO_H
#define ITINERARIO_H
#include "Avion.h"
#include "Pais.h"
#include <string>

using namespace std;

class Itinerario {
public:
    Itinerario(Pais* origen, Pais* destino, string hora,Avion * avion);
    virtual ~Itinerario();
    void setHora(string hora);
    string getHora() const;
    void setOrigen(Pais* origen);
    Pais* getOrigen() const;
    void setDestino(Pais* destino);
    Pais* getDestino() const;
    string toString();
    string toString2();
    void setAvion(Avion* avion);
    Avion* getAvion() const;
private:
    Pais* origen;
    Pais * destino;
    string hora;
    Avion * avion;
};

#endif /* ITINERARIO_H */

