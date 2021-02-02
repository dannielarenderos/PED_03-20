#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

struct nodo
{
    int carne, nivel, horas;
    string nombre;
    bool asistencia;
    nodo *sig;
};

class ListaSimple
{
private:
    nodo *pInicioPila;
    nodo *pInicioCola;

public:
    ListaSimple();
    ~ListaSimple();
    void InsertarEstudianteLista(int);
    void insInicio(int, string, int, int, bool);
    void mostrarListaSimple();
    void mostrarListaRecursiva(void);
    void mostrarListaRecursivaAux(nodo *p);
    void mostrarListaInversa(void);
    void mostrarListaInversaAux(nodo *p);
    void insertarFinalLista(int);
    void insFinal(int, string, int, int, bool);
    void insFinalRec(int carne);
    nodo *irUltimoNodoRec(nodo *p);
    void insertarAntesDeElemento(int carne, int carneRef);
    void insertarDespuesDeElemento(int carne, string nombre, int carneRef);
    bool buscarEnListaSimple(int carneBuscar);
    bool buscarEnListaSimpleRecursiva(int carneBuscar);
    bool buscarEnListaSimpleRecursivaAux(nodo *p, int carneBuscar);
};

ListaSimple::ListaSimple(void)
{
    pInicioPila = NULL;
    pInicioCola = NULL;
}

ListaSimple::~ListaSimple(void)
{
    nodo *p;

    while (pInicioPila)
    { //Extendida: pInicioPila != NULL
        p = pInicioPila;
        pInicioPila = pInicioPila->sig;
        delete p;
    }
}

void ListaSimple::InsertarEstudianteLista(int num)
{
    int carne, nivel, horas;
    string name;
    bool asistencia;

    for (int i = 0; i < num; i++)
    {

        cout << "Digite el nombre: " << endl;
        cin >> name;
        cout << "Digite el carne: " << endl;
        cin >> carne;
        cout << "Digite el nivel de carrera: " << endl;
        cin >> nivel;
        cout << "Digite las horas sociales: " << endl;
        cin >> horas;
        cout << "Digite la asistencia (0. si no asistió y 1. si asistió): " << endl
             << endl;
        cin >> asistencia;

        if (asistencia == 1)
        {
            insInicio(carne, name, nivel, horas, asistencia);
            insFinal(carne, name, nivel, horas, asistencia);
        }
        else
        {
            insInicio(carne, name, nivel, horas, asistencia);
        }
        
    }
}

void ListaSimple::insInicio(int carne, string nombre, int nivel, int horas, bool asistencia)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->carne = carne; // 9
    nuevo->nombre = nombre;
    nuevo->nivel = nivel;
    nuevo->horas = horas;
    nuevo->asistencia = asistencia;
    nuevo->sig = pInicioPila; // 9  7 null
    pInicioPila = nuevo;      // 9
}

void ListaSimple::mostrarListaSimple()
{
    nodo *p;
    cout << "La lista de estudiantes es: " << endl;
    p = pInicioPila;
    while (p != NULL)
    { //Abreviada: p
        cout << "Nombre: " << p->nombre << endl;
        cout << "Carne: " << p->carne << endl;
        cout << "Nivel de carrera: " << p->nivel << endl;
        cout << "Horas sociales: " << p->horas << endl;
        cout << "Asistencia: " << p->asistencia << endl;
        p = p->sig;
    }
    cout << "Fin de lista de estudiante" << endl;
}

void ListaSimple::mostrarListaRecursiva(void)
{
    ListaSimple::mostrarListaRecursivaAux(pInicioPila);
}

void ListaSimple::mostrarListaRecursivaAux(nodo *p)
{
    if (p != NULL)
    { //Abreviada: p
        cout << "Nombre:" << p->carne;
        cout << "Carne:" << p->nombre << endl;
        cout << "Nivel de carrera:" << p->carne;
        cout << "Horas sociales:" << p->nombre << endl;
        cout << "Asistencia: " << p->asistencia << endl;
        mostrarListaRecursivaAux(p->sig);
    }
}

void ListaSimple::mostrarListaInversa(void)
{
    mostrarListaInversaAux(pInicioPila);
}

void ListaSimple::mostrarListaInversaAux(nodo *p)
{
    if (p->sig) //Etendoda: p->sig != NULL
        mostrarListaInversaAux(p->sig);
    cout << "Nombre:" << p->carne << endl;
    cout << "Carne:" << p->nombre << endl;
    cout << "Nivel de carrera:" << p->nivel;
    cout << "Horas sociales:" << p->horas << endl;
    cout << "Asistencia: " << p->asistencia << endl;
}

void ListaSimple::insertarFinalLista(int num)
{
    int carne, nivel, horas;
    string name;
    bool asistencia;

    for (int i = 0; i < num; i++)
    {
        cout << "Digite el nombre: ";
        cin >> name;
        cout << "Digite el carne: ";
        cin >> carne;
        cout << "Digite el nivel de carrera: ";
        cin >> nivel;
        cout << "Digite las horas sociales: ";
        cin >> horas;
        cout << "Digite la asistencia: ";
        cin >> asistencia;

        insFinal(carne, name, nivel, horas, asistencia);
    }
}

