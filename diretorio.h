#ifndef DIRETORIO_H
#define DIRETORIO_H

#include <entradadiretorio.h>
#include <QList>

class Diretorio {

private:
    static Padroes p;

    uint clusterAtual;
    uint clusterPai;
    QList<EntradaDiretorio> entradas;

    QByteArray entradasToByteArray();
    QByteArray completaLista();
    QByteArray geraEntradaVazia();

public:
    Diretorio();
    Diretorio(uint atual, uint pai);

    QByteArray toByteArray();
};

#endif // DIRETORIO_H