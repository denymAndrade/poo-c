#pragma once

#include "Personagem.h"

class ArvoreFloresta {
private:
    struct NoArvore {
        Personagem* personagem;
        NoArvore* esquerdo;
        NoArvore* direito;

        explicit NoArvore(Personagem* personagem);
        ~NoArvore();
    };

    NoArvore* raiz;

public:
    ArvoreFloresta();
    ~ArvoreFloresta();

    void inserir(Personagem* personagem);
    void percorrerEmOrdem() const;

private:
    NoArvore* inserirRec(NoArvore* no, Personagem* personagem);
    void percorrerRec(NoArvore* no) const;
    void destruir(NoArvore* no);
};
