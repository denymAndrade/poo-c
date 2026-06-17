#include <iostream>
#include <string>
#include <locale.h>

using namespace std;


    unsigned long long int fatorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * fatorial(n - 1);
    }

int main() {
     setlocale(LC_ALL, "pt_BR.UTF-8");
     
    int numero;

    cout << "Digite um número para calcular o fatorial: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Fatorial não é definido para números negativos." << endl;
    } else {
        cout << "O fatorial de " << numero << " é " << fatorial(numero) << "." << endl;
    }

    return 0;

}

    