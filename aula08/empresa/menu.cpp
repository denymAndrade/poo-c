#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <locale.h>
#include <limits>
#include "funcionario.h"
#include "gerente.h"
#include "operario.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void mostrarTodos(const vector<unique_ptr<Funcionario>>& v) {
    cout << "\n--- Lista de Funcionários ---" << endl;
    for (const auto& f : v) {
        f->mostrarDados();
    }
}

Funcionario* encontrarPorMatricula(const vector<unique_ptr<Funcionario>>& v, int matricula) {
    for (const auto& f : v) {
        if (f->getMatricula() == matricula) return f.get();
    }
    return nullptr;
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    vector<unique_ptr<Funcionario>> funcionarios;
    int opcao;

    do {
        cout << "\n=== MENU DE CADASTRO ===" << endl;
        cout << "1 - Cadastrar Funcionário (genérico)" << endl;
        cout << "2 - Cadastrar Gerente" << endl;
        cout << "3 - Cadastrar Operário" << endl;
        cout << "4 - Listar todos" << endl;
        cout << "5 - Mostrar dados por matrícula" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        if (!(cin >> opcao)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        cin.ignore();

        switch (opcao) {
            case 1: {
                string nome; double salario; int matricula;
                cout << "Nome: "; getline(cin, nome);
                cout << "Salário: "; cin >> salario; cout << "Matrícula: "; cin >> matricula; cin.ignore();
                funcionarios.emplace_back(make_unique<Funcionario>(nome, salario, matricula));
                cout << "Funcionário cadastrado." << endl;
                break;
            }
            case 2: {
                string nome, setor; double salario; int matricula;
                cout << "Nome: "; getline(cin, nome);
                cout << "Salário base: "; cin >> salario; cout << "Matrícula: "; cin >> matricula; cin.ignore();
                cout << "Setor: "; getline(cin, setor);
                auto g = make_unique<Gerente>(nome, salario, matricula, setor);
                g->aumentarSalario20(); // aplica 20% a mais usando o método
                funcionarios.emplace_back(move(g));
                cout << "Gerente cadastrado (salário ajustado em +20%)." << endl;
                break;
            }
            case 3: {
                string nome; double salario; int matricula; int horasExtra;
                cout << "Nome: "; getline(cin, nome);
                cout << "Salário: "; cin >> salario; cout << "Matrícula: "; cin >> matricula; cout << "Horas extra: "; cin >> horasExtra; cin.ignore();
                funcionarios.emplace_back(make_unique<Operario>(nome, salario, matricula, horasExtra));
                cout << "Operário cadastrado." << endl;
                break;
            }
            case 4:
                mostrarTodos(funcionarios);
                break;
            case 5: {
                int mat; cout << "Informe a matrícula: "; cin >> mat; cin.ignore();
                Funcionario* f = encontrarPorMatricula(funcionarios, mat);
                if (f) f->mostrarDados(); else cout << "Matrícula não encontrada." << endl;
                break;
            }
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
