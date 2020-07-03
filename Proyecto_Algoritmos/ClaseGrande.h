
#ifndef CLASEGRANDE_H
#define CLASEGRANDE_H
#include <list>
#include <queue> 
#include "string"
#include "Aerolinea.h"
#include "AerolineaBusiness.h"
#include "Client.h"
#include "Compra.h"
#include "RestriccionData.h"

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
    bool comprobarRestriccionDelQueCompraElTiquete();
    Client* getUsuarioActual() const;
    void registrarCompra();
    void asignarItinerario();
    void usuarioReset();
    void agregarItinerario(Itinerario* itinerario);
    void agregarItinerarioActualizado(Itinerario* itinerario);
    bool existe(Aerolinea* aerolinea);
private:
    ClaseGrande();
    list<Aerolinea*>* aerolineas;
    AerolineaBusiness* aerolineaBusiness;
    static ClaseGrande* instance;
    vector<Client*>* listaCliente;
    Grafo* grafo;
    Client* usuarioActual = NULL;
    vector<Compra*>* listaCompra;
    Compra* compra;
    Pais* pais1;
    vector<Pais*> tempRestriccion;
    RestriccionData* restriccionData;
};

#endif /* CLASEGRANDE_H */

