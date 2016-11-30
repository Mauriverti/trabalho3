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

    char* nome;
    char* extensao;
    uint primeiroCluster;
    bool ehAarquivo;            // true se for arquivo, false se for pasta

    string normalizaString(string str, uint tamanhoMaximo);
    char* string2charVet(string str, uint tamanho);

    char* parseNome(string str, uint tamanho);

public:
    EntradaDiretorio();
    EntradaDiretorio(char* nome, char* extensao, uint primeiroCluster, bool ehArquivo);

    QByteArray toByteArray();
};

#endif // ENTRADADIRETORIO_H