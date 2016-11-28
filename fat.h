#ifndef FAT_H
#define FAT_H

using namespace std;

class Fat {

private:
    uint tamanho;
    int clusters[];

public:
    Fat();
    Fat(uint tamanho);
    void getPosicao(uint posicao);
    void setPosicao(uint posicao, int valor);
    uint achaPrimeiroLivre();

};

#endif // FAT_H
