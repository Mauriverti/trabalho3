#ifndef ENTRADADIRETORIO_H
#define ENTRADADIRETORIO_H

#include <cstdlib>
#include <iostream>
#include <QByteArray>
#include <padroes.h>

using namespace std;

class EntradaDiretorio {

private:
    static Padroes p;

    string nome;
    string extensao;
    uint primeiroCluster;
    bool ehAarquivo;            // true se for arquivo, false se for pasta

    string cortaString(string str, uint tamanhoMaximo);

public:
    EntradaDiretorio();
    EntradaDiretorio(string nome, string extensao, uint primeiroCluster, bool ehArquivo);

    QByteArray toByteArray();
};

#endif // ENTRADADIRETORIO_H
