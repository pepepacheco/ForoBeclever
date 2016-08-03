#include "Hilo.h"
#include "Mensaje.h"

using namespace std;

Mensaje* Hilo::nuevoMensaje(string contenido, Usuario *usuario){
    Mensaje *mensaje = new Mensaje(contenido, usuario);
    this->mensajes->push_back(*mensaje);
    
    return mensaje;   
}

vector<Mensaje>* Hilo::buscarMensajes(string termino) {
    vector<Mensaje> *resultado = new vector<Mensaje>;
    for (int i = 0; i < this->mensajes->size(); i++) {
        if (this->mensajes->at(i).getContenido().find(termino) != -1)
            resultado->push_back(mensajes->at(i));
    }  
    return resultado;    
}