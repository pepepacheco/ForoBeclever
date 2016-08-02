#ifndef VISTA_H
#define VISTA_H

#include "Foro.h"

class Vista {
    Foro *foro; 
    
    public:
        Vista(Foro *f);
        void mensajeInicial();
        void registro();
        void login();
        void vistaForo(Usuario *u);
        void crearTema(Usuario *u);
        void verTemas(Usuario *u);
        void menuUsuario(Usuario *u);
        void menuCambiarNombre(Usuario *u);
        void menuCambiarAlias(Usuario *u);
        void menuCambiarClave(Usuario *u);
        void buscarTemas(Usuario *u);
        void menuTema(Usuario*u, Tema *t);
        void crearHilo(Usuario *u, Tema *t);
        void verHilos(Usuario *u, Tema *t);
        void buscarHilos(Usuario *u, Tema *t);
        void menuHilo(Usuario *u, Tema *t, Hilo *h);
        void crearMensaje(Usuario *u, Tema *t, Hilo *h);
        void verMensajes(Usuario *u, Tema *t, Hilo *h);
        void buscarMensajes(Usuario *u, Tema *t, Hilo *h);
        ~Vista(){}
};

#endif 