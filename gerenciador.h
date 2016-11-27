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

    string FORMATO = "BIR";

public:
    Gerenciador();
    string getNomeDisco();
    void setNomeDisco(string nome);

    void abrirDisco(QString nome);
    bool checaFormato(QByteArray b);
    void formatarDisco(QString nome);
    void criaDisco(QString nome, int tamanho, string tipoTamanho);
};

#endif // GERENCIADOR_H
