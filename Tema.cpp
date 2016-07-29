#include "Tema.h"
#include "Hilo.h"
#include "Mensaje.h"

using namespace std;

Hilo* Tema::nuevoHilo(string titulo, Mensaje *mensajeInicial){
    Hilo *hilo = new Hilo(titulo);
    Mensaje *mensaje = new Mensaje(*mensajeInicial);
    
    return hilo;
}

vector<Hilo>* Tema::buscarHilos(string termino) {
    vector<Hilo> *resultado = new vector<Hilo>;
    for (int i = 0; i < this->hilos.size(); i++) {
        if (hilos.at(i).getTitulo().find(termino) != -1)
            resultado->push_back(hilos.at(i));
    }  
    return resultado;
}
