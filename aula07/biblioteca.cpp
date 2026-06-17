#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Biblioteca {
private:
    string nome;
    vector<string> livros;

public:
    Biblioteca(string nomeInicial = "") {
        setNome(nomeInicial); 
    }

    string getNome() {
        return this->nome;
    }

    void setNome(string novo_nome) {
        if (!novo_nome.empty()) {
            this->nome = novo_nome;
        } else {
            cout << "[!] Erro: O nome da biblioteca nao pode ser vazio." << endl;
        }
    }

    void adicionarLivro(string titulo) {
        if (titulo.empty()) {
            cout << "[!] Erro: Titulo invalido (vazio)." << endl;
            return; 
        }

        for (int i = 0; i < livros.size(); i++) {
            if (livros[i] == titulo) {
                cout << "[!] Aviso: O livro '" << titulo << "' ja existe na biblioteca!" << endl;
                return;
            }
        }

        livros.push_back(titulo);
        cout << "[+] Livro adicionado com sucesso: " << titulo << endl;
    }

    void listarLivros() {
        cout << "\n--- Acervo da " << this->nome << " ---" << endl;
        
        if (livros.empty()) {
            cout << "Nenhum livro cadastrado." << endl;
        } else {
            for (int i = 0; i < livros.size(); i++) {
                cout << i + 1 << ". " << livros[i] << endl;
            }
        }
        cout << "--------------------------------------\n" << endl;
    }
};

int main() {
    Biblioteca minhaBiblioteca;
    minhaBiblioteca.setNome("Biblioteca Central");

    cout << "Sistema Iniciado: " << minhaBiblioteca.getNome() << "\n" << endl;

    minhaBiblioteca.adicionarLivro("O Senhor dos Aneis");
    minhaBiblioteca.adicionarLivro("Dom Casmurro");
    minhaBiblioteca.adicionarLivro("1984");

    minhaBiblioteca.adicionarLivro("1984");

    minhaBiblioteca.listarLivros();

    minhaBiblioteca.setNome("Biblioteca Municipal de Roraima");

    cout << ">>> O novo nome da instituicao eh: " << minhaBiblioteca.getNome() << endl;

    return 0;
}