#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string nombre;
    int cantidad;
    float precio, totpagar;
    int i, k;
    cout << endl;
    cout << "LEER PALABRA POR PALABRA DESDE UN ARCHIVO" << endl
         << endl;
    ifstream archivo;
    ofstream archivollenar;
    archivo.open("archivo06.txt");
    archivollenar.open("archivo03.txt");

    while (!archivo.eof())
    {
        archivo >> nombre;
        archivo >> cantidad;
        archivo >> precio;
        cout << "Se compraron " << cantidad << " unidades de ";
        totpagar = cantidad*precio;
        cout << nombre << " a $" << precio << " pagando $" << totpagar <<  endl;

        archivollenar << nombre << " " << totpagar << endl;
    }
    archivo.close();
    archivollenar.close();

    cout << endl;
    return 0;
}


