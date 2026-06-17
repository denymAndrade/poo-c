#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// CLASSE: Aluno
// ==========================================
class Aluno {
private:
    string nome;
    int idade;
    string curso;

public:
    // Construtor
    Aluno(string nomeInicial, int idadeInicial, string cursoInicial) {
        this->nome = nomeInicial;
        this->idade = idadeInicial;
        this->curso = cursoInicial;
    }

    // Métodos Getter e Setter para Nome
    string getNome() { return this->nome; }
    void setNome(string novoNome) {
        if (!novoNome.empty()) {
            this->nome = novoNome;
        }
    }

    // Métodos Getter e Setter para Idade
    int getIdade() { return this->idade; }
    void setIdade(int novaIdade) {
        if (novaIdade > 0) { // Validação básica: idade não pode ser negativa ou zero
            this->idade = novaIdade;
        }
    }

    // Métodos Getter e Setter para Curso
    string getCurso() { return this->curso; }
    void setCurso(string novoCurso) {
        if (!novoCurso.empty()) {
            this->curso = novoCurso;
        }
    }

    // Método exigido para exibir os dados do aluno
    void apresentar() {
        cout << "- Aluno(a): " << this->nome 
             << " | Idade: " << this->idade 
             << " | Curso: " << this->curso << endl;
    }
};

// ==========================================
// CLASSE: Escola
// ==========================================
class Escola {
private:
    string nome;
    vector<Aluno> alunos; // O Vetor agora guarda objetos do tipo 'Aluno'

public:
    // Construtor
    Escola(string nomeInicial = "") {
        setNome(nomeInicial);
    }

    // Controle de leitura e alteração do nome
    string getNome() { return this->nome; }
    
    void setNome(string novoNome) {
        if (!novoNome.empty()) {
            this->nome = novoNome;
        } else {
            cout << "[!] O nome da escola nao pode ser vazio." << endl;
        }
    }

    // O C++ garante nativamente que 'alunoNovo' seja exclusivamente um objeto da classe Aluno
    void adicionarAluno(Aluno alunoNovo) {
        alunos.push_back(alunoNovo);
        cout << "[+] Matricula confirmada: " << alunoNovo.getNome() << endl;
    }

    // Exibe todos os alunos chamando o método apresentar() de cada um
    void listarAlunos() {
        cout << "\n======================================" << endl;
        cout << "      ALUNOS MATRICULADOS: " << this->nome << endl;
        cout << "======================================" << endl;

        if (alunos.empty()) {
            cout << "Nenhum aluno matriculado." << endl;
        } else {
            // Varre o vetor e chama a função de apresentar de dentro de cada objeto Aluno
            for (int i = 0; i < alunos.size(); i++) {
                alunos[i].apresentar();
            }
        }
        cout << "======================================\n" << endl;
    }
};

// ==========================================
// FUNÇÃO PRINCIPAL (MAIN) - DESAFIO EXTRA
// ==========================================
int main() {
    Escola minhaEscola("Escola Futuro");
    int opcao = -1;

    while (opcao != 0) {
        cout << "\n=== MENU: " << minhaEscola.getNome() << " ===" << endl;
        cout << "1. Cadastrar novo aluno" << endl;
        cout << "2. Listar alunos matriculados" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string nome, curso;
                int idade;

                cout << "\n--- Cadastro de Aluno ---" << endl;
                cout << "Nome: ";
                cin.ignore(); // Limpa o buffer do teclado antes de usar getline
                getline(cin, nome);

                cout << "Idade: ";
                cin >> idade;

                cout << "Curso: ";
                cin.ignore(); // Limpa o buffer do enter apos ler a idade
                getline(cin, curso);

                Aluno novoAluno(nome, idade, curso);
                minhaEscola.adicionarAluno(novoAluno);
                break;
            }
            case 2:
                minhaEscola.listarAlunos();
                break;
            case 0:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    }

    return 0;
}
