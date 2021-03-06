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
    this->nomeDisco = nome;

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
    QByteArray bytes = criaVetorVazio(tamanhoEmKB, true);

    rw.gravaArquivo(nome, bytes);
}

void Gerenciador::exibirDiretorio(uint posicaoCluster) {
    int statusCluster = disco.getFat().getPosicao(posicaoCluster);
    if (statusCluster == 0) {
        cout << endl << "ERRO: cluster vazio";
    } else {
        this->diretorioAtual = Diretorio(disco.getDados().getCluster(posicaoCluster));
        this->diretorioAtual.exibeConteudo();

        int opcao = -1;
        while (opcao != 0) {
            cout << endl << "0 - Voltar para menu principal";
            cout << endl << "1 - Abrir pasta";
            cout << endl << "2 - Voltar pasta";
            cout << endl << "3 - Add arquivo";
            cout << endl << "4 - Criar pasta";
            cout << endl << "5 - Corrigir arquivo";
            cout << endl << "6 - Mostrar toda a FAT";
            cout << endl << "7 - Modificar FAT";
            cout << endl << "8 - Mostrar conteudo da pasta atual";
            cout << endl << "9 - Extrair arquivo";
            cout << endl;
            cin >> opcao;

            switch (opcao) {
                case 1: {
                    cout << "\tInforme o indice da pasta a ser aberta: ";
                    int indice;
                    cin >> indice;

                    QList<EntradaDiretorio> entradas = this->diretorioAtual.getEntradas();
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
                    this->exibirDiretorio(this->diretorioAtual.getClusterPai());
                    break;
                }
                case 3: {
                    cout << "Informe o nome do arquivo: ";
                    string arqNome;
                    cin >> arqNome;
                    QByteArray arq = rw.lerArquivo(QString::fromStdString(arqNome));
                    addArquivo(arq, arqNome);
                    this->salvaDisco();
                    break;
                }
                case 4: {
                    // informar nome
                    // achar cluster vazio
                    // criar nova pasta
                    // setar cluster
                    break;
                }
                case 5: {
                    QList<EntradaDiretorio> entradas = this->diretorioAtual.getEntradas();

                    for (EntradaDiretorio ed: entradas) {
                        if (ed.getEhArquivo()) {
                            if (this->validaArquivo(ed.getTamanhoArquivo(), ed.getPrimeiroCluster())) {
                                cout << endl << ed.getFullname().toStdString() << " esta OK!";
                            } else {
                                cout << endl << ed.getFullname().toStdString() << " esta Corrompido!";
                            }
                        }
                    }
                    cout << endl << endl;

                    // comecar a varrer arquivo

                    // verificar irregularidade
                    // verificar ciclo
                        // criar lista de inteiro com posicoes já acessadas
                        // verificar lista a cada insercao
                            // se ciclo aparece exatamente no ultimo cluster,       CORRECAO
                            // se ciclo aparece apos o ultimo cluster necessario    CORRECAO
                            // se ciclo aparece antes do ultimo cluster             ERRO FATAL

                    // qtd de clusters > necessario                                 CORRECAO
                    // qtd de clusters < necessario                                 ERRO FATAL
                    break;
                }
                case 6: {
                    this->disco.mostraFat();
                    break;
                }
                case 7: {
                    cout << endl << "Informe a posicao e o valor que deseja alterar";
                    int pos, valor;
                    cout << endl << "Posicao: ";
                    cin >> pos;
                    cout << endl << "Valor: ";
                    cin >> valor;
                    this->disco.setPosicaoFat(pos, valor);
                    break;
                }
                case 8: {
                    QList<EntradaDiretorio> entradas = this->diretorioAtual.getEntradas();
                    for (EntradaDiretorio ed: entradas) {
                        cout << endl << ed.toString().toStdString();
                    }
                    break;
                }
                case 9: {
                    QString nomeArq;
                    cout << endl << "Informe o nome do arquivo que deseja extrair: ";
                    string nome;
                    cin >> nome;
                    nomeArq = QString::fromStdString(nome);
                    QList<EntradaDiretorio> entradas = this->diretorioAtual.getEntradas();
                    for (EntradaDiretorio ed: entradas) {
                        if (ed.getFullname() == nomeArq) {
                            this->extraiArquivo(ed);
                            break;
                        }
                    }
                    cout << endl << "Arquivo nao existe neste diretorio";
                }
            }
        }
    }
}

