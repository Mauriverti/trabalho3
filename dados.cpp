#include "dados.h"

Dados::Dados() {

}

Dados::Dados(QByteArray byteArray) {
    this->dados = byteArray;
}

QByteArray Dados::getDados() {
    return this->dados;
}
