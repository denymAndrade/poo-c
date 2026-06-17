#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
   
vector<string> jogos = {"BRA x EGT", "RSA x MAR", "FRA x ARG", "GER x COS"};
    vector<int> golsReaisA = {3, 1, 1, 4}; // Gols reais dos times A
    vector<int> golsReaisB = {0, 1, 2, 2}; // Gols reais dos times B

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
        
        // Laco para capturar as apostas dos jogos
        for (size_t i = 0; i < jogos.size(); i++) {
            // Extrai os nomes das seleções a partir da string (ex: "BRA" e "EGT")
            string timeA = jogos[i].substr(0, 3);
            string timeB = jogos[i].substr(6, 3);
            
            cout << "\n  [ " << jogos[i] << " ]\n";
            cout << "  Gols " << timeA << ": "; cin >> apostaA;
            cout << "  Gols " << timeB << ": "; cin >> apostaB;
            
            realA = golsReaisA[i]; 
            realB = golsReaisB[i]; 

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
    for (size_t i = 0; i < jogos.size(); i++) {
        string timeA = jogos[i].substr(0, 3);
        string timeB = jogos[i].substr(6, 3);
        cout << "  " << timeA << "  " << golsReaisA[i] << "  X  " << golsReaisB[i] << "  " << timeB << "  \n";
    }
    cout << "========================================\n\n";

    return 0;
}