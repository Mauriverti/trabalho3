#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <disco.h>
#include <readwrite.h>

class Gerenciador {

private:
    QString nomeDisco;
    ReadWrite rw;
    Disco disco;

    int getTamanhoEmKBytes(int tamanho, string tipoTamanho);
    QByteArray criaVetorVazio(int tamanho);

public:
    Gerenciador();
    string getNomeDisco();
    void setNomeDisco(string nome);

    void abrirDisco();
    bool checaFormato();
    void criaDisco(QString nome, int tamanho, string tipoTamanho);
};

#endif // GERENCIADOR_H
