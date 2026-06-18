#include <iostream>
#include <memory>
#include "funcionario.h"
#include "gerente.h"
#include "operario.h"

int main() {
    // Usando construtores e polimorfismo
    std::unique_ptr<Funcionario> f1 = std::make_unique<Funcionario>("Ana", 3500.0, 1001);
    std::unique_ptr<Funcionario> f2 = std::make_unique<Gerente>("Bruno", 7000.0, 1002, "Vendas");
    std::unique_ptr<Funcionario> f3 = std::make_unique<Operario>("Carlos", 2500.0, 1003, 10);

    f1->mostrarDados();
    f2->mostrarDados();

    // Aumentar salário do gerente em 20% e mostrar novamente
    if (Gerente* g = dynamic_cast<Gerente*>(f2.get())) {
        std::cout << "\nAumentando salário do gerente em 20%..." << std::endl;
        g->aumentarSalario20();
        g->mostrarDados();
    }

    f3->mostrarDados();

    return 0;
}
