#include <iostream>
#include <string>

using namespace std;

int sumIterativa(int numero)  //538
{
    int suma = 0;
    while (numero != 0) //0
    {
        suma = suma + numero % 10; //8+3+5
        numero = numero / 10; //0
    }
    return suma;
}

int sumRecursiva(int numero, int suma)
{
    suma = suma + numero % 10;
    numero = numero / 10;
    if (numero == 0)
        return suma;
    else
        sumRecursiva(numero, suma);
}

int main(int argc, char const *argv[])
{
    int numero;
    cout << "Ingrese un numero" << endl;
    cin >> numero;
    cout << "Suma iterativa" << endl;
    cout << sumIterativa(numero)<<endl;
    cout << "Suma recursiva" << endl;
    cout << sumRecursiva(numero,0);

    return 0;
}
