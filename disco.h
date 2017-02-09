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
    void setFat(Fat fat);

    Fat getFat();
    Dados getDados();

    void formatar(QByteArray b);
    void formatar();
    QByteArray toByteArray();
    void abrir(QByteArray byteArray, bool formatado);

    void setPosicaoFat(int posicao, int valor);
    void setClusterDados(int posicao, QByteArray dados);

    void mostraFat();
};

#endif // DISCO_H
