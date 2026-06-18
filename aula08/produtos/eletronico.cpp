#include "eletronico.h"
#include <iostream>

Eletronico::Eletronico(const std::string& nome, double valor, int garantia)
    : Produto(nome, valor), garantiaMeses(garantia) {}

Eletronico::~Eletronico() {}

void Eletronico::setGarantia(int meses) { garantiaMeses = meses; }
int Eletronico::getGarantia() const { return garantiaMeses; }

void Eletronico::mostrar() const {
    Produto::mostrar();
    std::cout << " | Garantia: " << garantiaMeses << " meses\n";
}
