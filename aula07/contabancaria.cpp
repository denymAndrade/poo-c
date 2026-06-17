#include <iostream>
#include <string>


using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;

public:
    // Construtor
    ContaBancaria(string t, double s) : titular(t), saldo(s) {}

    // Getters (leitura controlada)
    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    // Setters (escrita controlada com validacao)
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Deposito de R$ " << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Valor invalido para deposito!" << endl;
        }
    }

    bool sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado com sucesso." << endl;
            return true;
        } else {
            cout << "Saldo insuficiente ou valor invalido!" << endl;
            return false;
        }
    }
};

int main() {
    ContaBancaria minhaConta("João", 1000.0);

    cout << "Titular: " << minhaConta.getTitular() << endl;
    cout << "Saldo: R$ " << minhaConta.getSaldo() << endl;
    minhaConta.depositar(500.0);
    minhaConta.sacar(200.0);  
    minhaConta.sacar(2000.0); 
    cout << "Saldo Atual: R$ " << minhaConta.getSaldo() << endl; 

    return 0;
}