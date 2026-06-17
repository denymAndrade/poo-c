#include <iostream>
#include <vector>
#include <string>

class Restaurante {
private:
    std::string nome;
    std::vector<std::string> cardapio;

public:
    // Construtor
    Restaurante(std::string nome_inicial) : nome(nome_inicial) {}

    // Getter
    std::string get_nome() {
        return nome;
    }

    // Setter com validação
    void set_nome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        }
    }

    void adicionarPrato(std::string prato) {
        // Verifica se o prato já existe antes de adicionar
        for (const auto& p : cardapio) {
            if (p == prato) return; 
        }
        cardapio.push_back(prato);
    }

    void listarCardapio() {
        std::cout << "--- Cardapio ---" << std::endl;
        for (const auto& prato : cardapio) {
            std::cout << "- " << prato << std::endl;
        }
    }

    void atenderCliente(std::string nome_cliente, std::string prato) {
        bool encontrado = false;
        for (const auto& p : cardapio) {
            if (p == prato) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            std::cout << "[" << nome_cliente << "]: Pedido confirmado (" << prato << ")." << std::endl;
        } else {
            std::cout << "[" << nome_cliente << "]: Erro - O prato '" << prato << "' nao existe." << std::endl;
        }
    }
};
int main() {
    Restaurante meuRestaurante("Sabor de Casa");
    meuRestaurante.adicionarPrato("Feijoada");
    meuRestaurante.adicionarPrato("Churrasco");
    meuRestaurante.adicionarPrato("Lasanha");

    std::cout << "Bem-vindo ao restaurante " << meuRestaurante.get_nome() << "!" << std::endl;
    meuRestaurante.listarCardapio();

    meuRestaurante.atenderCliente("Maria", "Feijoada");
    meuRestaurante.atenderCliente("Joao", "Pizza");

    meuRestaurante.set_nome("Sabor Caseiro Premium");std::cout << "Novo nome: " << meuRestaurante.get_nome() << std::endl;

    return 0;
}