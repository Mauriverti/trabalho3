#ifndef DISCO_H
#define DISCO_H

#include <cabecalho.h>
#include <fat.h>
#include <dados.h>

using namespace std;

class Disco {

private:
    Cabecalho cabecalho;
    Fat fat;
    Dados dados;

public:
    Disco();
    Disco(QByteArray byteArray);

    Cabecalho getCabecalho();
    void setCabecalho(Cabecalho c);

    void formatar(QByteArray b);
    void formatar();
    QByteArray toByteArray();
    void abrir(QByteArray byteArray, bool formatado);
};

#endif // DISCO_H
