#ifndef FAT_H
#define FAT_H

#include <cstdlib>
#include <iostream>
#include <QByteArray>
#include <QList>
#include "padroes.h"

using namespace std;

class Fat {

private:
    QByteArray tabela;

    Padroes p;
    uint calculaPosicaoNaTabela(uint posicao);

public:
    Fat();
    Fat(QByteArray tabela);
    int getPosicao(uint posicao);
    void setPosicao(uint posicao, int valor);
    uint achaPrimeiroLivre();

    bool temEspaco(int qtdClusters);
    void formatar();
    QByteArray getTable();

    void exibeFat();

    bool checaArquivo(uint primeiroCluster, uint qtdCluster);

};

#endif // FAT_H
