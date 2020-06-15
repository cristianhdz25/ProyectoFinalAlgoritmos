#ifndef ITINERARIO_H
#define ITINERARIO_H
#include <string>

using namespace std;

class Itinerario {
public:
    Itinerario(string ruta, string hora);
    virtual ~Itinerario();
    void setHora(string hora);
    string getHora() const;
    void setRuta(string ruta);
    string getRuta() const;
    string toString();
private:
    string ruta;
    string hora;
};

#endif /* ITINERARIO_H */

