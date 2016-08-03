#include "Tema.h"
#include "Hilo.h"
#include "Mensaje.h"

using namespace std;

Hilo* Tema::nuevoHilo(string titulo, Mensaje *mensajeInicial){
    Hilo *hilo = new Hilo(titulo);
    hilo->getMensajes()->push_back(*mensajeInicial);
    this->hilos->push_back(*hilo);
    
    return hilo;
}

int Tema::numeroMensajes() {
    int numeroMensajesTotal;
    for (int i = 0; i < hilos->size(); i++) {
        numeroMensajesTotal += hilos->at(i).numMensajes();
    }
    return numeroMensajesTotal;
}

vector<Hilo>* Tema::buscarHilos(string termino) {
    vector<Hilo> *resultado = new vector<Hilo>;
    for (int i = 0; i < this->hilos->size(); i++) {
        if (this->hilos->at(i).getTitulo().find(termino) != -1)
            resultado->push_back(hilos->at(i));
    }  
    return resultado;
}
