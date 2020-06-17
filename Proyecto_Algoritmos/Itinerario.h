#ifndef ITINERARIO_H
#define ITINERARIO_H
#include "Avion.h"
#include <string>

using namespace std;

class Itinerario {
public:
    Itinerario(string origen, string destino, string hora,Avion * avion);
    virtual ~Itinerario();
    void setHora(string hora);
    string getHora() const;
    void setOrigen(string origen);
    string getOrigen() const;
    void setDestino(string destino);
    string getDestino() const;
    string toString();
    void setAvion(Avion* avion);
    Avion* getAvion() const;
private:
    string origen, destino, hora;
    Avion * avion;
};

#endif /* ITINERARIO_H */

