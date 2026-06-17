#include <iostream>
#include <string>



using namespace std;

class Pessoa {
private:    
    string nome;
    int idade;
public:
    string getNome() const { return nome; }
    void setNome(const string& n) { nome = n; }
    int getIdade() const { return idade; }
    void setIdade(int novaIdade) { 
        if (novaIdade > 0 && novaIdade < 150 ) {
            idade = novaIdade;
        } else {
            cout << "Idade invalida!" << endl;
        }
     }
};

int main() {
   

    Pessoa pessoa;
    pessoa.setNome("Ana");
    pessoa.setIdade(28);

    cout << "Nome da pessoa: " << pessoa.getNome() << ", Idade: " << pessoa.getIdade() << " anos." << endl;

    return 0;
}
