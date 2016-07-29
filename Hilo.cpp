#include "Hilo.h"
#include "Mensaje.h"
using namespace std;

Mensaje Hilo::nuevoMensaje(string contenido, Usuario *usuario){
    Mensaje *mensaje = new Mensaje(contenido, usuario);
    this->mensajes.push_back(*mensaje);
    
    return *mensaje;   
}