#include "entradadiretorio.h"

EntradaDiretorio::EntradaDiretorio() {}

EntradaDiretorio::EntradaDiretorio(QString nome, QString extensao, uint tamanhoArquivo, uint primeiroCluster, bool ehArquivo) {
    this->nome = normalizaString(nome, p.tamanhoNomeArquivo);
    this->extensao = normalizaString(extensao, p.tamanhoExtensaoArquivo);
    this->tamanhoArquivo = tamanhoArquivo;
    this->primeiroCluster = primeiroCluster;
    this->ehAarquivo = ehArquivo;
}

EntradaDiretorio::EntradaDiretorio(QByteArray byteArray) {
    if (byteArray.size() != p.tamanhoEntradaDiretorio) {
        cout << endl << "ERRO - entrada diretorio invalida";
        return;
    }

    uint deslocamento = 0;
    QString s;

    this->nome = &*((char*) byteArray.mid(deslocamento,p.tamanhoNomeArquivo).data());
    deslocamento += p.tamanhoNomeArquivo;
    this->extensao = &*((char *) byteArray.mid(deslocamento, p.tamanhoExtensaoArquivo).data());
//    this->extensao = *((char*) byteArray.mid(deslocamento,p.tamanhoExtensaoArquivo).data());
    deslocamento += p.tamanhoExtensaoArquivo;
    this->primeiroCluster = *((uint *) byteArray.mid(deslocamento,4).data());
    deslocamento += 4;
    this->tamanhoArquivo = *((uint *) byteArray.mid(deslocamento,4).data());
    deslocamento += 4;
    this->ehAarquivo = *((char *) byteArray.mid(deslocamento,1).data());

}

bool EntradaDiretorio::entradaValida() {

    if (this->nome.size() && (this->primeiroCluster != 0)) return true;

    return false;
}

QString EntradaDiretorio::toString() {
    QString str = this->nome.trimmed();
    if (this->ehAarquivo) {
        str.append(".");
        str.append(this->extensao);
        str.append("\t\t1c: ");
        str.append(QString::number(this->primeiroCluster));
        str.append("\t\ttamanho: ");
        str.append(QString::number(this->tamanhoArquivo));
        str.append(" bytes\n");
    }
    else {
        str.append("\t\t1cluster: ");
        str.append(this->primeiroCluster);
        str.append("\n");
    }

    return str;
}

uint EntradaDiretorio::getPrimeiroCluster() {
    return this->primeiroCluster;
}

QString EntradaDiretorio::normalizaString(QString str, uint tamanho) {

    uint length = str.length();
    if (length > tamanho) {
        str.truncate(tamanho);
    } else {
        for (uint i = length; i < tamanho; i++) {
            str.append(' ');
        }
    }
    return str;
}

QByteArray EntradaDiretorio::toByteArray() {
    QByteArray b;

    int deslocamento = 0;
    const char* s = this->nome.toStdString().c_str();
    b.insert(0, (char*) &s, p.tamanhoNomeArquivo);
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
