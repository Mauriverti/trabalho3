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
    uint tamanho = (this->tabela.size()/4);      // dividido por 4 pois um int tem 4 bytes

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
    cout << endl << "\t 0\t1\t2\t3\t4\t5\t6\t7\t8\t9";
    cout << endl << "-------------------------------------------------------------------------------------";

    for (int i = 0; i < tamanho; i++) {
        if (i%10 == 0) cout << endl << i << "\t|";
        cout << getPosicao(i) << "\t";
    }
    cout << endl;
}

bool Fat::checaArquivo(uint primeiroCluster, uint qtdCluster) {

    uint maxClusters = this->tabela.size()/4;
    QList<uint> clustersVizitados;

    uint cont = 1;
    uint proxCluster = this->getPosicao(primeiroCluster);
    uint clusterAtual = primeiroCluster;


//    while ((proxCluster != -1) && (proxCluster != 0) && (cont <= maxClusters) && !(clustersVizitados.contains(proxCluster))) {
//        clustersVizitados.append(proxCluster);
//        cont++;
//        proxCluster = this->getPosicao(proxCluster);
//    }
    while (true) {
        if (proxCluster == -1) {
            if (cont == qtdCluster) return true;
            else {
                cout << endl << "Arquivo com clusters faltando / sobrando - impossivel corrigir";
            }
            return false;
        }
        if (proxCluster == 0) {
            cout << endl << "Erro no final de Arquivo";
            if (cont == qtdCluster) {
                cout << endl << "Tentativa de correcao";
                this->setPosicao(clusterAtual, -1);
                return true;
            } else {
                cout << endl << "Impossivel corrigir";
            } return false;
        }
        if (cont > maxClusters) {
            cout << endl << "Erro - Arquivo muito grande - impossivel corrigir";
            return false;
        }
        if (clustersVizitados.contains(proxCluster)) {
            cout << endl << "Erro - Arquivo em ciclo";
            if (cont == qtdCluster) {
                cout << endl << "Tentativa de correcao";
                this->setPosicao(clusterAtual, -1);
                return true;
            } else {
                cout << endl << "Impossivel corrigir";
            } return false;
        }

        clustersVizitados.append(clusterAtual);
        cont++;
        clusterAtual = proxCluster;
        proxCluster = this->getPosicao(proxCluster);

    }


    return false;
}
