#include <iostream>
#include <string>


using namespace std;

class Carro {
private:    
    string marca;
    int velocidade;
public:
    string getMarca() const { return marca; }