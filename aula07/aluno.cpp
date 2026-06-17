#include <iostream>
#include <string>


using namespace std;


class Aluno {
private:    
    string nome;
    int nota;
public:
    string getNome() const { return nome; } 
    void setNome(const string& n) { nome = n; }
    int getNota() const { return nota; }
    void setNota(double novaNota) {  
        if (novaNota > 0 && novaNota <= 10 ) {
            nota = novaNota;
        } else {
            cout << "Nota invalida!" << endl;
        }
     } 
     void exibir_nota() const {
        cout << "Nome do aluno: " << nome << ", Nota: " << nota << endl;
     }
};

int main() {
    Aluno aluno;
    aluno.setNome("Jose");
    aluno.setNota(8.5);


    aluno.exibir_nota();

    return 0;
}
