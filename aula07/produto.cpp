#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
class Produto {
private:
    string nome;
    double preco;
public:
    string getNome() const { return nome; }
    double getPreco() const { return preco; }

    Produto(string nome, double preco) : nome(nome), preco(preco) {
        if (preco < 0) {
            cout << "Preco invalido! Definindo preco para 0." << endl;
            this->preco = 0;
        }
        this->nome = nome;
    }
    void setPreco(double novoPreco) {
        if (novoPreco > 0) {
            preco = novoPreco;
            cout << fixed << setprecision(2);
            cout << "Preco atualizado para R$ " << preco << endl;
        } else {
            cout << "Preco invalido! O preco nao pode ser negativo." << endl;
        }
    }
    void exibirProduto() const {
        cout << fixed << setprecision(2);
        cout << "Produto: " << nome << ", Preco: R$ " << preco << endl;
     }
};

int main() {
    Produto produto("notebook", 3500);
    produto.exibirProduto();    
    Produto produto2("smartphone", 1500);
    produto2.exibirProduto();
    }