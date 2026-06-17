#include <iostream>
#include <string>
#include "pessoa.cpp"

using namespace std;

class Professor : public Pessoa {
    private:
        string disciplina;
    public:
        Professor(string nome, string disciplina) : Pessoa(nome), disciplina(disciplina) {}
        
        void falar() override {
            cout << "Olá, meu nome é " << nome << " e eu ensino " << disciplina << "." << endl;
        }
};