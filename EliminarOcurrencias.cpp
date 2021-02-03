#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nodo
{
    int nro;
    struct nodo *sgte;
};

typedef struct nodo *Tlista;

void imprimir(Tlista lista)
{
    int c = 1;
    while (lista != NULL)
    {                                                   // 4 7 null
        cout << c<< " "<< lista->nro << endl;
        lista = lista->sgte;
        c++;
    }
    cout << endl;
}

void insertalinicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new (struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista = q;
}

void eliminainicio(Tlista &lista)
{
    struct nodo *p;
    if (lista != NULL)                        // 4 7 null
    {
        p = lista;                            // nodolista=7  p = 4
        lista = lista->sgte;
        delete (p);
    }
}

int promedio(Tlista &lista)
{
    Tlista q;
    q = lista;
    int c = 0, s = 0;
    float x = 0;
    while (q != NULL)
    {
        s = s + q->nro; // 0 13
        c = c + 1;     /// 0 1
        q = q->sgte;
    }
    x = s / c;
    return x;
}

int busqueda(Tlista &lista, int ele)
{
    Tlista q;
    q = lista;
    int c = 1;
    while (q != NULL)
    {
        if (q->nro == ele)
        {
            cout << " Elemento " << ele << " encontrado en posicion " << c << endl;
            return 1;
        }
        q = q->sgte;  
        c++;
    }
    return 0;
}


/* Elimina de la lista todas las ocurrencias del número pasado por parámetro.
Retorna la cantidad de eliminaciones que realizó. */
int eliminar_ocurrencias(Tlista &inicio, int num) {
   int cantidad = 0;
   nodo* a_eliminar;
   nodo* aux = inicio;
   while (aux != NULL) {
       if (inicio->nro == num) {   //Este es el caso en que el elemento a eliminar está al inicio de la lista
           a_eliminar = inicio;   //  6  Inicio = 8 Aux = 8
           inicio = inicio->sgte;   // 6 -> 8 -> 4 -> 6 -> 8 -> 4
           aux = inicio;
           delete a_eliminar;
           cantidad++;
       }
       else {
           if (aux->sgte != NULL && aux->sgte->nro == num) { //Este es el caso en que el siguiente nodo se debe eliminar
               a_eliminar = aux->sgte;        // aelimar = 6 
               aux->sgte = aux->sgte->sgte;  // 8 -> 8 -> 4 -> 6 -> 8 -> 4
               delete a_eliminar;
               cantidad++;
           }
           else {  //El siguiente nodo no se debe eliminar o no hay siguiente, entonces avanzamos
               aux = aux->sgte;
           }
       }
   }
   return cantidad;
}

int main()
{
    Tlista lista = NULL;
    int opc, valor, n, i, ele, prm;
    do
    {
        cout << "1.Insertar elementos:" << endl;
        cout << "2.Eliminar elemento del inicio:" << endl;
        cout << "3.Promedio de elementos:" << endl;
        cout << "4.Buscar elemento" << endl;
        cout << "5.Mostrar lista:" << endl;
        cout << "6.Eliminar ocurrencia de lista:" << endl;
        cout << "7.Salir" << endl;
        cout << "Ingrese una opcion:" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Numero de elementos a ingresar ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Ingrese elementos: ";
                cin >> valor;
                insertalinicio(lista, valor);
            }
            break;
        case 2:
            cout << "Eliminar elemento de inicio";
            eliminainicio(lista);
            break;
        case 3:
            cout << endl
                 << "Promedio" << endl;
            prm = promedio(lista);
            cout << "El promedio de la lista es:" << prm << endl;
            break;
        case 4:
            cout << endl
                 << "Numero a buscar: " << endl;
            cin >> ele;
            if (busqueda(lista, ele) == 0)
                cout << "Elemento no encontrado";
            break;
        case 5:
            cout << endl
                 << "Listado: " << endl;
            imprimir(lista);
            break;
        case 6:
            cout << endl<< "6.Eliminar ocurrencia de lista:" << endl;
            cout<< "Numero a eliminar: " << endl;
            cin >> ele;
            eliminar_ocurrencias(lista, ele);
            break;
        }
    } while (opc != 7);

    return 0;
}
