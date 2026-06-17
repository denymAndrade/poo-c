#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    string username, password;
    int contador = 0;
try {
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
            if (contador >= 3) throw runtime_error("Erro a1");
            cout << "Tentativa " << contador << " de 3." << endl;
        }
    }
} catch (const std::exception& e) {
    cerr << "Ocorreu um erro: usuario Bloqueado " << e.what() << endl;
    return 1;
}
    return 0;
}