#ifndef MENSAJE_H
#define MENSAJE_H

#include "Usuario.h"
#include "Fecha.h"

using namespace std;

class Mensaje {
    Fecha *fecha;
    string contenido;
    Usuario *autor;
    public:
        Mensaje(string contenido, Usuario *autor):contenido(contenido), autor(autor){fecha = new Fecha();}
        Usuario *verAutor();
        ~Mensaje(){};
};

#endif

