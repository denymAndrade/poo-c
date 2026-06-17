#include <iostream>

using namespace std;

int main() {
    const int numero = 5;

    std::cout << "\nTabuada do " << numero << ":\n";
    std::cout << "-------------------\n";

    for (int i = 1; i <= 10; ++i) {
        std::cout << " " << numero << " x " << i << " = " << (numero * i) << "\n";
    }

    std::cout << "-------------------\n";

    return 0;
}