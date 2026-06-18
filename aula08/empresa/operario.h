#ifndef OPERARIO_H
#define OPERARIO_H

#include "funcionario.h"

class Operario : public Funcionario {
private:
    int horasExtra;
public:
    Operario(const std::string& nome, double salario, int matricula, int horasExtra)
        : Funcionario(nome, salario, matricula), horasExtra(horasExtra) {}

    int getHorasExtra() const { return horasExtra; }
    void setHorasExtra(int h) { horasExtra = h; }

    void mostrarDados() const override {
        std::cout << "Operário - ";
        Funcionario::mostrarDados();
        std::cout << "Horas extra: " << horasExtra << std::endl;
    }
};

#endif // OPERARIO_H
