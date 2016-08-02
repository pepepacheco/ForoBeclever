#include "Foro.h"
#include "Usuario.h"
#include "Tema.h"

using namespace std;

Foro::Foro(string nombre) {
    this->nombre = nombre;
    temas = new vector<Tema>;
    usuarios = new vector<Usuario>;
}

Usuario* Foro::nuevoUsuario(string nombre, string alias, string clave) {
    Usuario *u = new Usuario(nombre, alias, clave);
    this->usuarios->push_back(*u);    
    return u;
}

Usuario* Foro::usuarioPorNombre(string nombre) {
    for (int i = 0; i < usuarios->size(); i++) {
        if (usuarios->at(i).getNombre().compare(nombre) == 0)
            return &(usuarios->at(i));
    }
    return NULL;    
}

Tema* Foro::nuevoTema(string denominacion) {
    Tema *t = new Tema(denominacion);
    this->temas->push_back(*t);
    return t;
}

vector<Tema>* Foro::buscarTemas(string termino) {
    vector<Tema> *resultado = new vector<Tema>;
    for (int i = 0; i < this->temas->size(); i++) {
        if (this->temas->at(i).getDenominacion().find(termino) != -1)
            resultado->push_back(temas->at(i));
    }  
    return resultado;    
}