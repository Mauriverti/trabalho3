#ifndef CABECALHO_H
#define CABECALHO_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Cabecalho {

private:
    string formato;         // string de tamanho 3, padrao BIR
                            // tamanho cluster
                            // tamanho disco
                            // qtd cluster
                            // espaco ocupado?
                            // espaco livre?
                            // inicio fat
                            // tamanho fat?
                            // inicio data


public:
    Cabecalho();

    string getFormato();
    void setFormato(string formato);




};

#endif // CABECALHO_H
