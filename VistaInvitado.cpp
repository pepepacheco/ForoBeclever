#include "VistaInvitado.h"
#include "Vista.h"
#include <iostream>

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

using namespace std;

VistaInvitado::VistaInvitado(Foro *f) {
    foro = f;
    vistaForo(new Usuario("invitado", "invitado", "invitado"));
}

void VistaInvitado::vistaForo(Usuario *u) {
    int resultado;
    cout << "\nBIENVENIDO " << u->getNombre() << " al Foro: \"" << foro->getNombre() << "\"" << endl
    << "====================================================\n" << endl;

    while (true) {       
        cout << "1: Ver temas" << endl
        << "2: Buscar temas" << endl        
        << "3: Volver al menu principal" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                verTemas(u);
                break;
            case 2:
                if (system("CLS")) system("clear");
                buscarTemas(u);
                break;
            case 3:
                delete u;
                if (system("CLS")) system("clear");
                new Vista(this->foro);
                break;
            default:
                continue;       
        }
    break;
    }
}

void VistaInvitado::verTemas(Usuario* u) {
    int numeroTema;
    Tema *t;
    cout << "\nTemas" << endl
    << "====================================================\n" << endl;   
    
    if (foro->numTemas() > 0) {
        for (int i = 0; i < foro->numTemas(); i++) {
            cout << i + 1 << "-> " << foro->verTema(i)->getDenominacion() << endl;
        }

        do {
            cout << "\nIntroduce el numero de tema para acceder a el" << endl
                    << "0 para volver al menu principal" << endl;
            cin >> numeroTema;
        }
        while (!(numeroTema >= 0 && numeroTema <= foro->numTemas()));

        if (numeroTema == 0) {
            if (system("CLS")) system("clear");
            vistaForo(u);
        }
        else {
            t = foro->verTema(numeroTema - 1);
            if (system("CLS")) system("clear");
            menuTema(u, t);
        }        
    }
    else
        cout << "0" << endl;
    
    if (system("CLS")) system("clear");
    vistaForo(u);

}

void VistaInvitado::buscarTemas(Usuario* u) {
    string criterio;
    int numeroTema;
    Tema *t;
    
    cout << "\nIntroduzca un criterio de busqueda:" << endl;
    cin >> criterio;
    
    vector<Tema> *resultado = foro->buscarTemas(criterio);
    
    cout << "\n----- Temas encontrados -----\n" << endl;
    for (int i = 0; i < resultado->size(); i++) {
        cout << i+1 << "-> " << resultado->at(i).getDenominacion() << endl;
    }
    
    do {
        cout << "\nIntroduce el numero de tema para acceder a el" << endl
                << "0 para volver al menu de temas" << endl;
        cin >> numeroTema;
    } while (!(numeroTema >= 0 && numeroTema <= resultado->size()));

    if (numeroTema == 0) {
        if (system("CLS")) system("clear");
        vistaForo(u);
    }
    else {
        t = &(resultado->at(numeroTema - 1));
        if (system("CLS")) system("clear");
        menuTema(u, t);
    }     
}

void VistaInvitado::menuTema(Usuario*u, Tema *t) {
    int resultado;
    
    cout << "\nBIENVENIDO " << u->getNombre() << " al Tema: \"" << t->getDenominacion() << "\"" << endl
    << "====================================================\n" << endl;
    
    while (true) {       
        cout << "1: Ver hilos" << endl
        << "2: Buscar hilo" << endl
        << "3: Volver al menu del Foro" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                verHilos(u, t);
                break;
            case 2:
                if (system("CLS")) system("clear");
                buscarHilos(u, t);
                break;
            case 3:
                if (system("CLS")) system("clear");
                vistaForo(u);
                break;
            default:
                continue;      
        }
    break;
    }
}

