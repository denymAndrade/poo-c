#include "Personagem.h"
#include <iostream>

void Personagem::validarNivelPoder(int nivel) const {
    if (nivel < 1 || nivel > 100) {
        throw std::invalid_argument("Nível de poder deve estar entre 1 e 100");
    }
}

Personagem::Personagem(const std::string& nome, int nivelPoder, const std::string& tipo)
    : nome(nome), nivelPoder(nivelPoder), tipo(tipo) {
    validarNivelPoder(nivelPoder);
}

Personagem::~Personagem() = default;

void Personagem::imprimir() const {
    std::cout << "Nome: " << nome
              << " | Nível de poder: " << nivelPoder
              << " | Tipo: " << tipo;
}

int Personagem::getNivelPoder() const {
    return nivelPoder;
}
