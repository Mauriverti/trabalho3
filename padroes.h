#ifndef PADROES_H
#define PADROES_H

#include <QByteArray>

class Padroes {

public:
    Padroes();
    static const uint tamanhoCluster = 4 * 1024;     // 4k
    static const uint tamanhoCabecalho = 26;
    static const short siglaFormato = (((short)'I') << 8) | 'B';

    static const int tamanhoNomeArquivo = 20;
    static const uint tamanhoExtensaoArquivo = 3;
    static const uint tamanhoEntradaDiretorio = tamanhoNomeArquivo + tamanhoExtensaoArquivo + 5;     // 20 + 3 + 5 = 28
    static const uint quantidadeEntradasDiretorio = (tamanhoCluster - 8)/tamanhoEntradaDiretorio;    // (4096 - 8) / 28 = 146     // 8 = clusterInicial + clusterPai

};

#endif // PADROES_H
