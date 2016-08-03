#include "Vista.h"
#include "VistaInvitado.h"
#include <iostream>

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

using namespace std;

Vista::Vista(Foro *f) {
    if (f == NULL) 
        foro = new Foro("Beclever");
    else
        foro = f;
    
    mensajeInicial();
}

void Vista::mensajeInicial() {
    int resultado;    
    while (true) {       
        cout << "\nELIGE UNA OPCION" << endl
        << "====================================================" << endl
        << "\n1: Registrarme en el foro" <<endl
        << "2: Identificarme" << endl
        << "3: Acceder como invitado " << endl;
        cin >> resultado;       
        switch (resultado) {
            case 1:
            if (system("CLS")) system("clear");
                registro();
                break;
            case 2:
                if (system("CLS")) system("clear");
                login();
                break;
            case 3:
                if (system("CLS")) system("clear");
                new VistaInvitado(this->foro);
                break;
            default:
                continue;       
        }
        break;
    }
}

void Vista::registro() {
    string nombreUsuario;
    string alias;
    string pass;
    string pass2;
    
    while (true) {
        cout << "\nRegistro:" << endl
        << "====================================================" << endl
        << "\nIntroduce un nombre de usuario:" << endl;
        cin >> nombreUsuario;
        
        if (foro->usuarioPorNombre(nombreUsuario) != NULL)
            cout << "\nEste nombre de usuario ya existe!!" << endl;
        else
            break;
    }    
     
    cout << "Introduce un alias:" << endl;
    cin >> alias;
    
    while (true) {
        cout << "Introduce una clave" << endl;
        cin >> pass;
        cout << "Vuelve a introducir la clave" << endl;
        cin >> pass2;
        if (pass.compare(pass2) == 0)
            break;
        else {
            cout << endl << "=== Las claves no coinciden ===" << endl << endl;         
        }             
    }
    foro->nuevoUsuario(nombreUsuario, alias, pass);
    if (system("CLS")) system("clear");
    mensajeInicial();
}

void Vista::login() {	
        cout << "\nLogin (\"exit\" para salir)" << endl
        << "====================================================\n" << endl; 
        
	string usuario;
	string pass;
        
        bool login = false;
        do {        
            cout << "Usuario:" << endl;
            cin >> usuario;
            
            if (usuario.compare("exit") == 0) {
                if (system("CLS")) system("clear");
                mensajeInicial();
            }
            
            Usuario *u = foro->usuarioPorNombre(usuario);
            
            if (u == NULL){
                cout << "El usuario no existe" << endl;
                continue;
            }
            
            cout << "Clave:" << endl;
            cin >> pass;      
            
            if (pass.compare("exit") == 0) {
                if (system("CLS")) system("clear");
                mensajeInicial();
            }

            if (u->validarClave(pass) == 0){
                login = true;
                if (system("CLS")) system("clear");
                vistaForo(u);
            }
            else
                cout << "\nLogin incorrecto\n" << endl;             
        } while (!login);    
}

void Vista::vistaForo(Usuario *u) {
    int resultado;
    cout << "\nBIENVENIDO " << u->getNombre() << " al Foro: \"" << foro->getNombre() << "\"" << endl
    << "====================================================\n" << endl;

    while (true) {       
        cout << "1: Crear Tema" <<endl
        << "2: Ver temas" << endl
        << "3: Buscar temas" << endl        
        << "4: Configuracion de usuario " << endl
        << "5: Cerrar sesion y salir al menu principal" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                crearTema(u);
                break;
            case 2:
                if (system("CLS")) system("clear");
                verTemas(u);
                break;
            case 3:
                if (system("CLS")) system("clear");
                buscarTemas(u);
                break;
            case 4:
                if (system("CLS")) system("clear");
                menuUsuario(u);
                break;
            case 5:
                if (system("CLS")) system("clear");
                mensajeInicial();
                break;
            default:
                continue;       
        }
    break;
    }
}

void Vista::crearTema(Usuario *u) {
    string titulo;
    cout << "\nIntroduce el titulo del tema" << endl;
    cin.ignore();
    getline(cin, titulo);
    foro->nuevoTema(titulo);
    cout << "Nuevo tema: " << "\"" << titulo << "\"" << " creado correctamente" << endl;
    if (system("CLS")) system("clear");
    vistaForo(u);
    
}

