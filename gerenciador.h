#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <disco.h>
#include <readwrite.h>

class Gerenciador {

private:
    QString nomeDisco;
    ReadWrite rw;
    Disco disco;
    static Padroes p;
    Diretorio diretorioAtual;

    int getTamanhoEmKBytes(int tamanho, string tipoTamanho);
    QByteArray criaVetorVazio(int tamanho, bool emKb);

    void exibirPadrao();
    int calculaCluster(int tamanhoArq);
    void addArquivo(QByteArray arquivo, string nomeArquivo);
    QList<QByteArray> fragmentaArquivo(QByteArray arquivo);
    QByteArray preencheCluster(QByteArray ba, int tamanhoAtual, int tamanhoFinal);
    EntradaDiretorio criaEntradaArquivo(QByteArray arquivo, QString nome, int cluster);

    void salvaDisco();

public:
    Gerenciador();
    string getNomeDisco();
    void setNomeDisco(string nome);

    void abrirDisco(QString nome);
    bool checaFormato(QByteArray b);
    void formatarDisco(QString nome);
    void criaDisco(QString nome, int tamanho, string tipoTamanho);

    void exibirDiretorio(uint posicaoCluster);
};

#endif // GERENCIADOR_H
