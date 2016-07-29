#include <ctime>
#include "Fecha.h"
#include <sstream>

using namespace std;

Fecha::Fecha() {
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);   
    this->anio = tlocal->tm_year + 1900;
    this->mes = tlocal->tm_mon + 1;
    this->dia =  tlocal->tm_mday;    
    hora = new Hora(tlocal->tm_hour, tlocal->tm_min, tlocal->tm_sec);
}

string Fecha::getFecha() {
    ostringstream fec;
    fec << this->dia << "/" << this->mes << "/" << this->anio << endl << this->hora->getHora();
    string fecha = fec.str();
    return fecha;
}