#ifndef DIRETORIO_H
#define DIRETORIO_H

#include <entradadiretorio.h>

class Diretorio {

private:
    static Padroes p;

    uint clusterAtual;
    uint clusterPai;
    EntradaDiretorio entradas[p.quantidadeEntradasDiretorio];

public:
    Diretorio();
    Diretorio(uint atual, uint pai);
};

#endif // DIRETORIO_H
