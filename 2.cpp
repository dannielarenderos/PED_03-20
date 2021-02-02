

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream archivo("archivo03.txt");
    archivo << "Me llamo Anita,\n";
    archivo << "¿y vos?\n";
    archivo << "Yo me llamo Pepito\n";
    archivo << "Y soy bien portado\n";
    archivo.close();
    return 0;
}

