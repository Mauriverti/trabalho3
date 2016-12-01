#include "entradadiretorio.h"

EntradaDiretorio::EntradaDiretorio() {}

EntradaDiretorio::EntradaDiretorio(char *nome, char *extensao, uint primeiroCluster, bool ehArquivo) {
    this->nome = parseNome(nome, p.tamanhoNomeArquivo);
    this->extensao = parseNome(extensao, p.tamanhoExtensaoArquivo);
    this->primeiroCluster = primeiroCluster;
    this->ehAarquivo = ehArquivo;
}

string EntradaDiretorio::normalizaString(string str, uint tamanho) {

    uint comprimento = str.length();
    if (comprimento > tamanho) {
        str.substr(0, tamanho);
    } else {
        if (comprimento < tamanho) {
            for (;comprimento < tamanho; comprimento++) {
                char zero = 0;
                str.push_back(zero);
            }
        }
    }
    return str;
}

char* EntradaDiretorio::string2charVet(string str, uint tamanho) {
    char* c = new char[tamanho];
    for (uint i = 0; i < tamanho; i++) {
        c[i] = str.at(i);
    }

    return c;
}

char *EntradaDiretorio::parseNome(string str, uint tamanho) {
    str = normalizaString(str, tamanho);
    return string2charVet(str, tamanho);
}



QByteArray EntradaDiretorio::toByteArray() {
    QByteArray b;


    int deslocamento = 0;
    b.insert(0, (char*) &this->nome, p.tamanhoNomeArquivo);
    deslocamento += p.tamanhoNomeArquivo;

    b.insert(deslocamento, (char*) &this->extensao, p.tamanhoExtensaoArquivo);
    deslocamento += p.tamanhoExtensaoArquivo;

    b.insert(deslocamento, (char*) &this->primeiroCluster, 4);
    deslocamento += 4;

    b.insert(deslocamento, (char*) &this->tamanhoArquivo, 4);
    deslocamento += 4;

    b.insert(deslocamento, (char*) &this->ehAarquivo, 1);

    return b;

}
