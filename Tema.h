#ifndef TEMA_H
#define TEMA_H

#include "Hilo.h"
using namespace std;

class Tema {
    vector<Hilo> *hilos;
    string denominacion;
    
    public:
        Tema(string denominacion);
        string getDenominacion() {return this->denominacion;}
        int numeroHilo() {return this->hilos->size();}
        Hilo *verHilo(int numHilo) {return &(this->hilos->at(numHilo));}
        Hilo *nuevoHilo(string titulo, Mensaje *mensajeInicial);
        int numeroMensajes(Hilo *hilo){return hilo->numMensajes();}
        vector<Hilo> *buscarHilos(string termino);
        ~Tema(){}
};

#endif

