#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

class ListaSimple
{
private:
    nodo *pInicio;

public:
    ListaSimple();
    ~ListaSimple();
    void insertarInicioLista(void);
    void insInicio(int);
    void mostrarListaSimple();
    void mostrarListaRecursiva(void);
    void mostrarListaRecursivaAux(nodo *p);
    void mostrarListaInversa(void);
    void mostrarListaInversaAux(nodo *p);
    void insertarFinalLista(void);
    void insFinal(int dato);
    void insFinalRec(int dato);
    nodo *irUltimoNodoRec(nodo *p);
    void insertarAntesDeElemento(int dato, int datoRef);
    void insertarDespuesDeElemento(int dato, int datoRef);
    bool buscarEnListaSimple(int datoBuscar);
    bool buscarEnListaSimpleRecursiva(int datoBuscar);
    bool buscarEnListaSimpleRecursivaAux(nodo *p, int datoBuscar);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

ListaSimple::~ListaSimple(void)
{
    nodo *p;

    while (pInicio)
    { //Extendida: pInicio != NULL
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaSimple::insertarInicioLista(void)
{
    int dato;

    cout << "Digite un entero o -1 para terminar: ";
    while (dato!=-1)
    {
        cin >> dato;
        insInicio(dato);
        cout << "Digite un entero o -1 para terminar: ";
    }
}

void ListaSimple::insInicio(int dato)
{
    nodo *nuevo;

    nuevo = new nodo;            
    nuevo->dato = dato; // 9
    nuevo->sig = pInicio; // 13 8 9  7 null
    pInicio = nuevo;  // 9
}

void ListaSimple::mostrarListaSimple()
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while (p != NULL)
    { //Abreviada: p
        cout << p->dato << endl;
        p = p->sig;
    }
    cout << "Fin de mostrar lista" << endl;
}

void ListaSimple::mostrarListaRecursiva(void)
{
    ListaSimple::mostrarListaRecursivaAux(pInicio);
}

void ListaSimple::mostrarListaRecursivaAux(nodo *p) // null
{
    if (p != NULL)
    { //Abreviada: p
        cout << p->dato << endl;  //13 8 9 7
        mostrarListaRecursivaAux(p->sig); 
    }
}

void ListaSimple::mostrarListaInversa(void)
{
    mostrarListaInversaAux(pInicio);
}

void ListaSimple::mostrarListaInversaAux(nodo *p)
{
    if (p->sig) //Etendoda: p->sig != NULL
        mostrarListaInversaAux(p->sig);   // 13 8 9 7 null
    cout << p->dato << endl;
}

void ListaSimple::insertarFinalLista(void)
{
    int dato;

    cout << "Digite un entero o Ctrl-D para terminar: ";
    while (cin >> dato)
    {
        insFinal(dato);
        //insFinalRec(dato);
        cout << "Digite un entero o Ctrl-D para terminar: ";
    }
}

void ListaSimple::insFinal(int dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;      
    nuevo->sig = NULL;

    //Notar que hay dos casos de inserción: si la lista esta
    //vacia o si ya tiene elementos.
    if (!pInicio) //Extendido: pInicio == NULL
        pInicio = nuevo;  // 6 
    else
    {            //    13 8 9 7 6 null
        nodo *s = pInicio;   
        while (s->sig) //Extendido: s->sig != NULL   
            s = s->sig;
        s->sig = nuevo;
    }
}

void ListaSimple::insFinalRec(int dato)  //15
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    // Avanzar hacia el último nodo de la lista.
    nodo *aux = irUltimoNodoRec(pInicio);  //    13 8 9 7 6 15 null 
    //Notar que hay dos casos de inserción: si la lista esta
    //vacia o si ya tiene elementos.
    if (!aux)
        pInicio = nuevo;
    else
        aux->sig = nuevo;
}

nodo *ListaSimple::irUltimoNodoRec(nodo *p)
{
    if (!p)
        return NULL;
    else if (p->sig)
        return irUltimoNodoRec(p->sig);
    else
        return p;
}

//Inserción de un elemento antes de un elemento determinado
// El algoritmo realiza las siguientes consideraciones:
// Si la lista esta vacia, el elemento sera el primero.
// Si el elemento de referencia es el primero de la lista,
// el nuevo elemento se insertara al inicio de la lista.
// Si el elemento de referencia existe en la lista, el nuevo
// elemento se insertara antes que él; y si el elemento de
// referencia no existe en la lista, el nuevo elemento
// se insertara en la cola.

void ListaSimple::insertarAntesDeElemento(int dato, int datoRef) // 4 3
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;  // 4 

    if (!pInicio)                      //  4 null
    { // Si la lista esta vacia.
        pInicio = nuevo;
        pInicio->sig = NULL;
    }

