#include <iostream>
using namespace std;

struct estructura
{
    int campo1;
    float campo2;
    char campo3;
};

// tipo nombre

int main(void)
{
    estructura miVariable, tuVariable, *p;
    float suma;
    cout << endl;
    cout << "PRIMER EJEMPLO DE USO DE UNA ESTRUCTURA" << endl
         << endl;
    p = &miVariable;
    p->campo1 = 5;
    (*p).campo2 = 37.54;
    miVariable.campo3 = 't';
    tuVariable = miVariable;
    
    
    tuVariable.campo1 = 13;
    suma = miVariable.campo1 + tuVariable.campo1;
    cout<< "La suma es "<< suma <<endl;

    cout << "El campo 1 de miVariable es: " << miVariable.campo1 << endl;
    cout << "El campo 2 de miVariable es: " << p->campo2 << endl;
    cout << "El campo 3 de miVariable es: " << (*p).campo3 << endl;
    cout << endl;
    cout << "El campo 1 de tuVariable es: " << tuVariable.campo1 << endl;
    cout << "El campo 2 de tuVariable es: " << tuVariable.campo2 << endl;
    cout << "El campo 3 de tuVariable es: " << tuVariable.campo3 << endl;
    cout << endl;
    return 0;
}
