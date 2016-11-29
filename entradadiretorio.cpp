#include "entradadiretorio.h"

string EntradaDiretorio::cortaString(string str, uint tamanhoMaximo) {
    return str.substr(0,tamanhoMaximo);
}

EntradaDiretorio::EntradaDiretorio() {}

EntradaDiretorio::EntradaDiretorio(string nome, string extensao, uint primeiroCluster, bool ehArquivo) {
    this->nome = cortaString(nome, p.tamanhoNomeArquivo);
    this->extensao = cortaString(extensao, p.tamanhoExtensaoArquivo);
    this->primeiroCluster = primeiroCluster;
    this->ehAarquivo = ehArquivo;
}

QByteArray EntradaDiretorio::toByteArray() {

}
