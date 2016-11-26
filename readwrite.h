#ifndef READWRITE_H
#define READWRITE_H

#include <QByteArray>
#include <QFile>
#include <qdebug.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class ReadWrite {

private:
    bool validaDiretorio(QString diretorio);
    bool validaInformacao(QByteArray informacao);
    QFile* abrirArquivoLeitura(QString diretorio);
    QFile* abrirArquivoEscrita(QString diretorio);

public:
    ReadWrite();

    QByteArray lerArquivo(QString diretorio);
    void gravaArquivo(QString diretorio, QByteArray informacao);
};

#endif // READWRITE_H
