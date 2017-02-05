#include "entradadiretorio.h"

EntradaDiretorio::EntradaDiretorio() {}

EntradaDiretorio::EntradaDiretorio(char *nome, char *extensao, uint primeiroCluster, bool ehArquivo) {
    this->nome = parseNome(nome, p.tamanhoNomeArquivo);
    this->extensao = parseNome(extensao, p.tamanhoExtensaoArquivo);
    this->primeiroCluster = primeiroCluster;
    this->ehAarquivo = ehArquivo;
}

EntradaDiretorio::EntradaDiretorio(QByteArray byteArray) {
    if (byteArray.size() != p.tamanhoEntradaDiretorio) {
        cout << endl << "ERRO - entrada diretorio invalida";
        return;
    }

    uint deslocamento = 0;
    this->nome = &*((char *) byteArray.mid(deslocamento, p.tamanhoNomeArquivo).data());
    //this->nome = *((char*) byteArray.mid(deslocamento,p.tamanhoNomeArquivo).data());
    deslocamento += p.tamanhoNomeArquivo;
    this->extensao = &*((char *) byteArray.mid(deslocamento, p.tamanhoExtensaoArquivo).data());
//    this->extensao = *((char*) byteArray.mid(deslocamento,p.tamanhoExtensaoArquivo).data());
    deslocamento += p.tamanhoExtensaoArquivo;
    this->primeiroCluster = *((uint *) byteArray.mid(deslocamento,4).data());
    deslocamento += 4;
    this->tamanhoArquivo = *((uint *) byteArray.mid(deslocamento,4).data());
    deslocamento += 4;
    this->ehAarquivo = *((char *) byteArray.mid(deslocamento,1).data());

}

bool EntradaDiretorio::entradaValida() {



    return false;
}

string EntradaDiretorio::toString() {
    string str(this->nome);
    if (this->ehAarquivo) {
        string ext(this->extensao);      // gambiarra pra converter char* em string
        str +=  "." + ext
                + "\t\t1c: " + to_string(this->primeiroCluster)
                + "\t\ttamanho: " + to_string(this->tamanhoArquivo) + " bytes"
                + "\n";
    }
    else {
        str +=  "\t\t1cluster: " + to_string(this->primeiroCluster)
                + "\n";
    }

    return str;
}

uint EntradaDiretorio::getPrimeiroCluster() {
    return this->primeiroCluster;
}

string EntradaDiretorio::normalizaString(string str, uint tamanho) {

    uint comprimento = str.length();
    if (comprimento > tamanho) {
        str.substr(0, tamanho);
    } else {
        if (comprimento < tamanho) {
            for (;comprimento < tamanho; comprimento++) {
                char zero = 0;
                str.push_back(zero);
            }
        }
    }
    return str;
}

char* EntradaDiretorio::string2charVet(string str, uint tamanho) {
    char* c = new char[tamanho];
    for (uint i = 0; i < tamanho; i++) {
        c[i] = str.at(i);
    }

    return c;
}

char *EntradaDiretorio::parseNome(string str, uint tamanho) {
    str = normalizaString(str, tamanho);
    return string2charVet(str, tamanho);
}



QByteArray EntradaDiretorio::toByteArray() {
    QByteArray b;


    int deslocamento = 0;
    b.insert(0, (char*) &this->nome, p.tamanhoNomeArquivo);
    deslocamento += p.tamanhoNomeArquivo;

    b.insert(deslocamento, (char*) &this->extensao, p.tamanhoExtensaoArquivo);
    deslocamento += p.tamanhoExtensaoArquivo;

    b.insert(deslocamento, (char*) &this->primeiroCluster, 4);
    deslocamento += 4;

    b.insert(deslocamento, (char*) &this->tamanhoArquivo, 4);
    deslocamento += 4;

    b.insert(deslocamento, (char*) &this->ehAarquivo, 1);

    return b;

}
