#include "livro.h"
#include <iostream>

Livro::Livro(const std::string& nome, double valor, const std::string& autor)
    : Produto(nome, valor), autor(autor) {}

Livro::~Livro() {}

void Livro::setAutor(const std::string& a) { autor = a; }
std::string Livro::getAutor() const { return autor; }

void Livro::mostrar() const {
    Produto::mostrar();
    std::cout << " | Autor: " << autor << "\n";
}
