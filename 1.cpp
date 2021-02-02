

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string frase;
    int numero;
    cout << "LLENAR UN ARCHIVO CON NUMEROS DESDE TECLADO" << endl
    << endl;
    ofstream archivo;
    archivo.open("archivo06.txt");
    cout << "Digite un numero o Ctrl-C para finalizar:" << endl;
    cin>>numero;
    while (numero!=0)
    {
        archivo << numero << endl;
        cout << "Digite un numero o Ctrl-C para finalizar:" << endl;
        cin>>numero;

    }
    archivo.close();
    
    return 0;
}


