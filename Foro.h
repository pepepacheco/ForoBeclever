
#ifndef FORO_H
#define FORO_H

#include "Tema.h"
#include "Usuario.h"

using namespace std;

class Foro {
    string nombre;
    vector<Tema> *temas;
    vector<Usuario> *usuarios;
    
    public:
        Foro(string nombre);
        
        //getters
        string getNombre() {return this->nombre;}
        vector<Tema>* getTemas(){return this->temas;}
        vector<Usuario>* getUsuarios() {return this->usuarios;}
        
        int numTemas() {return temas->size();}
        Tema* verTema(int numTema) {return &(temas->at(numTema));}
        Usuario* nuevoUsuario(string nombre, string alias, string clave);
        Usuario* usuarioPorNombre(string nombre);
        Tema* nuevoTema(string denominacion);
        vector<Tema> *buscarTemas(string termino);
        
        ~Foro(){}               
};

#endif 

