#include <iostream>
#include <cstdlib>
#include <list>
#include <QByteArray>
#include <QFile>
#include <qdebug.h>

using namespace std;

void criaArquivo(QByteArray b, QString fileDir);
void montaArquivo(int tamanho, const string tipo);

int main() {

    cout << "ola" << endl;

    list<int> l;
    list<int>::iterator it;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);


    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << endl;
    }

    montaArquivo(8, "MB");


    return 0;
}


void montaArquivo(int tamanho, const string tipo) {
    int tamanhoEmKBytes;

    if (tipo == "MB") {
        tamanhoEmKBytes = tamanho * 1024 * 1024;
    } else
    if (tipo =="GB") {
        tamanhoEmKBytes = tamanho * 1024 * 1024 * 1024;
    } else
//    if (tipo == "KB") {
        tamanhoEmKBytes = tamanho;

    char _1kb[1024];
    for (int i = 0; i < 1024; i++) {
        _1kb[i] = 0;
    }


    QByteArray b;
    for (int i = 0; i < tamanhoEmKBytes/1024; i++) {
        b.insert(i*1024, (char*) &_1kb , 1024);
    }

    criaArquivo(b, "disco");
}

void criaArquivo(QByteArray b, QString fileDir = "disco") {

    QFile file (fileDir);
    if ( !file.open(QIODevice::WriteOnly) ) {
        qDebug() << "Nao foi possivel abrir arquivo para salvar";
        return;
    }

    file.write(b);
    file.close();

}
