
#ifndef CLASEGRANDE_H
#define CLASEGRANDE_H
#include <list>
#include <queue> 
#include "string"
#include "Aerolinea.h"
#include "AerolineaBusiness.h"
#include "Client.h"
#include "Compra.h"

using namespace std;

class ClaseGrande {
public:
    
    static ClaseGrande* getInstance(); //constructor singleton
    virtual ~ClaseGrande();

    string mostrarAerolinea();
    string mostrarItinerario();
    string mostrarItinerarios();
    void subirItinerario();
    void arribaItinerario();
    void registrarAerolinea(Aerolinea* aerolinea);
    void registrarItinerario(Itinerario* itinerario);
    void setAerolineas(list<Aerolinea*>* aerolineas);
    list<Aerolinea*>* getAerolineas();
    void arriba();
    void abajo();
    void registrarCliente(Client* client);
    Client* searchClient(string passport, string password);
    void moverVertices();
    void mostrarVertices();
    void setUsuarioActual(Client* usuarioActual);
    Client* getUsuarioActual() const;
    void registrarCompra(); 
private:
    ClaseGrande();
    list<Aerolinea*>* aerolineas;
    AerolineaBusiness* aerolineaBusiness;
    static ClaseGrande* instance;
    vector<Client*>* listaCliente;
    Grafo* grafo;
    Client* usuarioActual;
    vector<Compra*>* listaCompra;
    Compra* compra;
};

#endif /* CLASEGRANDE_H */

