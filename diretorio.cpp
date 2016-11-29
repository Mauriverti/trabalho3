#include "diretorio.h"

Diretorio::Diretorio() {}

Diretorio::Diretorio(uint atual, uint pai) {
    this->clusterAtual = atual;
    this->clusterPai = pai;
}
