#include "readwrite.h"

ReadWrite::ReadWrite() {

}


void ReadWrite::gravaArquivo(QString diretorio, QByteArray informacao) {

    if (!informacao.size()) {
        qDebug() << "\nNao e possivel salvar um arquivo vazio";
    }

    QFile file (diretorio);
    if ( !file.open(QIODevice::WriteOnly) ) {
        qDebug() << "\nNao foi possivel abrir arquivo para salvar";
        return;
    }

    file.write(informacao);
    file.close();
}
