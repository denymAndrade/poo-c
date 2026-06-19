#pragma once

#include "Personagem.h"
#include <string>

class ChefeDaFloresta : public Personagem {
private:
    std::string reino;

public:
    ChefeDaFloresta(const std::string& nome, int nivelPoder, const std::string& tipo, const std::string& reino);
    void imprimir() const override;
};