void Vista::verTemas(Usuario* u) {
    int numeroTema;
    Tema *t;
    cout << "\nTemas" << endl
    << "====================================================\n" << endl;   
    
    if (foro->numTemas() > 0) {
        for (int i = 0; i < foro->numTemas(); i++) {
            cout << i + 1 << "-> " << foro->verTema(i)->getDenominacion() << " | Creado por: " << u->getAlias() << endl;
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

void Vista::buscarTemas(Usuario* u) {
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

void Vista::menuUsuario(Usuario* u) {
    cout << "\nConfiguracion de usuario" << endl
    << "====================================================\n" << endl;      
    
    int resultado;
    while (true) {       
        cout << "1: Cambiar nombre" <<endl
        << "2: Cambiar alias" << endl
        << "3: Cambiar clave" << endl
        << "4: Volver al menu del foro" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                menuCambiarNombre(u);
                break;
            case 2:
                if (system("CLS")) system("clear");
                menuCambiarAlias(u);
                break;
            case 3:
                if (system("CLS")) system("clear");
                menuCambiarClave(u);
                break;
            case 4:
                if (system("CLS")) system("clear");
                vistaForo(u);
                break;
            default:
                continue;       
        }
    break;
    }    
}

void Vista::menuCambiarNombre(Usuario* u) {
    string nuevoNombre;    
    while (true) {
        cout << "\nIntroduce un nuevo nombre de usuario:" << endl;
        cin >> nuevoNombre;
        
        if (foro->usuarioPorNombre(nuevoNombre) != NULL)
            cout << "\nEste nombre de usuario ya existe!!" << endl;
        else
            break;
    }      
    u->cambiarNombre(nuevoNombre);
    cout << "\nNombre cambiado correctamente" << endl;
    if (system("CLS")) system("clear");
    menuUsuario(u);
}

void Vista::menuCambiarAlias(Usuario* u) {
    string nuevoAlias;

    cout << "\nIntroduce un nuevo alias:" << endl;
    cin >> nuevoAlias;

    u->cambiarAlias(nuevoAlias);
    cout << "\nAlias cambiado correctamente" << endl;
    
    if (system("CLS")) system("clear");
    menuUsuario(u);    
}

void Vista::menuCambiarClave(Usuario* u) {
    string oldPass;
    string newPass;
    string newPass2;
    
    while (true) {
        cout << "\nIntroduce la clave actual" << endl;
        cin >> oldPass;
        
        if (u->validarClave(oldPass) == 0)
            break;
        else
            cout << "\nClave incorrecta" << endl;
    }
    
    while (true) {
        cout << "Introduce la nueva clave" << endl;
        cin >> newPass;
        cout << "Vuelve a introducir la clave" << endl;
        cin >> newPass2;
        if (newPass.compare(newPass2) == 0)
            break;
        else {
            cout << endl << "=== Las claves no coinciden ===" << endl << endl;      
        }             
    }
    u->cambiarClave(newPass);
    
    cout << "\nClave cambiada correctamente" << endl;
    
    if (system("CLS")) system("clear");
    menuUsuario(u);
}

void Vista::menuTema(Usuario*u, Tema *t) {
    int resultado;
    
    cout << "\nBIENVENIDO " << u->getNombre() << " al Tema: \"" << t->getDenominacion() << "\"" << endl
    << "====================================================\n" << endl;
    
    while (true) {       
        cout << "1: Nuevo hilo" <<endl
        << "2: Ver hilos" << endl
        << "3: Buscar hilo" << endl
        << "4: Volver al menu del Foro" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                crearHilo(u, t);
                break;
            case 2:
                if (system("CLS")) system("clear");
                verHilos(u, t);
                break;
            case 3:
                if (system("CLS")) system("clear");
                buscarHilos(u, t);
                break;
            case 4:
                if (system("CLS")) system("clear");
                vistaForo(u);
                break;
            default:
                continue;      
        }
    break;
    }
}

void Vista::crearHilo(Usuario* u, Tema *t) {
    string titulo;
    string mensajeInicial;
    
    cout << "\nIntroduce un titulo" << endl;
    cin.ignore();
    getline(cin, titulo);
    
    cout << "\nIntroduce un mensaje inicial" << endl;
    getline(cin, mensajeInicial);
    
    t->nuevoHilo(titulo, new Mensaje(mensajeInicial, u));
    cout << "Nuevo hilo: " << "\"" << titulo << "\"" << " creado correctamente" << endl;
    
    if (system("CLS")) system("clear");
    menuTema(u, t);
}

void Vista::verHilos(Usuario* u, Tema* t) {
    int numeroHilo;
    Hilo *h;
    cout << "\nHilos" << endl
    << "====================================================\n" << endl;  

    if (t->numeroHilo() > 0) {
        for (int i = 0; i < t->numeroHilo(); i++) {
            cout << "Hilo " << i + 1 << "-> " << t->verHilo(i)->getTitulo() << " | Creado por: " << u->getAlias() << endl
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

void Vista::buscarHilos(Usuario* u, Tema* t) {
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

void Vista::menuHilo(Usuario* u, Tema *t, Hilo* h) {
    int resultado;

    cout << "\nBIENVENIDO " << u->getNombre() << " al Hilo: \"" << h->getTitulo() << "\"" << endl
    << "====================================================\n" << endl;
    
    while (true) {       
        cout << "1: Nuevo mensaje" <<endl
        << "2: Ver mensajes" << endl
        << "3: Buscar mensajes" << endl
        << "4: Volver al menu de Temas " << endl;     
        cin >> resultado;       
        switch (resultado) {
            case 1:
                if (system("CLS")) system("clear");
                crearMensaje(u, t, h);
                break;
            case 2:
                if (system("CLS")) system("clear");
                verMensajes(u, t, h);
                break;
            case 3:
                if (system("CLS")) system("clear");
                buscarMensajes(u, t, h);
                break;
            case 4:
                if (system("CLS")) system("clear");
                menuTema(u, t);
                break;
            default:
                continue;      
        }
    break;
    }
}

void Vista::crearMensaje(Usuario* u, Tema* t, Hilo* h) {
    string contenidoMensaje;
    
    cout << "\nEscribe un mensaje" << endl;
    cin.ignore();
    getline(cin, contenidoMensaje);
    
    h->nuevoMensaje(contenidoMensaje, u);
    
    if (system("CLS")) system("clear");
    menuHilo(u, t, h);
}

void Vista::verMensajes(Usuario* u, Tema* t, Hilo* h) {
    char caracter = ' ';

    cout << "\nMensajes" << endl
    << "====================================================\n" << endl;    
    
    for (int i = 0; i < h->numMensajes(); i++) {
        cout << i+1 << "-> " << "Autor: " << h->verMensaje(i)->verAutor()->getAlias() << " | Fecha: " << h->verMensaje(i)->getFecha()->getFecha() << endl
        << "Mensaje: " << endl << h->verMensaje(i)->getContenido() << endl << endl;
    }
    
    do {
        cout << "\nPulse una tecla para regresar" << endl;
        cin >> caracter;
    }
    while (caracter == ' ');
    
    if (system("CLS")) system("clear");
    menuHilo(u, t, h);
}

void Vista::buscarMensajes(Usuario* u, Tema* t, Hilo* h) {
    string criterio;
    char caracter = ' ';
    
    cout << "\nIntroduzca un criterio de busqueda:" << endl;
    cin >> criterio;
    
    vector<Mensaje> *resultado = h->buscarMensajes(criterio);
    
    cout << "\n----- Mensajes encontrados -----\n" << endl;
    for (int i = 0; i < resultado->size(); i++) {
        cout << i+1 << "-> " << "Autor: " << h->verMensaje(i)->verAutor()->getAlias() << " | Fecha: " << h->verMensaje(i)->getFecha()->getFecha() << endl
        << "Mensaje: " << endl << h->verMensaje(i)->getContenido() << endl << endl;
    } 
    
    do {
        cout << "\nPulse una tecla para regresar" << endl;
        cin >> caracter;
    }
    while (caracter == ' ');
    
    if (system("CLS")) system("clear");
    menuHilo(u, t, h);    
}