    else if (pInicio->dato == datoRef)                               //      
    {                         // Si el elemento de referencia     //  4  3  5   6  14 60 null
        nuevo->sig = pInicio; // es el primero de la lista.
        pInicio = nuevo;
    }
    else
    {                      // Casos en que el elemento de referencia se encuentra
        nodo *s = pInicio; // a la mitad de la lista o no esta en la lista.
        while (s->sig && (s->sig->dato != datoRef))     //            s
                                                               //4-> sig  || s->sig   3
                                                       //                     s
            s = s->sig;                               //   77    5    6   8  11  3   14 60 null

                            // 4 -> 3                //   77    5    6 8  11 -> 4 -> 3    14 60 null
        nuevo->sig = s->sig;  // 3
        s->sig = nuevo;
    }
}

/*

Inserción de un elemento después de un elemento determinado

El algoritmo es el siguiente:

1.	Asignar un nuevo nodo al puntero nuevo, que es una variable local de la función de inserción.
2.	Introducir nuevos datos en la zona de datos del nuevo nodo.
3.	Recorrer la lista hasta llegar al elemento que va antes del elemento a insertar o hasta encontrar el elemento de la cola de la lista.
4.	Hacer que el puntero siguiente del nuevo nodo apunte a s->siguiente->siguiente.
5.	Hacer que s->siguiente->siguiente apunte al nuevo nodo.

*/

// Si el elemento de referencia no existe en la lista, el nuevo elemento
// se insertara en la cola:
void ListaSimple::insertarDespuesDeElemento(int dato, int datoRef)  // 15 30
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;    

    if (!pInicio)
    { // Si la lista está vacía.
        pInicio = nuevo;
        pInicio->sig = NULL;
    }
    else
    {                                               //                 q           s
        nodo *s = pInicio, *q = NULL;             //   77   5   6   3  60 -> 15 ->  null
        while (s && s->dato != datoRef)    
        { // Hacer avanzar los punteros sobre la lista.
            q = s;
            s = s->sig;
        }
        if (!q)                                              // 
        { // Si s se quedó apuntando al primer elemento.    // 77  5   6   8  11  3   14 60 null
            nuevo->sig = s->sig; 
            s->sig = nuevo;
        }
        else if (!s)
        { // Si s se salió de la lista.
            q->sig = nuevo;
            nuevo->sig = NULL;
        }
        else
        { // Si q y s apuntan a nodos contiguos (en medio de la lista).
            nuevo->sig = s->sig;          //         q   s
            s->sig = nuevo;              //  77  5   6  30 -> 15 -> 11  3   14 60 null
        }
    }
}

/*
Búsqueda de un elemento en una lista simplemente enlazada

El algoritmo es el siguiente:

1.	Solicitar dato a buscar;
2.	Apuntar hacia el nodo al frente de la lista.
3.	Recorrer la lista hasta llegar al elemento buscado o hasta encontrar el final.
4.	Al finalizar el recorrido: si el puntero de búsqueda no apunta a NULL, el elemento se encuentra en la lista, si no, el elemento no se encuentra en la lista.

Una versión iterativa de la función miembro para buscar un elemento en la lista es:
*/

bool ListaSimple::buscarEnListaSimple(int datoBuscar)
{
    nodo *s;

    s = pInicio;
    while (s && (s->dato != datoBuscar))
        s = s->sig;
    if (s)
        return true;
    else
        return false;
}

//Una función miembro recursiva para buscar un elemento en la lista es:

bool ListaSimple::buscarEnListaSimpleRecursiva(int datoBuscar)
{
    return buscarEnListaSimpleRecursivaAux(pInicio, datoBuscar);
}

bool ListaSimple::buscarEnListaSimpleRecursivaAux(nodo *p, int datoBuscar)
{
    if (p && (p->dato != datoBuscar))
        buscarEnListaSimpleRecursivaAux(p->sig, datoBuscar);
    else if (p)
        return true;
    else
        return false;
}

int main(void)
{
    ListaSimple objListaSimple;
    int numbuscar, numinsertardespues, refinsert;

    cout << endl;
    cout << "PROGRAMA EJEMPLO DE LISTAS SIMPLES" << endl
         << endl;

    cout << "Inserción de datos en la lista:" << endl;
    objListaSimple.insertarInicioLista();

    objListaSimple.mostrarListaSimple();
    cout << endl;

    cout << "Numero a buscar" << endl;
    cin >> numbuscar;
   cout<< objListaSimple.buscarEnListaSimple(numbuscar)<<endl;
    cout << "Numero a insertar después de un elemento" << endl;
    cin >> numinsertardespues;

    cout << "insertar después de que elemento" << endl;
    cin >> refinsert;
    
    objListaSimple.insertarDespuesDeElemento(numinsertardespues, refinsert);

    objListaSimple.mostrarListaSimple();
    cout << endl;
    return 0;
}
