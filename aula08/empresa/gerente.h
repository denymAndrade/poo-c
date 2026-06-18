#ifndef GERENTE_H
#define GERENTE_H

#include "funcionario.h"
#include <string>

class Gerente : public Funcionario {
private:
    std::string setor;
public:
    Gerente(const std::string& nome, double salario, int matricula, const std::string& setor)
        : Funcionario(nome, salario, matricula), setor(setor) {}

    const std::string& getSetor() const { return setor; }
    void setSetor(const std::string& s) { setor = s; }

    void mostrarDados() const override {
        std::cout << "Gerente - ";
        Funcionario::mostrarDados();
        std::cout << "Setor: " << setor << std::endl;
    }
    
    void aumentarSalario20() {
        salario *= 1.20; 
    }
};

#endif // GERENTE_H
