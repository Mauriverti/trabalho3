#include "fat.h"

uint Fat::calculaPosicaoNaTabela(uint posicao) {
    return posicao*4;
}

Fat::Fat() {}

Fat::Fat(QByteArray table) {
    this->tabela = table;
}

int Fat::getPosicao(uint posicao) {
    if (posicao >= this->tabela.size()) {
        cout << "Posicao " << posicao << " inacessivel";
        return -1;
    }

    return *((int *) this->tabela.mid(calculaPosicaoNaTabela(posicao),4).data());
}

void Fat::setPosicao(uint posicao, int valor) {
    this->tabela.replace(calculaPosicaoNaTabela(posicao), 4, (char*) &valor);
}

uint Fat::achaPrimeiroLivre() {
    uint tamanho = tabela.size();
    for (uint i = 0; i < tamanho; i++) {
        int valor = getPosicao(i);
        if (valor == 0) return i;
    }
    return INT_MAX;
}

void Fat::formatar() {
    uint tamanho = tabela.size();
    char zero = 0;
    for (uint i = 0; i < tamanho; i++) {
        tabela.replace(i, 1, (char*) &zero);
    }

    this->setPosicao(0, -1);    // marca o diretorio raiz como ocupado
}

QByteArray Fat::getTable() {
    return this->tabela;
}
