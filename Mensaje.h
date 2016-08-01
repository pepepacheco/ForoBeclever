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
        Fecha *getFecha(){return this->fecha;}
        string getContenido() {return this->contenido;}
        Usuario *verAutor(){return this->autor;}
        ~Mensaje(){};
};

#endif

