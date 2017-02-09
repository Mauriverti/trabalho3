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
    QByteArray bvalor;
    bvalor.insert(0, (char*) &valor, 4);
    this->tabela = this->tabela.replace(calculaPosicaoNaTabela(posicao), 4, bvalor);
}

uint Fat::achaPrimeiroLivre() {
    uint tamanho = tabela.size();
    for (uint i = 0; i < tamanho; i++) {
        int valor = getPosicao(i);
        if (valor == 0) return i;
    }
    return INT_MAX;
}

bool Fat::temEspaco(int qtdClusters) {
    int tamanho = (this->tabela.size()/4);      // dividido por 4 pois um int tem 4 bytes

    int posicoesLivres = 0;
    for (uint i = 0; i < tamanho || posicoesLivres == qtdClusters; i++) {
        int valor = getPosicao(i);
        if (valor == 0) posicoesLivres++;
    }
    if (posicoesLivres >= qtdClusters) return true;
    return false;
}

void Fat::formatar() {
    uint tamanho = tabela.size();

    char czero = 0;
    QByteArray bzero;
    bzero.insert(0, (char*) &czero, 1);

    for (uint i = 0; i < tamanho; i++) {
        tabela.replace(i, 1, bzero);
    }

    this->setPosicao(0, -1);    // marca o diretorio raiz como ocupado
}

QByteArray Fat::getTable() {
    return this->tabela;
}

void Fat::exibeFat() {

    int tamanho = (this->tabela.size()/4);      // dividido por 4 pois um int tem 4 bytes

    cout << endl << "FAT";
    cout << endl << "1\t2\t3\t4\t5\t6\t7\t8\t9\t10";
    cout << endl << "----------------------------------------------------------------------------";

    for (int i = 0; i < tamanho; i++) {
        if (i%10 == 0) cout << endl;
        cout << getPosicao(i) << "\t";
    }
}
