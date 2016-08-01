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
/*
Usuario* Foro::usuarioPorAlias(string alias) {
    for (set<Usuario>::iterator it = usuarios->begin(); it != usuarios->end(); it++) {
        if (it._M_const_cast()->getNombre().compare(alias))
            return &(it._M_const_cast().operator *());            
    }
    return NULL;
}
*/

Usuario* Foro::usuarioPorAlias(string alias) {
    for (int i = 0; i < usuarios->size(); i++) {
        if (usuarios->at(i).getAlias().compare(alias))
            return &(usuarios->at(i));
    }
    return NULL;
}

Tema* Foro::nuevoTema(string denominacion) {
    Tema *t = new Tema(denominacion);
    this->temas->push_back(*t);
    return t;
}
/*
void Foro::verUsuarios() {
    for (set<Usuario>::iterator it = usuarios->begin(); it != usuarios->end(); it++) {
        cout << it._M_const_cast()->getNombre() << endl;
    }    
}
*/

void Foro::verUsuarios() {
    //cout << usuarios->size() << endl;
    for (int i = 0; i < usuarios->size(); i++) {
        //cout << (usuarios->at(i)).getNombre() << endl;
    }
}
