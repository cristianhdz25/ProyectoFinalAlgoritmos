#ifndef ITINERARIO_H
#define ITINERARIO_H
#include <string>

using namespace std;

class Itinerario {
public:
    Itinerario(string origen, string destino, string hora);
    virtual ~Itinerario();
    void setHora(string hora);
    string getHora() const;
    void setOrigen(string origen);
    string getOrigen() const;
    void setDestino(string destino);
    string getDestino() const;
    string toString();
private:
    string origen, destino, hora;
};

#endif /* ITINERARIO_H */