void VistaInvitado::verHilos(Usuario* u, Tema* t) {
    int numeroHilo;
    Hilo *h;
    cout << "\nHilos" << endl
    << "====================================================\n" << endl;  

    if (t->numeroHilo() > 0) {
        for (int i = 0; i < t->numeroHilo(); i++) {
            cout << "Hilo " << i + 1 << "-> " << t->verHilo(i)->getTitulo() << endl
            << t->verHilo(i)->getMensajes()->at(0).getContenido() << endl;
        }

        do {
            cout << "\nIntroduce el numero de hilo para acceder a el" << endl
                    << "0 para volver al menu de temas" << endl;
            cin >> numeroHilo;
        } while (!(numeroHilo >= 0 && numeroHilo <= t->numeroHilo()));

        if (numeroHilo == 0) {
            if (system("CLS")) system("clear");
            menuTema(u, t);
        }
        else {
            h = t->verHilo(numeroHilo - 1);
            if (system("CLS")) system("clear");
            menuHilo(u, t, h);
        }
    }
    else
        cout << "0" << endl;
    
    if (system("CLS")) system("clear");
    menuTema(u, t);

}

void VistaInvitado::buscarHilos(Usuario* u, Tema* t) {
    string criterio;
    int numeroHilo;
    Hilo *h;
    
    cout << "\nIntroduzca un criterio de busqueda:" << endl;
    cin >> criterio;
    
    vector<Hilo> *resultado = t->buscarHilos(criterio);
    
    cout << "\n----- Hilos encontrados -----\n" << endl;
    for (int i = 0; i < resultado->size(); i++) {
        cout << i+1 << "-> " << resultado->at(i).getTitulo() << endl;
    }
    
    do {
        cout << "\nIntroduce el numero de hilo para acceder a el" << endl
                << "0 para volver al menu de temas" << endl;
        cin >> numeroHilo;
    } while (!(numeroHilo >= 0 && numeroHilo <= resultado->size()));

    if (numeroHilo == 0) {
        if (system("CLS")) system("clear");
        menuTema(u, t);
    }
    else {
        h = &(resultado->at(numeroHilo - 1));
        if (system("CLS")) system("clear");
        menuHilo(u, t, h);
    }        
}

void VistaInvitado::menuHilo(Usuario* u, Tema *t, Hilo* h) {
    int resultado;

    cout << "\nBIENVENIDO " << u->getNombre() << " al Hilo: \"" << h->getTitulo() << "\"" << endl
    << "====================================================\n" << endl;
    
    while (true) {       
        cout << "1: Ver mensajes" << endl
        << "2: Buscar mensajes" << endl
        << "3: Volver al menu de Temas " << endl;     
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                verMensajes(u, t, h);
                break;
            case 2:
                if (system("CLS")) system("clear");
                buscarMensajes(u, t, h);
                break;
            case 3:
                if (system("CLS")) system("clear");
                menuTema(u, t);
                break;
            default:
                continue;      
        }
    break;
    }
}

void VistaInvitado::verMensajes(Usuario* u, Tema* t, Hilo* h) {
    char caracter = ' ';

    cout << "\nMensajes" << endl
    << "====================================================\n" << endl;    
    
    for (int i = 0; i < h->numMensajes(); i++) {
        cout << i+1 << "-> " << "Autor: " << h->verMensaje(i).verAutor()->getAlias() << " | Fecha: " << h->verMensaje(i).getFecha()->getFecha() << endl
        << "Mensaje: " << endl << h->verMensaje(i).getContenido() << endl << endl;
    }
    
    do {
        cout << "\nPulse una tecla para regresar" << endl;
        cin >> caracter;
    }
    while (caracter == ' ');
    
    if (system("CLS")) system("clear");
    menuHilo(u, t, h);
}

void VistaInvitado::buscarMensajes(Usuario* u, Tema* t, Hilo* h) {
    string criterio;
    char caracter = ' ';
    
    cout << "\nIntroduzca un criterio de busqueda:" << endl;
    cin >> criterio;
    
    vector<Mensaje> *resultado = h->buscarMensajes(criterio);
    
    cout << "\n----- Mensajes encontrados -----\n" << endl;
    for (int i = 0; i < resultado->size(); i++) {
        cout << i+1 << "-> " << "Autor: " << h->verMensaje(i).verAutor()->getAlias() << " | Fecha: " << h->verMensaje(i).getFecha()->getFecha() << endl
        << "Mensaje: " << endl << h->verMensaje(i).getContenido() << endl << endl;
    } 
    
    do {
        cout << "\nPulse una tecla para regresar" << endl;
        cin >> caracter;
    }
    while (caracter == ' ');
    
    if (system("CLS")) system("clear");
    menuHilo(u, t, h);    
}