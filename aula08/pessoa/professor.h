#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "pessoa.h"

class Professor : public Pessoa {
    private:
        string disciplina;
    public:
        Professor(string nome, int idade, string disciplina) : Pessoa(nome, idade), disciplina(disciplina) {}
        
        void falar() override {
            cout << "Olá, meu nome é " << nome << " e eu ensino " << disciplina << "." << endl;
        }
};

#endif
