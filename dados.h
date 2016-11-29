#ifndef DADOS_H
#define DADOS_H

#include <iostream>
#include <cstdlib>
#include <QByteArray>

class Dados {

private:
QByteArray dados;

public:
    Dados();
    Dados(QByteArray byteArray);

    QByteArray getDados();

};

#endif // DADOS_H
