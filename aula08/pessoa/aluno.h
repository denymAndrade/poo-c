#ifndef ALUNO_H
#define ALUNO_H

#include "pessoa.h"

class Aluno : public Pessoa {
    private:
        int matricula;
    public:
        Aluno(string nome, int idade, int matricula) : Pessoa(nome, idade), matricula(matricula) {}
        
        void falar() override {
            cout << "Olá, meu nome é " << nome << " e minha matrícula é " << matricula << "." << endl;
        }  
};

#endif
