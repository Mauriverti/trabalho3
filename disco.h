#ifndef DISCO_H
#define DISCO_H

#include <iostream>
#include <cstdlib>
#include <cabecalho.h>
#include <fat.h>
#include <dados.h>

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
    void abrir(QByteArray byteArray);
};

#endif // DISCO_H
