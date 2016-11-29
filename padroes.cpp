#include "padroes.h"

uint tamanhoCluster = 4 * 1024;     // 4k
uint tamanhoCabecalho = 26;
short siglaFormato = (((short)'I') << 8) | 'B';


Padroes::Padroes() {}

uint Padroes::getTamanhoCluster() {
    return tamanhoCluster;
}

uint Padroes::getTamanhoCabecalho() {
    return tamanhoCabecalho;
}

short Padroes::getSiglaFormato() {
    return siglaFormato;
}
