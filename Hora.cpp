#include "Hora.h"

using namespace std;

string Hora::getHora(){
    ostringstream hor;
    hor << hora << ":" << min << ":" << seg;               
    string hora = hor.str();
      
    return hora;
}