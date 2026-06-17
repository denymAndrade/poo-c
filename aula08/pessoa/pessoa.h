#ifndef PESSOA_H
#define PESSOA_H

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
        virtual void fazerFalar(Pessoa* p) {
            p->falar();
    }
};
void fazerFalar(Pessoa* p) {
            p->falar();
    }

#endif
