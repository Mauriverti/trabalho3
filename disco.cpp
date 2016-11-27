#include "disco.h"

Disco::Disco() {

}

Disco::Disco(QByteArray byteArray) {
    cabecalho = Cabecalho(byteArray);
}

Cabecalho Disco::getCabecalho() {
    return this->cabecalho;
}

void Disco::setCabecalho(Cabecalho c) {
    this->cabecalho = c;
}

QByteArray Disco::toByteArray() {
    QByteArray b;

    b.insert(0, cabecalho.toByteArray());

    return b;
}
