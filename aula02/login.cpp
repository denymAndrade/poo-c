#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    string username, password;
    int contador = 0;

    while (contador < 3) {
        cout << "Digite o nome de usuário: ";
        cin >> username;

        cout << "Digite a senha: ";
        cin >> password;

        if (username == "admin" && password == "1234") {
            cout << "Login bem-sucedido!" << endl;
            return 0;
        } else {
            contador++;
            cout << "Nome de usuário ou senha incorretos." << endl;
            cout << "Tentativa " << contador << " de 3." << endl;
        }
    }

    cout << "Número máximo de tentativas atingido." << endl;
    return 0;
}