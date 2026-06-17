#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> valores; // Cria um vetor dinâmico de inteiros
    valores.push_back(10); // Adiciona o valor 10 ao vetor
    valores.push_back(20); // Adiciona o valor 20 ao vetor
    valores.push_back(30); // Adiciona o valor 30 ao vetor

    cout << "Primeiro: " << valores[0] << endl; // Acessa o primeiro elemento do vetor
    cout << "Tamanho: " << valores.size() << endl; // Exibe o tamanho do vetor
    cout << "Elementos: ";
    for (size_t i = 0; i < valores.size(); i++) {
        cout << valores[i] << " "; // Exibe cada elemento do vetor
    }
    cout << endl;
    valores.pop_back(); // Remove o último elemento do vetor
    cout << "apos remover: ";

    for (int x : valores) {
        cout << x << " "; // Exibe cada elemento do vetor após a remoção
    }
    cout << endl;
    return 0;
}