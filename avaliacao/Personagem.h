#pragma once

#include <string>
#include <stdexcept>

class Personagem {
protected:
    std::string nome;
    int nivelPoder;
    std::string tipo;

    void validarNivelPoder(int nivel) const;

public:
    Personagem(const std::string& nome, int nivelPoder, const std::string& tipo);
    virtual ~Personagem();

    virtual void imprimir() const;
    int getNivelPoder() const;
};
