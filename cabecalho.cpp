#include "cabecalho.h"

Cabecalho::Cabecalho() {

}

string Cabecalho::getFormato() {
    return this->formato;
}

void Cabecalho::setFormato(string formato) {
    this->formato = formato.substr(0,3);
}
