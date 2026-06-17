#include <iostream>
#include <string>


using namespace std;

class Pessoa {
    protected:
        string nome;
        int idade;
    public:
        Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
        
        virtual void falar() {
            cout << "Olá, meu nome é " << nome << " e tenho " << idade << " anos." << endl;
        }
        
};
void fazerFalar(Pessoa* p) {
            p->falar();
    }
