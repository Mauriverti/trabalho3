#include "disco.h"

Disco::Disco() {

}

Disco::Disco(QByteArray byteArray) {
    cabecalho = Cabecalho(byteArray);
    QByteArray _fat = byteArray.mid(cabecalho.getInicioFAT(), cabecalho.getTamanhoFAT());
    cout << endl << "bytearray FAT: " << _fat.size();
    fat = Fat(_fat);
    dados = Dados(byteArray.mid(cabecalho.getInicioDados()));
}

Cabecalho Disco::getCabecalho() {
    return this->cabecalho;
}

void Disco::setCabecalho(Cabecalho c) {
    this->cabecalho = c;
}

QByteArray Disco::toByteArray() {
    cout << endl << "toByteArray";
    QByteArray b;

    b.insert(0, cabecalho.toByteArray());
    cout << endl << "cabecalho " << cabecalho.toByteArray().size();
    b.insert(this->cabecalho.getInicioFAT(), fat.getTable());
    cout << endl << "fat " << fat.getTable().size();
    b.insert(this->cabecalho.getInicioDados(), dados.getDados());
    cout << endl << "dados " << dados.getDados().size();

    return b;
}

void Disco::abrir(QByteArray byteArray) {
    cabecalho.abrir(byteArray);
}
