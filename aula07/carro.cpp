#include <iostream>
#include <string>


using namespace std;

class Carro {
private:    
    string marca;
    int velocidade;
public:
    string getMarca() const { return marca; }
    void setMarca(const string& m) { marca = m; }

    int getVelocidade() const { return velocidade; }
    void setVelocidade(int v) { 
        if (v >= 0) {
            velocidade = v;
        } else {
            cout << "Velocidade nao pode ser negativa!" << endl;
        }
    }
};

int main() {
    Carro meuCarro;
    meuCarro.setMarca("Ford");
    meuCarro.setVelocidade(80);

    cout << "Marca do carro: " << meuCarro.getMarca() << " | Velocidade: " << meuCarro.getVelocidade() << " km/h" << endl;

    return 0;
}