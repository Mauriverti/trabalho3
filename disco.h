#ifndef DISCO_H
#define DISCO_H

#include <iostream>
#include <cstdlib>
#include <cabecalho.h>

using namespace std;

class Disco {

private:
    Cabecalho cabecalho;

public:
    Disco();

    Cabecalho getCabecalho();
    void setCabecalho(Cabecalho c);
};

#endif // DISCO_H
