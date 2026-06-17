#include <iostream>
#include <locale.h>


using namespace std;
int main(){

    setlocale(LC_ALL, "UTF-8");

    short int * pi = new short int;
    *pi = 1001;
    cout << "Valor Inteiro = " << *pi << endl;
    cout << "Localização = " << pi << endl << endl;

    float * pf = new float;
    *pf = 123.35;
    cout << "(Float)Valor ponto-flutuante = " << *pf << endl;
    cout << "(Float)Localização = " << pf << endl << endl;
    
    double *pd = new double;
    *pd = 500.35;
    cout << "(Double)Valor ponto-flutuante = " << *pd << endl;
    cout << "(Double)Localização = " << pd << endl << endl;

    cout << "(int4bytes)Tamanho de pi = " << sizeof(pi) << endl;
    cout << "(int4bytes)Tamanho de *pi = " << sizeof(*pi) << endl;
    cout << "(int4bytes)Tamanho de pd = " << sizeof(pd) << endl;
    cout << "(int4bytes)Tamanho de *pd = " << sizeof(*pd) << endl;
    cout << "(int4bytes)Tamanho de pf = " << sizeof(pf) << endl;
    cout << "(int4bytes)Tamanho de *pf = " << sizeof(*pf) << endl;

    return 0;

}