#ifndef CABECALHO_H
#define CABECALHO_H

#include <iostream>
#include <cstdlib>
#include <QByteArray>

using namespace std;

class Cabecalho {

private:
    string formato;         // string de tamanho 3, padrao BIR
    int tamanhoCluster;     // tamanho cluster
    int tamanhoDisco;       // tamanho disco
                            // qtd cluster
                            // espaco ocupado?
                            // espaco livre?
    int inicioFAT;          // inicio fat
    int tamanhoFAT;         // tamanho fat?
    int inicioDados;        // inicio dados
    int tamanhoDados;       // tamanho dados


public:
    Cabecalho();
    Cabecalho(QByteArray byteArray);

    string getFormato();
    void setFormato(string formato);
    int getTamanhoCluster();
    void setTamanhoCluster(int tamanhoCluster);
    int getTamanhoDisco();
    void setTamanhoDisco(int tamanhoDisco);
    int getInicioFAT();
    void setInicioFAT(int inicioFAT);
    int getTamanhoFAT();
    void setTamanhoFAT(int tamanhoFAT);
    int getInicioDados();
    void setInicioDados(int inicioDados);
    int getTamanhoDados();
    void setTamanhoDados(int tamanhoDados);


    QByteArray toByteArray();



};

#endif // CABECALHO_H
