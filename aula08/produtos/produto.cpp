#include "produto.h"
#include <iostream>

Produto::Produto(const std::string& nome, double valor)
    : nome(nome), valor(valor) {}

Produto::~Produto() {}

void Produto::setNome(const std::string& n) { nome = n; }
std::string Produto::getNome() const { return nome; }

void Produto::setValor(double v) { valor = v; }
double Produto::getValor() const { return valor; }

void Produto::mostrar() const {
    std::cout << "Nome: " << nome << " | Valor: R$ " << valor;
}
