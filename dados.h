#ifndef DADOS_H
#define DADOS_H

#include <padroes.h>
#include <diretorio.h>

class Dados {

private:
    QByteArray dados;
    Padroes p;

    QByteArray montaClusterDiretorio(uint cluster, uint pai);
    QByteArray montaClusterArquivo();

    uint calculaPosicao(uint posicao);

public:
    Dados();
    Dados(QByteArray byteArray);

    void formatar();

    QByteArray getDados();
    
    QByteArray getCluster(uint posicao);
    void setCluster(uint posicao, QByteArray byteArray);

};

#endif // DADOS_H
