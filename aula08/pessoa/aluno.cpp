#include <iostream>
#include <string>
#include "pessoa.cpp"

using namespace std;

class Aluno : public Pessoa {
    private:
        int matricula   ;
    public:
        Aluno(string nome, int matricula) : Pessoa(nome), matricula(matricula) {}
        
        void falar() override {
            cout << "Olá, meu nome é " << nome << " e minha matrícula é " << matricula << "." << endl;
        }  
        void fazerFalar(Pessoa* p) {
            p ->falar();
        }
};