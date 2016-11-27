#include "gerenciador.h"

Gerenciador::Gerenciador() {

}

string Gerenciador::getNomeDisco() {
    return this->nomeDisco.toStdString();
}

void Gerenciador::setNomeDisco(string nome) {
    this->nomeDisco = QString::fromStdString(nome);
}

void Gerenciador::abrirDisco(QString nome) {

    QByteArray b = rw.lerArquivo(nome);
    if (b == NULL) return;

    cout << endl << "Disco aberto com sucesso!";

    if (checaFormato(b)) {
        cout << endl << "Disco formatado";
        disco.abrir(b);
        rw.gravaArquivo(QString::fromStdString("b"), disco.toByteArray());
    } else {
        cout << endl << "Disco NAO FORMATADO";
    }
}

bool Gerenciador::checaFormato(QByteArray b) {
    QString tipo = b.mid(0, 2);
    if ( tipo == "BI" ) {      // verifica o tipo do arquivo
        return true;
    }
    return false;

}

void Gerenciador::formatarDisco(QString nome) {
    QByteArray b = rw.lerArquivo(nome);

    if (b != NULL) {
        disco = Disco(b);

        b = disco.toByteArray();

        rw.gravaArquivo(nome, b);
        cout << endl << "Disco Formatado";
    }
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
