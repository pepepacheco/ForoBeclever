#include "Vista.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

Vista::Vista() {
    foro = new Foro("Foro beclever");
    mensajeInicial();
}

void Vista::mensajeInicial() {
    int resultado;    
    while (true) {       
        cout << "\nELIGE UNA OPCION" << endl
        << "==========================" << endl
        << "\n1: Registrarme en el foro" <<endl
        << "2: Identificarme" << endl
        << "3: Acceder como invitado " << endl;
        cin >> resultado;       
        switch (resultado) {
            case 1:
                registro();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Elegido 3" << endl;
                exit(0);
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
    
    cout << "\nRegistro:" << endl
    << "==========================" << endl
    << "\nIntroduce un nombre de usuario:" << endl;
    cin >> nombreUsuario;
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
            continue;          
        }             
    }
    foro->nuevoUsuario(nombreUsuario, alias, pass);   
    mensajeInicial();
}

void Vista::login() {	
        cout << "\nLogin\n:" << endl
        << "==========================" << endl;    
	string usuario;
	string pass;
        bool login = false;
        do {        
            cout << "Usuario:" << endl;
            cin >> usuario;
            cout << "Clave:" << endl;
            cin >> pass;

            for (int i = 0; i < foro->getUsuarios()->size(); i++ ) {
                if ((foro->getUsuarios()->at(i).getNombre().compare(usuario) == 0) && (foro->getUsuarios()->at(i).getPass().compare(pass) == 0)){
                    login = true;
                    break;
                }    
            }
            if (!login)
                cout << "\nLogin incorrecto\n" << endl;
        }
        while (!login);       
        mensajeInicial();
}












