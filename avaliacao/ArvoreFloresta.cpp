#include "ArvoreFloresta.h"
#include <iostream>

ArvoreFloresta::NoArvore::NoArvore(Personagem* personagem)
    : personagem(personagem), esquerdo(nullptr), direito(nullptr) {}

ArvoreFloresta::NoArvore::~NoArvore() {
    delete personagem;
}

ArvoreFloresta::ArvoreFloresta() : raiz(nullptr) {}

ArvoreFloresta::~ArvoreFloresta() {
    destruir(raiz);
}

void ArvoreFloresta::inserir(Personagem* personagem) {
    raiz = inserirRec(raiz, personagem);
}

void ArvoreFloresta::percorrerEmOrdem() const {
    std::cout << "\nPercurso em ordem (menos poderoso -> mais poderoso):\n";
    percorrerRec(raiz);
    std::cout << std::endl;
}

ArvoreFloresta::NoArvore* ArvoreFloresta::inserirRec(NoArvore* no, Personagem* personagem) {
    if (no == nullptr) {
        return new NoArvore(personagem);
    }

    if (personagem->getNivelPoder() < no->personagem->getNivelPoder()) {
        no->esquerdo = inserirRec(no->esquerdo, personagem);
    } else {
        no->direito = inserirRec(no->direito, personagem);
    }
    return no;
}

void ArvoreFloresta::percorrerRec(NoArvore* no) const {
    if (no == nullptr) {
        return;
    }

    percorrerRec(no->esquerdo);
    no->personagem->imprimir();
    std::cout << std::endl;
    percorrerRec(no->direito);
}

void ArvoreFloresta::destruir(NoArvore* no) {
    if (no == nullptr) {
        return;
    }

    destruir(no->esquerdo);
    destruir(no->direito);
    delete no;
}
