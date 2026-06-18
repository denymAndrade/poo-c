#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include <iomanip>

class Funcionario {
protected:
    std::string nome;
    double salario;
    int matricula;

public:
    Funcionario(const std::string& nome, double salario, int matricula)
        : nome(nome), salario(salario), matricula(matricula) {}

    virtual ~Funcionario() = default;

    const std::string& getNome() const { return nome; }
    double getSalario() const { return salario; }
    int getMatricula() const { return matricula; }

    void setNome(const std::string& novoNome) { nome = novoNome; }
    void setSalario(double novoSalario) { salario = novoSalario; }
    void setMatricula(int novaMatricula) { matricula = novaMatricula; }

    virtual void mostrarDados() const {
        std::cout << "Nome: " << nome
                  << ", Salário: " << std::fixed << std::setprecision(2) << salario
                  << std::defaultfloat << ", Matrícula: " << matricula
                  << std::endl;
    }
};

#endif // FUNCIONARIO_H
