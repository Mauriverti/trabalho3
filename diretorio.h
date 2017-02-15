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
    QByteArray geraEntradaVazia(uint tamanho);

public:
    Diretorio();
    Diretorio(uint atual, uint pai);
    Diretorio(QByteArray byteArray);

    QList<EntradaDiretorio> getEntradas();
    uint getClusterAtual();
    uint getClusterPai();
    void addEntrada(EntradaDiretorio ed);

    void exibeConteudo();
    void exibeEntrada();
    QByteArray toByteArray();
};

#endif // DIRETORIO_H
