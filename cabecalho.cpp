#include "cabecalho.h"

Cabecalho::Cabecalho() {}

Cabecalho::Cabecalho(QByteArray byteArray) {
    cout << endl << "tamanho: " << byteArray.size();
    this->setFormato(p.siglaFormato);
    this->setTamanhoCluster(p.tamanhoCluster);
    this->setTamanhoDisco(byteArray.size());
    this->setInicioFAT(p.tamanhoCabecalho);
    this->setTamanhoFAT(((this->tamanhoDisco - p.tamanhoCabecalho)/this->tamanhoCluster)*4);
    this->setInicioDados(p.tamanhoCabecalho+this->tamanhoFAT);
    this->setTamanhoDados(this->tamanhoDisco-p.tamanhoCabecalho-this->tamanhoFAT);

    cout << endl << "formato " <<  this->formato;
    cout << endl << "cluster " << this->tamanhoCluster;
    cout << endl << "disco " << this->tamanhoDisco;
    cout << endl << "inicioFAT " << this->inicioFAT;
    cout << endl << "tamanhoFAT " << this->tamanhoFAT;
    cout << endl << "dados " << this->inicioDados;
    cout << endl << "tamanho Dados " << this->tamanhoDados;
}

ushort Cabecalho::getFormato() {
    return this->formato;
}

void Cabecalho::setFormato(ushort formato) {
    this->formato = formato;
}

uint Cabecalho::getTamanhoCluster() {
    return this->tamanhoCluster;
}

void Cabecalho::setTamanhoCluster(uint tamanhoCluster) {
    this->tamanhoCluster = tamanhoCluster;
}

uint Cabecalho::getTamanhoDisco() {
    return this->tamanhoDisco;
}

void Cabecalho::setTamanhoDisco(uint tamanhoDisco) {
    this->tamanhoDisco = tamanhoDisco;
}

uint Cabecalho::getInicioFAT() {
    return this->inicioFAT;
}

void Cabecalho::setInicioFAT(uint inicioFAT) {
    this->inicioFAT = inicioFAT;
}

uint Cabecalho::getTamanhoFAT() {
    return this->tamanhoFAT;
}

void Cabecalho::setTamanhoFAT(uint tamanhoFAT) {
    this->tamanhoFAT = tamanhoFAT;
}

uint Cabecalho::getInicioDados() {
    return this->inicioDados;
}

void Cabecalho::setInicioDados(uint inicioDados) {
    this->inicioDados = inicioDados;
}

uint Cabecalho::getTamanhoDados() {
    return this->tamanhoDados;
}

void Cabecalho::setTamanhoDados(uint tamanhoDados) {
    this->tamanhoDados = tamanhoDados;
}

void Cabecalho::abrir(QByteArray byteArray) {
    this->formato =         *((ushort *) byteArray.mid(0,2).data());
    this->tamanhoCluster =  *((uint *) byteArray.mid(2,4).data());
    this->tamanhoDisco =    *((uint *) byteArray.mid(6,4).data());
    this->inicioFAT =       *((uint *) byteArray.mid(10,4).data());
    this->tamanhoFAT =      *((uint *) byteArray.mid(14,4).data());
    this->inicioDados =     *((uint *) byteArray.mid(18,4).data());
    this->tamanhoDados =    *((uint *) byteArray.mid(22,4).data());
}

QByteArray Cabecalho::toByteArray() {
    QByteArray b;

    b.insert(0, (char*) &this->formato,        2);
    b.insert(2, (char*) &this->tamanhoCluster, 4);
    b.insert(6, (char*) &this->tamanhoDisco,   4);
    b.insert(10,(char*) &this->inicioFAT,      4);
    b.insert(14,(char*) &this->tamanhoFAT,     4);
    b.insert(18,(char*) &this->inicioDados,    4);
    b.insert(22,(char*) &this->tamanhoDados,   4);

    return b;
}
