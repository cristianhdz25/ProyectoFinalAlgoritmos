
#ifndef CLASEGRANDE_H
#define CLASEGRANDE_H
#include <list>
#include <queue> 
#include "Aerolinea.h"
#include "AerolineaBusiness.h"
#include "Client.h"

using namespace std;

class ClaseGrande {
public:
    ClaseGrande();
    static ClaseGrande* getInstance(); //constructor singleton
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
    void registrarCliente(Client* client);
    void moverVertices();
    void mostrarVertices();
private:
    list<Aerolinea*> aerolineas;
    AerolineaBusiness* aerolineaBusiness;
    static ClaseGrande* instance;
    vector<Client*> listaCliente;
    Grafo* grafo;
};

#endif /* CLASEGRANDE_H */

