#include "diretorio.h"

QByteArray Diretorio::entradasToByteArray() {
    QByteArray byteArray;
    for (EntradaDiretorio ed: this->entradas) {
        byteArray.append(ed.toByteArray());
    }
    return byteArray;
}

//QByteArray Diretorio::completaLista() {

//    QByteArray entradaVazia = geraEntradaVazia(p.tamanhoEntradaDiretorio);
//    QByteArray b;
//    uint c = p.quantidadeEntradasDiretorio;
//    for (uint inicio = this->entradas.size(); inicio < c; inicio++) {
//        b.insert(inicio*p.tamanhoEntradaDiretorio, entradaVazia);
//    }
//    return b;
//}


QByteArray Diretorio::geraEntradaVazia(uint tamanho) {

    QByteArray b;
    char zero = 0;

    for (uint i = 0; i < (tamanho); i++) {
        b.insert(i, (char*) &zero, 1);
    }

    return b;
}

Diretorio::Diretorio() {}

Diretorio::Diretorio(uint atual, uint pai) {
    this->clusterAtual = atual;
    this->clusterPai = pai;
}

Diretorio::Diretorio(QByteArray byteArray) {
    uint deslocamento = 0;
    this->clusterAtual = *((uint *) byteArray.mid(deslocamento,4).data());
    deslocamento += 4;
    this->clusterPai =   *((uint *) byteArray.mid(deslocamento,4).data());
    deslocamento += 4;

    for (uint i = 0; i < p.quantidadeEntradasDiretorio; i++) {
        EntradaDiretorio ed = EntradaDiretorio(byteArray.mid(deslocamento,p.tamanhoEntradaDiretorio));

        if (!ed.entradaValida()) {
            break;
        }

        this->entradas.append(ed);
        deslocamento += p.tamanhoEntradaDiretorio;
    }
}

QList<EntradaDiretorio> Diretorio::getEntradas() {
    return this->entradas;
}

uint Diretorio::getClusterAtual() {
    return this->clusterAtual;
}

uint Diretorio::getClusterPai() {
    return this->clusterPai;
}

void Diretorio::addEntrada(EntradaDiretorio ed) {
    this->entradas.append(ed);
}

void Diretorio::exibeConteudo() {
    cout << endl << endl << "Cluster atual: " << this->clusterAtual;
    cout << endl << "Cluster pai: " << this->clusterPai;

    this->exibeEntrada();

    cout << endl << endl;
}

void Diretorio::exibeEntrada() {
    for (EntradaDiretorio ed: this->entradas) {
        cout << endl << ed.toString().toStdString();
    }
}

QByteArray Diretorio::toByteArray() {
    QByteArray b;

    b.insert(0, (char*) &this->clusterAtual, 4);
    b.insert(4, (char*) &this->clusterPai, 4);

    int deslocamento = 8;

    uint qtdArquivos = this->entradas.size();
    for (uint i = 0; i < qtdArquivos; i++) {
        EntradaDiretorio ed = entradas.at(i);
        b.insert(deslocamento, ed.toByteArray());
        deslocamento += p.tamanhoEntradaDiretorio;
    }

    b.append(this->geraEntradaVazia(p.tamanhoCluster-deslocamento));

    return b;
}
