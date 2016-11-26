#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <cabecalho.h>
#include <readwrite.h>

class Gerenciador {

private:
    QString nomeDisco;

    void criaArquivo(QByteArray b, QString fileDir);
    int getTamanhoEmKBytes(int tamanho, string tipoTamanho);
    QByteArray criaVetorVazio(int tamanho);

public:
    Gerenciador();
    bool checaFormato();
    void criaDisco(QString nome, int tamanho, string tipoTamanho);

    string getNomeDisco();
    void setNomeDisco(string nome);
};

#endif // GERENCIADOR_H
