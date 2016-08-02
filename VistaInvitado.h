#ifndef VISTAINVITADO_H
#define VISTAINVITADO_H

#include "Foro.h"

class VistaInvitado{
    Foro *foro; 
    
    public:
        VistaInvitado(Foro *f);
        void vistaForo(Usuario *u);
        void verTemas(Usuario *u);
        void buscarTemas(Usuario *u);
        void menuTema(Usuario*u, Tema *t);
        void verHilos(Usuario *u, Tema *t);
        void buscarHilos(Usuario *u, Tema *t);
        void menuHilo(Usuario *u, Tema *t, Hilo *h);
        void verMensajes(Usuario *u, Tema *t, Hilo *h);
        void buscarMensajes(Usuario *u, Tema *t, Hilo *h);
        ~VistaInvitado(){}
};

#endif 

