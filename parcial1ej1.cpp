#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string cadena;
    cout<<"Ingrese una cadena de texto"<<endl;
    getline(cin, cadena);
    int cont = cadena.length()-1;
    while(cont!=-1){
        cout<<cadena[cont];
        cont--;
    }
    return 0;
}
