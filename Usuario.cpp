#include "Usuario.h"

using namespace std;

bool Usuario::validarClave(string clave) {
    if (this->clave.compare(this->clave) == 0)
        return 0;
    else
        return 1;
}