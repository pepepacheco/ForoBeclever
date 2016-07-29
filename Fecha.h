#ifndef FECHA_H
#define FECHA_H

#include "Hora.h"

using namespace std;

class Fecha {
    int dia, mes, anio;
    Hora *hora;
    
    public:
        Fecha();
        string getFecha();
        ~Fecha(){};   
};

#endif

