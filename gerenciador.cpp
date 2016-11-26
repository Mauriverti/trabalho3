#include "gerenciador.h"

Gerenciador::Gerenciador() {

}

string Gerenciador::getNomeDisco() {
    return this->nomeDisco.toStdString();
}

void Gerenciador::setNomeDisco(string nome) {
    this->nomeDisco = QString::fromStdString(nome);
}

void Gerenciador::abrirDisco() {

    QByteArray b = rw.lerArquivo(this->nomeDisco);
    if (b == NULL) return;

    QString tipo = b.mid(0, 3);
    if ( tipo == "BIR" ) {      // verifica o tipo do arquivo
        cout << endl << "Disco aberto com sucesso" << endl;
    } else {
        cout << endl << "Disco aberto porem NAO FORMATADO" << endl;
    }
}

bool Gerenciador::checaFormato() {

    return true;
}

void Gerenciador::criaDisco(QString nome, int tamanho, string tipoTamanho) {
    int tamanhoEmKB = getTamanhoEmKBytes(tamanho, tipoTamanho);
    QByteArray bytes = criaVetorVazio(tamanhoEmKB);

    rw.gravaArquivo(nome, bytes);
}

QByteArray Gerenciador::criaVetorVazio(int tamanho) {

    // monta vetor de 1K vazio
    char _1kb[1024];
    for (int i = 0; i < 1024; i++) {
        _1kb[i] = 0;
    }

    // cria vetor do tamanho especificado
    QByteArray b;
    for (int i = 0; i < tamanho/1024; i++) {
        b.insert(i*1024, (char*) &_1kb , 1024);
    }

    return b;
}

int Gerenciador::getTamanhoEmKBytes(int tamanho, string tipoTamanho) {

    if (tipoTamanho == "MB") {
        return tamanho * 1024 * 1024;
    } else
    if (tipoTamanho =="GB") {
        return tamanho * 1024 * 1024 * 1024;
    } else
//    if (tipo == "KB")
        return tamanho * 1024;
}
