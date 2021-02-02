#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int numero, cant, sum = 0, prom = 0;
    ofstream archivo;
    archivo.open("archivo.txt");
    cout << "Cantidad de numeros a ingresar?" << endl;
    cin >> cant;
    for (int i = 0; i < cant; i++)
    {
        cout << "Digite el numero " << i+1 << endl;
        cin >> numero;
        sum += numero;
    }

    archivo << sum << endl;
    archivo << (sum / cant) << endl;
    archivo.close();
    return 0;
}
