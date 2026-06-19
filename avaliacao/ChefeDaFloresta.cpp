#include "ChefeDaFloresta.h"
#include <iostream>

ChefeDaFloresta::ChefeDaFloresta(const std::string& nome, int nivelPoder, const std::string& tipo, const std::string& reino)
    : Personagem(nome, nivelPoder, tipo), reino(reino) {}

void ChefeDaFloresta::imprimir() const {
    Personagem::imprimir();
    std::cout << " | Reino: " << reino;
}
