#include "gerenciador.h"

Gerenciador::Gerenciador() {

}

string Gerenciador::getNomeDisco() {
    return this->nomeDisco.toStdString();
}

void Gerenciador::setNomeDisco(string nome) {
    this->nomeDisco = QString::fromStdString(nome);
}

void Gerenciador::abrirDisco(QString nome) {

    QByteArray b = rw.lerArquivo(nome);
    if (b == NULL) return;

    cout << endl << "Disco aberto com sucesso!";

    if (checaFormato(b)) {
        cout << endl << "Disco formatado";
        disco.abrir(b, true);
    } else {
        cout << endl << "Disco NAO FORMATADO";
        disco.abrir(b, false);
    }
}

bool Gerenciador::checaFormato(QByteArray b) {
    QString tipo = b.mid(0, 2);
    if ( tipo == "BI" ) {      // verifica o tipo do arquivo
        return true;
    }
    return false;

}

void Gerenciador::formatarDisco(QString nome) {

    this->disco.formatar();

    QByteArray b = disco.toByteArray();

    this->rw.gravaArquivo(nome, b);
    cout << endl << "Disco Formatado";
}

void Gerenciador::criaDisco(QString nome, int tamanho, string tipoTamanho) {
    int tamanhoEmKB = getTamanhoEmKBytes(tamanho, tipoTamanho);
    QByteArray bytes = criaVetorVazio(tamanhoEmKB);

    rw.gravaArquivo(nome, bytes);
}

void Gerenciador::exibirDiretorio(uint posicaoCluster) {
    int statusCluster = disco.getFat().getPosicao(posicaoCluster);
    if (statusCluster == 0) {
        cout << endl << "ERRO: cluster vazio";
    } else {
        exibirPadrao();
        Diretorio cluster = Diretorio(disco.getDados().getCluster(posicaoCluster));
        cluster.exibeConteudo();


//        aki
        //    FAZER MENU AQUI, FAZER COPIA DE ARQUIVO PRA DENTRO E PRA FORA

        int opcao = -1;
        while (opcao != 0) {
        cout << endl << "Opções";
        cout << endl << "0 - Voltar para menu principal";
        cout << endl << "1 - Abrir pasta";
        cout << endl << "2 - Voltar pasta";
        cout << endl << "3 - Add arquivo";
        cout << endl << "4 - Criar pasta";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cout << "\tInforme o indice da pasta a ser aberta: ";
                int indice;
                cin >> indice;

                QList<EntradaDiretorio> entradas = cluster.getEntradas();
                EntradaDiretorio ed = entradas.at(indice);
                uint fatPos = ed.getPrimeiroCluster();
                this->exibirDiretorio(fatPos);

                //this->entradas.a

                // pegar endereco cluster de destino
                // abrir endereco
                break;
            }
            case 2: {
                cout << endl;
                // pegar endereco cluster destino (pasta pai)
                // abrir endereco
                break;
            }
            case 3: {
                // digitar endereco arquivo
                // carregar tamanho do arquivo
                // contar clusters
                // achar clusters vazios
                // quebrar arquivo em clusters
                // jogar no lugar certo
                // arrumar fat
                break;
            }
            case 4: {
                // informar nome
                // achar cluster vazio
                // criar nova pasta
                // setar cluster
                break;
            }
        }


        }
        // criar pasta




    }
}

QByteArray Gerenciador::criaVetorVazio(int tamanho) {

    // monta vetor de 1K vazio
    char _1kb[1024];
    for (int i = 0; i < 1024; i++) {
        _1kb[i] = 0;
    }

    // cria vetor do tamanho especificado
    QByteArray b;
    for (int i = 0; i < tamanho/1024; i++) {
        b.insert(i*1024, (char*) &_1kb , 1024);
    }

    return b;
}

void Gerenciador::exibirPadrao() {
    cout << endl << "nome\t\t\ttamanho";
    cout << endl << ".";
    cout << endl << "..";
}

int Gerenciador::getTamanhoEmKBytes(int tamanho, string tipoTamanho) {

    if (tipoTamanho == "MB") {
        return tamanho * 1024 * 1024;
    } else
    if (tipoTamanho =="GB") {
        return tamanho * 1024 * 1024 * 1024;
    } else
//    if (tipo == "KB")
        return tamanho * 1024;
}
