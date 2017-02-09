#include "disco.h"

Disco::Disco() {

}

Disco::Disco(QByteArray byteArray) {
    cabecalho = Cabecalho(byteArray);
    fat.formatar();
    dados.formatar();
}

Cabecalho Disco::getCabecalho() {
    return this->cabecalho;
}

void Disco::setCabecalho(Cabecalho c) {
    this->cabecalho = c;
}

void Disco::setFat(Fat fat) {
    this->fat = fat;
}

Fat Disco::getFat() {
    return this->fat;
}

Dados Disco::getDados() {
    return this->dados;
}

void Disco::formatar() {
    fat.formatar();
    dados.formatar();
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

void Disco::abrir(QByteArray byteArray, bool formatado) {
    if (formatado)
        cabecalho.abrir(byteArray);
    else
        cabecalho = Cabecalho(byteArray);
    fat = Fat(byteArray.mid(cabecalho.getInicioFAT(), cabecalho.getTamanhoFAT()));
    dados = Dados(byteArray.mid(cabecalho.getInicioDados()));
}

void Disco::setPosicaoFat(int posicao, int valor) {
    this->fat.setPosicao(posicao, valor);
}

void Disco::setClusterDados(int posicao, QByteArray dados) {
    this->dados.setCluster(posicao, dados);
}

void Disco::mostraFat() {
    this->fat.exibeFat();
}
