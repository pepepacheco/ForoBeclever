
#ifndef FORO_H
#define FORO_H

#include "Tema.h"
#include "Usuario.h"
#include <vector>
using namespace std;

class Foro {
    string nombre;
    vector<Tema> *temas;
    vector<Usuario> *usuarios;
    public:
        Foro(string nombre);
        string getNombre() {return this->nombre;}
        vector<Tema>* getTemas(){return this->temas;}
        vector<Usuario>* getUsuarios() {return this->usuarios;}
        int numTemas() {return temas->size();}
        Tema* verTema(int numTema) {return &(temas->at(numTema));}
        Usuario* nuevoUsuario(string nombre, string alias, string clave);
        Usuario* usuarioPorAlias(string alias);
        Tema* nuevoTema(string denominacion);
        ~Foro(){}               
        void verUsuarios(); //comentar (testeo)
};

#endif 