void ListaSimple::insFinal(int carne, string nombre, int nivel, int horas, bool asistencia)
{
    nodo *nuevo = new nodo;
    nuevo->carne = carne;
    nuevo->nombre = nombre;
    nuevo->nivel = nivel;
    nuevo->horas = horas;
    nuevo->asistencia = asistencia;
    nuevo->sig = NULL;

    //Notar que hay dos casos de inserción: si la lista esta
    //vacia o si ya tiene elementos.
    if (!pInicioCola) //Extendido: pInicioCola == NULL
        pInicioCola = nuevo;
    else    /// Danni Beto Andres Oscar null
        {
        nodo *s = pInicioCola;
        while (s->sig) //Extendido: s->sig != NULL
            s = s->sig;
        s->sig = nuevo;
    }
}

void ListaSimple::insFinalRec(int carne)
{
    nodo *nuevo = new nodo;
    nuevo->carne = carne;
    nuevo->sig = NULL;

    // Avanzar hacia el último nodo de la lista.
    nodo *aux = irUltimoNodoRec(pInicioPila);

    //Notar que hay dos casos de inserción: si la lista esta
    //vacia o si ya tiene elementos.
    if (!aux)
        pInicioPila = nuevo;
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

void ListaSimple::insertarAntesDeElemento(int carne, int carneRef)
{
    nodo *nuevo = new nodo;
    nuevo->carne = carne;

    if (!pInicioPila)
    { // Si la lista esta vacia.
        pInicioPila = nuevo;
        pInicioPila->sig = NULL;
    }
    else if (pInicioPila->carne == carneRef)
    {                             // Si el elemento de referencia
        nuevo->sig = pInicioPila; // es el primero de la lista.
        pInicioPila = nuevo;
    }
    else
    {                          // Casos en que el elemento de referencia se encuentra
        nodo *s = pInicioPila; // a la mitad de la lista o no esta en la lista.
        while (s->sig && (s->sig->carne != carneRef))
            s = s->sig;
        nuevo->sig = s->sig;
        s->sig = nuevo;
    }
}

/*

Inserción de un elemento después de un elemento determinado

El algoritmo es el siguiente:

1.	Asignar un nuevo nodo al puntero nuevo, que es una variable local de la función de inserción.
2.	Introducir nuevos carnes en la zona de carnes del nuevo nodo.
3.	Recorrer la lista hasta llegar al elemento que va antes del elemento a insertar o hasta encontrar el elemento de la cola de la lista.
4.	Hacer que el puntero siguiente del nuevo nodo apunte a s->siguiente->siguiente.
5.	Hacer que s->siguiente->siguiente apunte al nuevo nodo.

*/

// Si el elemento de referencia no existe en la lista, el nuevo elemento
// se insertara en la cola:
void ListaSimple::insertarDespuesDeElemento(int carne, string nombre, int carneRef)
{
    nodo *nuevo = new nodo;
    nuevo->carne = carne;
    nuevo->nombre = nombre;

    if (!pInicioPila)
    { // Si la lista está vacía.
        pInicioPila = nuevo;
        pInicioPila->sig = NULL;
    }
    else
    {
        nodo *s = pInicioPila, *q = NULL;
        while (s && s->carne != carneRef)
        { // Hacer avanzar los punteros sobre la lista.
            q = s;
            s = s->sig;
        }
        if (!q)
        { // Si s se quedó apuntando al primer elemento.
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
            nuevo->sig = s->sig;
            s->sig = nuevo;
        }
    }
}

/*
Búsqueda de un elemento en una lista simplemente enlazada

El algoritmo es el siguiente:

1.	Solicitar carne a buscar;
2.	Apuntar hacia el nodo al frente de la lista.
3.	Recorrer la lista hasta llegar al elemento buscado o hasta encontrar el final.
4.	Al finalizar el recorrido: si el puntero de búsqueda no apunta a NULL, el elemento se encuentra en la lista, si no, el elemento no se encuentra en la lista.

Una versión iterativa de la función miembro para buscar un elemento en la lista es:
*/

bool ListaSimple::buscarEnListaSimple(int carneBuscar)
{
    nodo *s;

    s = pInicioPila;
    while (s && (s->carne != carneBuscar))
        s = s->sig;
    if (s)
        return true;
    else
        return false;
}

//Una función miembro recursiva para buscar un elemento en la lista es:

bool ListaSimple::buscarEnListaSimpleRecursiva(int carneBuscar)
{
    return buscarEnListaSimpleRecursivaAux(pInicioPila, carneBuscar);
}

bool ListaSimple::buscarEnListaSimpleRecursivaAux(nodo *p, int carneBuscar)
{
    if (p && (p->carne != carneBuscar))
        buscarEnListaSimpleRecursivaAux(p->sig, carneBuscar);
    else if (p)
        return true;
    else
        return false;
}

int main(void)
{
    ListaSimple objListaSimple;
    int numbuscar, numinsertardespues, refinsert;
    string nombredespues;
    int opc, valor, n, i, ele, prm;
    do
    {
        cout << "1.Insertar estudiantes:" << endl;
        cout << "2.Mostrar estudiantes" << endl;
        cout << "5. lista:" << endl;
        cout << "6.Salir" << endl;
        cout << "Ingrese una opcion:" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Numero de estudiantes a ingresar ";
            cin >> n;
            objListaSimple.InsertarEstudianteLista(n);
            break;
        case 2:
            cout << "Mostrar estudiantes" << endl;
            objListaSimple.mostrarListaSimple();
            break;
        case 3:
            cout << endl
                 << "Promedio" << endl;
            cout << "El promedio de la lista es:" << endl;
            break;
        case 4:
            cout << endl
                 << "Numero a buscar: " << endl;
            cin >> ele;

            break;
        case 5:

            break;
        }
    } while (opc != 6);

    return 0;
}
