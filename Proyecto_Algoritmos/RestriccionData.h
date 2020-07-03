#ifndef RESTRICCIONDATA_H
#define RESTRICCIONDATA_H

#include "Pais.h"
#include <vector>

class RestriccionData {
public:
    static RestriccionData* getInstance();
    RestriccionData();

    void initRestriccion();
    void registrarRestricciones(Pais* pais);
    void setRegistroRestricciones(vector<Pais*> registroRestricciones);
    vector<Pais*> getRegistroRestricciones() const;
    void anadirRestriccion(Pais* pais, int i);
    int existePais(string nombre);
private:
    vector<Pais*> registroRestricciones;
    
    
    static RestriccionData* instance;
};


#endif /* RESTRICCIONDATA_H */

