#include <iostream>
#include <conio.h>

using namespace std;

struct nodo        
{
    int dato;              // 8 6 9      9 -> 6 -> 8 -> null
    struct nodo *sgte;
};

int main()
{
    struct nodo NodoCabecera;
    struct nodo *q;
    int i, n;
    NodoCabecera.sgte = NULL;   //         null

    cout << "Numero de elementos:";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Elemento:" << (i + 1) << endl;  
        q = new (struct nodo);
        cin >> q->dato;  // 5                        //  5 -> null
        q->sgte = NodoCabecera.sgte;
        NodoCabecera.sgte = q;                     
    } 

    cout << endl << "Listado:" << endl;
    q = NodoCabecera.sgte;    // 9 -> 6 -> 8 -> null
    while (q != NULL)
    {
        cout << q->dato << endl; // 9 6 8
        q = q->sgte;    // 6 8 null
    }
    return 0;
}