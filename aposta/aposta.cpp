#include <iostream>
#include <string>

using namespace std;

int main() {
    // Resultados reais já definidos com base na imagem do laboratório
    int realA1 = 3, realB1 = 0; // Jogo 1: BRA x EGT
    int realA2 = 1, realB2 = 1; // Jogo 2: RSA x MAR
    int realA3 = 1, realB3 = 2; // Jogo 3: FRA x ARG
    int realA4 = 4, realB4 = 2; // Jogo 4: GER x COS

    // Variáveis individuais para os 3 participantes do trio
    string nome1, nome2, nome3;
    int pontos1 = 0, pontos2 = 0, pontos3 = 0;

    // Variáveis temporárias para o laço de repetição
    string nomeAtual;
    int pontosAtuais;
    int apostaA, apostaB, realA, realB;

    cout << "========================================\n";
    cout << "           BOLAO DA COPA 2026           \n";
    cout << "========================================\n\n";

    // Registrar e calcular apostas do Trio (Laco para os 3 participantes)
    for (int p = 1; p <= 3; p++) {
        cout << "----------------------------------------\n";
        cout << "Digite o nome do integrante " << p << ": ";
        cin >> nomeAtual;
        pontosAtuais = 0; // Zera a pontuação para começar a somar os jogos deste participante

        cout << "Apostas de " << nomeAtual << ":\n";
        
        // Laco para capturar as apostas dos 4 jogos específicos da imagem
        for (int i = 1; i <= 4; i++) {
            
            // Usamos if/else para identificar qual jogo exibir e qual resultado real usar
            if (i == 1) { 
                cout << "\n  [ BRA x EGT ]\n";
                cout << "  Gols BRA: "; cin >> apostaA;
                cout << "  Gols EGT: "; cin >> apostaB;
                realA = realA1; realB = realB1; 
            } 
            else if (i == 2) { 
                cout << "\n  [ RSA x MAR ]\n";
                cout << "  Gols RSA: "; cin >> apostaA;
                cout << "  Gols MAR: "; cin >> apostaB;
                realA = realA2; realB = realB2; 
            } 
            else if (i == 3) { 
                cout << "\n  [ FRA x ARG ]\n";
                cout << "  Gols FRA: "; cin >> apostaA;
                cout << "  Gols ARG: "; cin >> apostaB;
                realA = realA3; realB = realB3; 
            } 
            else if (i == 4) { 
                cout << "\n  [ GER x COS ]\n";
                cout << "  Gols GER: "; cin >> apostaA;
                cout << "  Gols COS: "; cin >> apostaB;
                realA = realA4; realB = realB4; 
            }

            // Cálculo da Pontuação usando as regras da imagem
            if (apostaA == realA && apostaB == realB) {
                pontosAtuais += 10; // Placar exato
                cout << "  -> Acertou em cheio! (+10 pontos)\n";
            } 
            else if ((apostaA > apostaB && realA > realB) || 
                     (apostaA < apostaB && realA < realB) || 
                     (apostaA == apostaB && realA == realB)) {
                pontosAtuais += 5; // Acertou vencedor ou empate
                cout << "  -> Acertou o resultado! (+5 pontos)\n";
            } else {
                cout << "  -> Errou o jogo! (0 pontos)\n";
            }
        }

        // Salva os dados do participante atual nas variáveis do ranking
        if (p == 1) { nome1 = nomeAtual; pontos1 = pontosAtuais; }
        else if (p == 2) { nome2 = nomeAtual; pontos2 = pontosAtuais; }
        else if (p == 3) { nome3 = nomeAtual; pontos3 = pontosAtuais; }
        cout << "\nTotal de pontos de " << nomeAtual << ": " << pontosAtuais << "\n\n";
    }

    // Lógica de Ranking "Na mão" (Sem vetores)
    string primNome, segNome, terNome;
    int primPts, segPts, terPts;

    // Verifica se o Integrante 1 é o vencedor
    if (pontos1 >= pontos2 && pontos1 >= pontos3) {
        primNome = nome1; primPts = pontos1;
        if (pontos2 >= pontos3) {
            segNome = nome2; segPts = pontos2;
            terNome = nome3; terPts = pontos3;
        } else {
            segNome = nome3; segPts = pontos3;
            terNome = nome2; terPts = pontos2;
        }
    } 
    // Verifica se o Integrante 2 é o vencedor
    else if (pontos2 >= pontos1 && pontos2 >= pontos3) {
        primNome = nome2; primPts = pontos2;
        if (pontos1 >= pontos3) {
            segNome = nome1; segPts = pontos1;
            terNome = nome3; terPts = pontos3;
        } else {
            segNome = nome3; segPts = pontos3;
            terNome = nome1; terPts = pontos1;
        }
    } 
    // Se não for nem o 1 nem o 2, o Integrante 3 é o vencedor
    else {
        primNome = nome3; primPts = pontos3;
        if (pontos1 >= pontos2) {
            segNome = nome1; segPts = pontos1;
            terNome = nome2; terPts = pontos2;
        } else {
            segNome = nome2; segPts = pontos2;
            terNome = nome1; terPts = pontos1;
        }
    }

    // Exibir o Ranking Final
    cout << "========================================\n";
    cout << "             RANKING FINAL              \n";
    cout << "========================================\n";
    cout << "1o Lugar: " << primNome << " com " << primPts << " pontos.\n";
    cout << "2o Lugar: " << segNome << " com " << segPts << " pontos.\n";
    cout << "3o Lugar: " << terNome << " com " << terPts << " pontos.\n";

    // NOVO: Exibir os Resultados Oficiais no final
    cout << "\n========================================\n";
    cout << "          RESULTADOS OFICIAIS           \n";
    cout << "========================================\n";
    cout << "  BRA  " << realA1 << "  X  " << realB1 << "  EGT  \n";
    cout << "  RSA  " << realA2 << "  X  " << realB2 << "  MAR  \n";
    cout << "  FRA  " << realA3 << "  X  " << realB3 << "  ARG  \n";
    cout << "  GER  " << realA4 << "  X  " << realB4 << "  COS  \n";
    cout << "========================================\n\n";

    return 0;
}