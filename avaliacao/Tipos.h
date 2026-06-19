#pragma once

#include <string>
#include <vector>

enum class TipoPersonagem {
    ANIMAL = 1,
    MAGO = 2,
    DRAGAO = 3,
    FADA = 4,
    HUMANO = 5
};

class TiposValidos {
public:
    static std::string getTipoNome(TipoPersonagem tipo) {
        switch (tipo) {
            case TipoPersonagem::ANIMAL: return "Animal";
            case TipoPersonagem::MAGO: return "Mago";
            case TipoPersonagem::DRAGAO: return "Dragão";
            case TipoPersonagem::FADA: return "Fada";
            case TipoPersonagem::HUMANO: return "Humano";
            default: return "Desconhecido";
        }
    }

    static std::vector<std::string> getAnimaisValidos() {
        return {"Lupo", "Urso", "Águia", "Serpente", "Lobo", "Raposa", "Gato", "Cachorro", "Javali", "Cervo"};
    }

    static std::vector<std::string> getMagosValidos() {
        return {"Merlin", "Arquimago", "Bruxo", "Feiticeiro", "Mago Negro", "Mago Branco"};
    }

    static std::vector<std::string> getDragoesValidos() {
        return {"Dragão Vermelho", "Dragão Azul", "Dragão Verde", "Dragão Negro", "Dragão Dourado"};
    }

    static std::vector<std::string> getFadasValidas() {
        return {"Fada da Luz", "Fada Sombria", "Fada da Floresta", "Fada Aquática", "Fada do Ar"};
    }

    static std::vector<std::string> getHumanosValidos() {
        return {"Cavaleiro", "Arqueiro", "Guerreiro", "Paladino", "Bardo", "Ranger"};
    }

    static bool validarNivelPoder(int nivel) {
        return nivel >= 1 && nivel <= 100;
    }

    static std::string descricaoNivelPoder(int nivel) {
        if (nivel >= 1 && nivel <= 30) return "Fraco";
        if (nivel >= 31 && nivel <= 60) return "Médio";
        return "Forte";
    }
};
