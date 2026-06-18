#include <iostream>
#include <vector>
#include <memory>
#include <limits>

#include "produto.h"
#include "livro.h"
#include "eletronico.h"

using namespace std;

void limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<unique_ptr<Produto>> produtos;
    int opc = 0;

    do {
        cout << "\n== Menu Produtos ==\n";
        cout << "1. Adicionar Livro\n";
        cout << "2. Adicionar Eletronico\n";
        cout << "3. Listar Produtos\n";
        cout << "4. Remover Produto\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opcao: ";
        if (!(cin >> opc)) { limparEntrada(); cout << "Entrada invalida\n"; continue; }

        if (opc == 1) {
            limparEntrada();
            string nome, autor;
            double valor;
            cout << "Nome do livro: "; getline(cin, nome);
            cout << "Autor: "; getline(cin, autor);
            cout << "Valor: "; cin >> valor;
            produtos.push_back(make_unique<Livro>(nome, valor, autor));
            cout << "Livro adicionado.\n";
        } else if (opc == 2) {
            limparEntrada();
            string nome;
            double valor;
            int garantia;
            cout << "Nome do eletronico: "; getline(cin, nome);
            cout << "Valor: "; cin >> valor;
            cout << "Garantia (meses): "; cin >> garantia;
            produtos.push_back(make_unique<Eletronico>(nome, valor, garantia));
            cout << "Eletronico adicionado.\n";
        } else if (opc == 3) {
            cout << "\nLista de produtos:\n";
            for (size_t i = 0; i < produtos.size(); ++i) {
                cout << i+1 << ") "; produtos[i]->mostrar();
            }
            if (produtos.empty()) cout << "(vazio)\n";
        } else if (opc == 4) {
            if (produtos.empty()) { cout << "Nenhum produto para remover.\n"; continue; }
            cout << "Indice do produto para remover (1.." << produtos.size() << "): ";
            size_t idx; if (!(cin >> idx)) { limparEntrada(); cout << "Entrada invalida\n"; continue; }
            if (idx < 1 || idx > produtos.size()) { cout << "Indice invalido\n"; continue; }
            produtos.erase(produtos.begin() + (idx-1));
            cout << "Produto removido.\n";
        } else if (opc == 5) {
            cout << "Saindo...\n";
        } else {
            cout << "Opcao invalida\n";
        }

    } while (opc != 5);

    return 0;
}
