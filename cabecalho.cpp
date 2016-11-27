#include "cabecalho.h"

const uint clusterSize = 4 * 1024;
const uint cabecalhoSize = 27;
const uint FATSize = 512;

Cabecalho::Cabecalho() {}

Cabecalho::Cabecalho(QByteArray byteArray) {
    cout << endl << "tamanho: " << byteArray.size();
    this->setFormato("BIR");
    this->setTamanhoCluster(clusterSize);
    this->setTamanhoDisco(byteArray.size());
    this->setInicioFAT(cabecalhoSize);
    this->setTamanhoFAT(FATSize);
    this->setInicioDados(cabecalhoSize+FATSize);
    this->setTamanhoDados(this->getTamanhoDisco()-cabecalhoSize-FATSize);
}

string Cabecalho::getFormato() {
    return this->formato;
}

void Cabecalho::setFormato(string formato) {
    this->formato = formato.substr(0,3);
}

int Cabecalho::getTamanhoCluster() {
    return this->getTamanhoCluster();
}

void Cabecalho::setTamanhoCluster(int tamanhoCluster) {
    this->tamanhoCluster = tamanhoCluster;
}

int Cabecalho::getTamanhoDisco() {
    return this->tamanhoDisco;
}

void Cabecalho::setTamanhoDisco(int tamanhoDisco) {
    this->tamanhoDisco = tamanhoDisco;
}

int Cabecalho::getInicioFAT() {
    return this->getInicioFAT();
}

void Cabecalho::setInicioFAT(int inicioFAT) {
    this->inicioFAT = inicioFAT;
}

int Cabecalho::getTamanhoFAT() {
    return this->tamanhoFAT;
}

void Cabecalho::setTamanhoFAT(int tamanhoFAT) {
    this->tamanhoFAT = tamanhoFAT;
}

int Cabecalho::getInicioDados() {
    return this->inicioDados;
}

void Cabecalho::setInicioDados(int inicioDados) {
    this->inicioDados = inicioDados;
}

int Cabecalho::getTamanhoDados() {
    return this->tamanhoDados;
}

void Cabecalho::setTamanhoDados(int tamanhoDados) {
    this->tamanhoDados = tamanhoDados;
}

QByteArray Cabecalho::toByteArray() {
    QByteArray b;

    b.insert(0, "BIR");
    cout << endl << "EXPLODINDO AQUI";
    b.insert(3, (char*) this->tamanhoCluster, 4);
    b.insert(7, (char*) this->tamanhoDisco,   4);
    b.insert(11,(char*) this->inicioFAT,      4);
    b.insert(15,(char*) this->tamanhoFAT,     4);
    b.insert(19,(char*) this->inicioDados,    4);
    b.insert(23,(char*) this->tamanhoDados,   4);

    return b;
}
