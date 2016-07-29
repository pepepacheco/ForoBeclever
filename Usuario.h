#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
    string nombre, alias, clave;
    public:
        Usuario(string nombre, string alias, string clave) : nombre(nombre), alias(alias), clave(clave) {}
        string getNombre() {return this->nombre;}
        string getAlias() {return this->alias;}
        string getPass() {return this->clave;}
        bool validarClave(string clave); 
        void cambiarClave(string clave){this->clave = clave;}
        ~Usuario(){};
};

#endif

