#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    struct nodo *sig;
};

int main(void)
{
    cout << endl;
    cout << "MIS PIRMERAS DOS ESTRUCTURAS DINÁMICAS" << endl
         << endl;
    nodo *p, *q;
    p = new nodo;
    q = new nodo;
    p->dato = 5;  // 5
    q->dato = 8;  // 8
    p->sig = q; // 5 8
    q->sig = p; // 8 5
    cout << "El dato del nodo p es: " << p->dato<< endl;
    cout << "El dato del nodo q es: " << q->dato << endl;
    cout << "El dato del nodo siguiente apuntado por q es: " << q->sig->dato << endl;
    cout << "El dato del nodo siguiente apuntado por p es: " << p->sig->dato << endl;   // q p s=0    || q->sig->sig->dato
    cout << "La direccion a la que apunta p es: " << p << endl;
    cout << "La direccion a la que apunta q es: " << q << endl;

    delete p;
    delete q;
    p = NULL;
    q = NULL;
    
    return 0;
}