#ifndef CABECALHO_H
#define CABECALHO_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Cabecalho {

public:
    Cabecalho();

    char formato[3];        // padrao BIR
                            // tamanho cluster
                            // tamanho disco
                            // qtd cluster
                            // espaco ocupado?
                            // espaco livre?
                            // inicio fat
                            // tamanho fat?
                            // inicio data



};

#endif // CABECALHO_H