QByteArray Gerenciador::criaVetorVazio(int tamanho, bool emKb) {

    QByteArray b;
    if (emKb) {
        // monta vetor de 1K vazio
        char _1kb[1024];
        for (int i = 0; i < 1024; i++) {
            _1kb[i] = 0;
        }

        // cria vetor do tamanho especificado
        for (int i = 0; i < tamanho/1024; i++) {
            b.insert(i*1024, (char*) &_1kb , 1024);
        }
    } else {
        char _1b = 0;

        for (int i = 0; i < tamanho; i++) {
            b.insert(i, (char*) &_1b, 1);
        }
    }

    return b;
}

int Gerenciador::calculaCluster(int tamanhoArq) {
    int numeroClusters = tamanhoArq/this->p.tamanhoCluster;
    if (tamanhoArq%this->p.tamanhoCluster != 0) numeroClusters++;
    return numeroClusters;
}

void Gerenciador::addArquivo(QByteArray arquivo, string nomeArquivo) {
    int tamanhoArq = arquivo.size();
    int qtdCluster = calculaCluster(tamanhoArq);
    if (!this->disco.getFat().temEspaco(qtdCluster)) {
        cout << endl << "Nao ha espaco suficiente no disco";
        return;
    }
    QList<QByteArray> arquivoFragmentado = fragmentaArquivo(arquivo);

    int posCluster = this->disco.getFat().achaPrimeiroLivre();
    EntradaDiretorio ed = criaEntradaArquivo(arquivo, QString::fromStdString(nomeArquivo), posCluster);

    this->diretorioAtual.addEntrada(ed);
    this->atualizaDiretorio();

    int posProxCluster;
    for (int i = 0; i < qtdCluster; i++) {
        this->disco.setPosicaoFat(posCluster, -1);
        this->disco.setClusterDados(posCluster, arquivoFragmentado.at(i));
        if (i <(qtdCluster-1)) {
            posProxCluster = this->disco.getFat().achaPrimeiroLivre();
            this->disco.setPosicaoFat(posCluster, posProxCluster);
            posCluster = posProxCluster;
        }
    }
    this->atualizaDiretorio();
}

QList<QByteArray> Gerenciador::fragmentaArquivo(QByteArray arquivo) {
    QList<QByteArray> arquivoFragmentado;

    int tamanho = arquivo.size();
    int qtdCluster = calculaCluster(tamanho);
    int pos = 0;
    for (int i = 0; i < (qtdCluster-1); i++) {
        QByteArray fragmento = arquivo.mid(pos, p.tamanhoCluster);
        arquivoFragmentado.append(fragmento);
        pos += p.tamanhoCluster;
    }

    QByteArray fragmentoFinal = arquivo.mid(pos);

    fragmentoFinal = preencheCluster(fragmentoFinal, fragmentoFinal.size(), p.tamanhoCluster);

    arquivoFragmentado.append(fragmentoFinal);

    return arquivoFragmentado;
}

QByteArray Gerenciador::preencheCluster(QByteArray ba, int tamanhoAtual, int tamanhoFinal) {
    int tamanho = tamanhoFinal-tamanhoAtual;
    return ba.append(criaVetorVazio(tamanho, false));
}

EntradaDiretorio Gerenciador::criaEntradaArquivo(QByteArray arquivo, QString nomeArq, int cluster) {
    int splitPos = nomeArq.lastIndexOf('.');
    QString nome = nomeArq.left(splitPos);
    QString extensao = nomeArq.mid(splitPos+1);
    EntradaDiretorio ed(nome, extensao, arquivo.size(), cluster, true);

    return ed;
}

bool Gerenciador::validaArquivo(uint tamanho, uint primeiroCluster) {
    uint qtdCluster = this->calculaCluster(tamanho);

    return this->disco.getFat().checaArquivo(primeiroCluster, qtdCluster);
}

void Gerenciador::salvaDisco() {
    QByteArray disco;
    disco = this->disco.toByteArray();
    rw.gravaArquivo(this->nomeDisco, disco);
}

void Gerenciador::atualizaDiretorio() {
    int pos = this->diretorioAtual.getClusterAtual();
    QByteArray dir = this->diretorioAtual.toByteArray();
    this->disco.setClusterDados(pos, dir);
}

void Gerenciador::extraiArquivo(EntradaDiretorio ed) {
    QString nomeSaida = ed.getFullname();
    QByteArray arquivoSaida;

    int cluster = ed.getPrimeiroCluster();

    while (cluster != -1) {
        arquivoSaida.append(this->disco.getDados().getCluster(cluster));
        cluster = this->disco.getFat().getPosicao(cluster);
    }

    arquivoSaida = arquivoSaida.mid(0, ed.getTamanhoArquivo());    // remove os bytes 0 no final do arquivo

    this->rw.gravaArquivo(nomeSaida, arquivoSaida);
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
