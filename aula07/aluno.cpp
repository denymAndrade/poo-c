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
};

int main() {
    Aluno aluno;
    aluno.setNome("Jose");
    aluno.setNota(8.5);

    cout << "Nome do aluno: " << aluno.getNome() << ", Nota: " << aluno.getNota() << endl;

    return 0;
}
