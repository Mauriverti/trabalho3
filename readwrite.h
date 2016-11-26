#ifndef READWRITE_H
#define READWRITE_H

#include <QByteArray>
#include <QFile>
#include <qdebug.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class ReadWrite {

public:
    ReadWrite();

    void gravaArquivo(QString diretorio, QByteArray informacao);
};

#endif // READWRITE_H
