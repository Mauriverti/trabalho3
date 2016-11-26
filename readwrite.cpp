#include "readwrite.h"

ReadWrite::ReadWrite() {

}

QByteArray ReadWrite::lerArquivo(QString diretorio) {
    validaDiretorio(diretorio);
    QFile* file = abrirArquivoLeitura(diretorio);

    if (file != NULL) {
        return file->readAll();
    } else {
        return NULL;
    }
}

bool ReadWrite::validaInformacao(QByteArray informacao) {
    if (!informacao.size()) {
        qDebug() << "\nNao e possivel salvar um arquivo vazio";
        return false;
    }
    return true;
}

bool ReadWrite::validaDiretorio(QString diretorio) {
    if (!diretorio.size()) {
        qDebug() << "\nDiretorio vazio";
        return false;
    }
    return true;
}



QFile* ReadWrite::abrirArquivoLeitura(QString diretorio) {

    QFile* file = new QFile(diretorio);
    if ( !file->open(QIODevice::ReadOnly) ) {
        qDebug() << "\nNao foi possivel abrir arquivo para leitura";
        return NULL;
    }
    return file;
}

QFile* ReadWrite::abrirArquivoEscrita(QString diretorio) {

    QFile* file = new QFile(diretorio);
    if ( !file->open(QIODevice::WriteOnly) ) {
        qDebug() << "\nNao foi possivel abrir arquivo para salvar";
        return NULL;
    }

    return file;
}


void ReadWrite::gravaArquivo(QString diretorio, QByteArray informacao) {
    if (validaDiretorio(diretorio) && validaInformacao(informacao)) {
        QFile* file = abrirArquivoEscrita(diretorio);
        if (file != NULL) {
            file->write(informacao);
            file->close();
        }
    }
}
