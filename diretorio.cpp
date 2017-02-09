#include "diretorio.h"

QByteArray Diretorio::completaLista() {

    QByteArray entradaVazia = geraEntradaVazia();
    QByteArray b;
    uint c = p.quantidadeEntradasDiretorio;
    for (uint inicio = this->entradas.size(); inicio < c; inicio++) {
        b.insert(inicio*p.tamanhoEntradaDiretorio, entradaVazia);
    }
    return b;
}

QByteArray Diretorio::geraEntradaVazia() {

    QByteArray b;
    char zero = 0;

    for (uint i = 0; i < (p.tamanhoEntradaDiretorio); i++) {
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
    for (int i = 0; i < this->entradas.size(); i++) {
        EntradaDiretorio ed = this->entradas.at(i);
        cout << endl << i << " - " << ed.toString();
    }
}

QByteArray Diretorio::toByteArray() {
    cout << endl << "Diretorio toByteArray";
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

    b.insert(deslocamento, completaLista());

    cout << endl <<  "tamanho: " << b.size();

    return b;
}
