#ifndef CABECALHO_H
#define CABECALHO_H

#include <iostream>
#include <cstdlib>
#include <QByteArray>

using namespace std;

class Cabecalho {

private:
    ushort formato;                 // string de tamanho 3, padrao BIR
    unsigned int tamanhoCluster;    // tamanho cluster
    unsigned int tamanhoDisco;      // tamanho disco
                                    // qtd cluster
                                    // espaco ocupado?
                                    // espaco livre?
    unsigned int inicioFAT;         // inicio fat
    unsigned int tamanhoFAT;        // tamanho fat?
    unsigned int inicioDados;       // inicio dados
    unsigned int tamanhoDados;      // tamanho dados


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
