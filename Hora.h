#ifndef HORA_H
#define HORA_H

#include <sstream>

using namespace std;

class Hora {
    int hora, min, seg;
    public:
        Hora(int hora, int min, int seg):hora(hora), min(min), seg(seg){}
        string getHora();
        ~Hora(){};
};

#endif

