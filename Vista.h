
#ifndef VISTA_H
#define VISTA_H
#include "Foro.h"

class Vista {
    Foro *foro; 
    public:
        Vista();
        void mensajeInicial();
        void registro();
        void login();
        void vistaForo(Usuario *u);
};

#endif 

