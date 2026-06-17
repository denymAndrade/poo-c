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
    // 1. Crie uma escola chamada “Escola Futuro”.
    Escola minhaEscola("Escola Futuro");

    // Teste inicial: tentar listar antes de ter alunos
    minhaEscola.listarAlunos();

    // 2. Crie 2 alunos com nome, idade e curso.
    Aluno a1("Carlos Eduardo", 20, "Logica de Programacao");
    Aluno a2("Mariana Silva", 22, "Banco de Dados");

    // 3. Teste alterações de atributos usando os métodos set.
    cout << "--- Testando validacoes (SET) ---" << endl;
    minhaEscola.setNome("Escola Futuro Tech"); // Alterando nome da Escola
    a1.setIdade(21); // Alterando idade do Carlos
    a2.setCurso("Arquitetura da Informacao"); // Alterando curso da Mariana
    cout << "Dados atualizados via Setters com sucesso!\n" << endl;

    // 4. Adicione os alunos à escola.
    minhaEscola.adicionarAluno(a1);
    minhaEscola.adicionarAluno(a2);

    // 5. Exiba a lista de alunos matriculados.
    minhaEscola.listarAlunos();

    return 0;
}
