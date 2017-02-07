#ifndef FAT_H
#define FAT_H

#include <cstdlib>
#include <iostream>
#include <QByteArray>

using namespace std;

class Fat {

private:
    QByteArray tabela;

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

};

#endif // FAT_H
