#include "dados.h"

QByteArray Dados::montaClusterDiretorio(uint cluster, uint pai) {
    return Diretorio(cluster, pai).toByteArray();
}

QByteArray Dados::montaClusterArquivo() {

}

uint Dados::calculaPosicao(uint posicao) {
    return posicao*p.tamanhoCluster;
}

Dados::Dados() {

}

Dados::Dados(QByteArray byteArray) {
    this->dados = byteArray;
}

void Dados::formatar() {
    Diretorio raiz = Diretorio(0, 0);

    this->setCluster(0, raiz.toByteArray());
}

QByteArray Dados::getDados() {
    return this->dados;
}

QByteArray Dados::getCluster(uint posicao) {
    uint _posicao = calculaPosicao(posicao);
    if (_posicao > this->dados.size()) {
        cout << endl << "Posicao invalida do cluster";
    }
    return this->dados.mid(_posicao, p.tamanhoCluster);
}

void Dados::setCluster(uint posicao, QByteArray byteArray) {
    uint _posicao = calculaPosicao(posicao);
    if (_posicao > this->dados.size()) {
        cout << endl << "Posicao invalida do cluster";
        return;
    } else {
        int tamanhoClusterNovo = byteArray.size();
        int tamanhoCluster = p.tamanhoCluster;
        if (byteArray.size() != p.tamanhoCluster) {
            cout << endl << "Tamanho do cluster invalido";
            return;
        }
    }
    this->dados.replace(_posicao, p.tamanhoCluster, byteArray);
}
