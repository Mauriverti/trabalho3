#ifndef ENTRADADIRETORIO_H
#define ENTRADADIRETORIO_H

#include <cstdlib>
#include <iostream>
#include <QByteArray>
#include <padroes.h>
#include <QString>

using namespace std;

class EntradaDiretorio {

private:
    static Padroes p;

    QString nome;               // 16
    QString extensao;           // 3
    uint primeiroCluster;
    uint tamanhoArquivo;
    bool ehAarquivo;            // true se for arquivo, false se for pasta
    QString normalizaString(QString str, uint tamanhoMaximo);
    QByteArray qString2ByteArray(QString s);

public:
    EntradaDiretorio();
    EntradaDiretorio(QString nome, QString extensao, uint tamanhoArquivo, uint primeiroCluster, bool ehArquivo);
    EntradaDiretorio(QByteArray byteArray);

    bool entradaValida();
    QString toString();

    uint getPrimeiroCluster();

    QByteArray toByteArray();
};

#endif // ENTRADADIRETORIO_H
