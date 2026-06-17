#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int n, t1 = 0, t2 = 1, nextTerm;

    cout << "Digite o número de termos: ";
    cin >> n;

    cout << "Sequência de Fibonacci: ";

    for (int i = 1; i <= n; ++i) {
        if(i == 1) {
            cout << t1 << " ";
            continue;
        }
        if(i == 2) {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << " ";
    }

    return 0;
}