#include "ArvoreFloresta.h"
#include "ChefeDaFloresta.h"
#include "Personagem.h"
#include "Tipos.h"

#include <iostream>
#include <limits>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

void mostrarMenu() {
    std::cout << "\n=== Floresta Encantada ===\n";
    std::cout << "1. Adicionar personagem\n";
    std::cout << "2. Exibir personagens em ordem\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int obterInteiro(const std::string& texto) {
    int valor;
    while (true) {
        std::cout << texto;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cout << "Valor inválido. Digite um número inteiro.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string obterTexto(const std::string& texto) {
    std::string valor;
    std::cout << texto;
    std::getline(std::cin, valor);
    return valor;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    ArvoreFloresta floresta;

    // Adiciona personagens padrão
    floresta.inserir(new Personagem("Lupi", 35, "Animal"));
    floresta.inserir(new Personagem("Mago Merlin", 80, "Mago"));
    floresta.inserir(new ChefeDaFloresta("Chefe Dragão", 95, "Dragão", "Reino do Fogo"));
    floresta.inserir(new ChefeDaFloresta("Chefe Fae", 70, "Fada", "Reino das Flores"));
    floresta.inserir(new Personagem("Arqueiro Silvestre", 40, "Humano"));
    floresta.inserir(new Personagem("Garrador", 25, "Animal"));

    int opcao = -1;
    while (opcao != 0) {
        mostrarMenu();
        opcao = obterInteiro("");

        switch (opcao) {
            case 1: {
                std::cout << "\n=== Tipos de Personagem ===\n";
                std::cout << "1 - " << TiposValidos::getTipoNome(TipoPersonagem::ANIMAL) << "\n";
                std::cout << "2 - " << TiposValidos::getTipoNome(TipoPersonagem::MAGO) << "\n";
                std::cout << "3 - " << TiposValidos::getTipoNome(TipoPersonagem::DRAGAO) << "\n";
                std::cout << "4 - " << TiposValidos::getTipoNome(TipoPersonagem::FADA) << "\n";
                std::cout << "5 - " << TiposValidos::getTipoNome(TipoPersonagem::HUMANO) << "\n";
                std::cout << "6 - Chefe da Floresta (com reino)\n";

                int tipoEscolha = obterInteiro("Escolha o tipo: ");
                
                std::string nome = obterTexto("Nome: ");
                int nivel = -1;

                while (!TiposValidos::validarNivelPoder(nivel)) {
                    nivel = obterInteiro("Nível de poder (1-100): ");
                    if (!TiposValidos::validarNivelPoder(nivel)) {
                        std::cout << "Nível inválido! Deve estar entre 1 e 100.\n";
                    }
                }

                try {
                    switch (tipoEscolha) {
                        case 1: {
                            auto animais = TiposValidos::getAnimaisValidos();
                            std::cout << "\nAnimais disponíveis: ";
                            for (size_t i = 0; i < animais.size(); i++) {
                                std::cout << animais[i];
                                if (i < animais.size() - 1) std::cout << ", ";
                            }
                            std::cout << "\n";
                            floresta.inserir(new Personagem(nome, nivel, TiposValidos::getTipoNome(TipoPersonagem::ANIMAL)));
                            break;
                        }
                        case 2: {
                            auto magos = TiposValidos::getMagosValidos();
                            std::cout << "\nMagos disponíveis: ";
                            for (size_t i = 0; i < magos.size(); i++) {
                                std::cout << magos[i];
                                if (i < magos.size() - 1) std::cout << ", ";
                            }
                            std::cout << "\n";
                            floresta.inserir(new Personagem(nome, nivel, TiposValidos::getTipoNome(TipoPersonagem::MAGO)));
                            break;
                        }
                        case 3: {
                            auto dragoes = TiposValidos::getDragoesValidos();
                            std::cout << "\nDragões disponíveis: ";
                            for (size_t i = 0; i < dragoes.size(); i++) {
                                std::cout << dragoes[i];
                                if (i < dragoes.size() - 1) std::cout << ", ";
                            }
                            std::cout << "\n";
                            floresta.inserir(new Personagem(nome, nivel, TiposValidos::getTipoNome(TipoPersonagem::DRAGAO)));
                            break;
                        }
                        case 4: {
                            auto fadas = TiposValidos::getFadasValidas();
                            std::cout << "\nFadas disponíveis: ";
                            for (size_t i = 0; i < fadas.size(); i++) {
                                std::cout << fadas[i];
                                if (i < fadas.size() - 1) std::cout << ", ";
                            }
                            std::cout << "\n";
                            floresta.inserir(new Personagem(nome, nivel, TiposValidos::getTipoNome(TipoPersonagem::FADA)));
                            break;
                        }
                        case 5: {
                            auto humanos = TiposValidos::getHumanosValidos();
                            std::cout << "\nHumanos disponíveis: ";
                            for (size_t i = 0; i < humanos.size(); i++) {
                                std::cout << humanos[i];
                                if (i < humanos.size() - 1) std::cout << ", ";
                            }
                            std::cout << "\n";
                            floresta.inserir(new Personagem(nome, nivel, TiposValidos::getTipoNome(TipoPersonagem::HUMANO)));
                            break;
                        }
                        case 6: {
                            std::string reino = obterTexto("Reino: ");
                            floresta.inserir(new ChefeDaFloresta(nome, nivel, "Chefe", reino));
                            break;
                        }
                        default:
                            std::cout << "Tipo inválido!\n";
                            continue;
                    }
                    std::cout << "Personagem adicionado com sucesso! (Nível: " << nivel << " - " 
                              << TiposValidos::descricaoNivelPoder(nivel) << ")\n";
                } catch (const std::invalid_argument& e) {
                    std::cout << "Erro: " << e.what() << "\n";
                }
                break;
            }
            case 2:
                floresta.percorrerEmOrdem();
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }

    return 0;
}
