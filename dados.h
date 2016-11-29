#ifndef DADOS_H
#define DADOS_H

#include <padroes.h>
#include <diretorio.h>

class Dados {

private:
    QByteArray dados;
    Padroes p;

    void montaDiretorioRaiz();
    QByteArray montaClusterDiretorio();
    QByteArray montaClusterArquivo();


public:
    Dados();
    Dados(QByteArray byteArray);

    void formatar();

    QByteArray getDados();

};

#endif // DADOS_H
