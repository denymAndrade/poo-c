#include <iostream>
#include <string>
#include <clocale>
#include "pessoa.h"
#include "aluno.h"
#include "professor.h"

using namespace std;



int main() {
    // Configurar locale para UTF-8
    setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "=== CADASTRO DE PESSOAS ===" << endl << endl;
    Pessoa* p1 = new Pessoa("Maria Silva", 18);
    Pessoa* p2 = new Aluno("João Santos", 20, 12345);
    Pessoa* p3 = new Professor("Dr. Carlos Oliveira", 40, "Programação em C++");
    
    fazerFalar(p1);
    fazerFalar(p2);
    fazerFalar(p3);
    
    delete p1;
    delete p2;
    delete p3;
  
    
    
    // Cadastrar uma Pessoa
   //cout << "1. Pessoa:" << endl;
    //Pessoa pessoa("Maria Silva", 15);
    //pessoa.falar();
    //cout << endl;
    
    // Cadastrar um Aluno
    //cout << "2. Aluno:" << endl;
    //Aluno aluno("João Santos", 20, 12345);
    //aluno.falar();
    //cout << endl;
    
    // Cadastrar um Professor
    //cout << "3. Professor:" << endl;
    //Professor professor("Dr. Carlos Oliveira", 40, "Programação em C++");
    //professor.falar();
    //cout << endl;
    
    return 0;
}
