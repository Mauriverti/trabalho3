#include "fat.h"

Fat::Fat() {

}

Fat::Fat(uint tamanho) {
    this.tamanho = tamanho;
    this.clusters = int[tamanho];
}

void Fat::getPosicao(uint posicao) {
    return this.clusters[posicao];
}

void Fat::setPosicao(uint posicao, int valor) {
    this.clusters[posicao] = valor;
}

uint Fat::achaPrimeiroLivre() {
    for (uint i = 0; i < tamanho; i++) {
        if (clusters[i] == 0) {
            return i;
        }
    }
    return INT_MAX;
}