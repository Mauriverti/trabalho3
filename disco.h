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
    Disco(QByteArray byteArray);

    Cabecalho getCabecalho();
    void setCabecalho(Cabecalho c);

    void formatar(QByteArray b);
    QByteArray toByteArray();
};

#endif // DISCO_H
