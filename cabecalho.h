#ifndef CABECALHO_H
#define CABECALHO_H

#include <iostream>
#include <cstdlib>
#include <padroes.h>

using namespace std;

class Cabecalho {

private:
    ushort formato;         // string de tamanho 2, padrao BI
    uint tamanhoCluster;    // tamanho cluster
    uint tamanhoDisco;      // tamanho disco
                            // qtd cluster
                            // espaco ocupado?
                            // espaco livre?
    uint inicioFAT;         // inicio fat
    uint tamanhoFAT;        // tamanho fat?
    uint inicioDados;       // inicio dados
    uint tamanhoDados;      // tamanho dados

    Padroes p;


public:
    Cabecalho();
    Cabecalho(QByteArray byteArray);

    ushort getFormato();
    void setFormato(ushort formato);
    uint getTamanhoCluster();
    void setTamanhoCluster(uint tamanhoCluster);
    uint getTamanhoDisco();
    void setTamanhoDisco(uint tamanhoDisco);
    uint getInicioFAT();
    void setInicioFAT(uint inicioFAT);
    uint getTamanhoFAT();
    void setTamanhoFAT(uint tamanhoFAT);
    uint getInicioDados();
    void setInicioDados(uint inicioDados);
    uint getTamanhoDados();
    void setTamanhoDados(uint tamanhoDados);

    void abrir(QByteArray byteArray);
    QByteArray toByteArray();

};

#endif // CABECALHO_H
