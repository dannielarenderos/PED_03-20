#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;


struct nodoasig
{
    string codigo, descripcion;
    int cantidad;
    struct nodoasig *siguiente;
};


nodoasig *primero, *ultimo;


void iniciar()
{
    primero = NULL;
    ultimo = NULL;
}




void insertar_delante(string cod, string nomb, int cant)
{
    nodoasig *nodo;
    nodo = new nodoasig;
    nodo->siguiente = NULL;
    nodo->codigo = cod;
    nodo->descripcion = nomb;
    nodo->cantidad = cant;
    if (primero == NULL)
    {
        primero = nodo;
        ultimo = nodo;
    }
    else
    {
        nodo->siguiente = primero;
        primero = nodo;
    }
    return;
}
void mostrar()
{
    nodoasig *p;
    if (primero == NULL)
        cout << "Lista vacia";
    else
    {
        p = primero;
        while (p != NULL)
        {
            cout <<"Codigo materia: "<< p->codigo << endl;
            cout <<"Nombre materia: "<< p->descripcion << endl;
            cout <<"Horas materia: "<<p->cantidad << endl<<endl;
            p = p->siguiente;
        }
    }

}
void eliminar(string valor)
{
    nodoasig *p, *q;
    q = primero;
    p = primero;
    while ((p != NULL) && (p->codigo != valor))
    {
        q = p;
        p = p->siguiente;
    }
    if (p == NULL)
        cout << "No existe ese elemento en la lista";
    else
    {
        if (primero == ultimo)
        {
            primero = NULL;
            ultimo = NULL;
        }
        else
        {
            q->siguiente = p->siguiente;
            if (p == primero)
                primero = p->siguiente;
            else if (p == ultimo)
                ultimo = q;
        }
    }
    return;
}
int main(int argc, char *argv[])
{
    int cant;
    string cod, nombre, c;
    int opc;
    iniciar();
    do
    {
        cout << " LISTA DE ASIGNATURAS" << endl;
        cout << " Seleccione la opcion a realizar\n\n";
        cout << " 1.- Insertar una asignatura\n";
        cout << " 2.- Eliminar una asignatura\n";
        cout << " 3.- Mostrar toda la lista de asignaturas\n";
        cout << " 4.- Salir";
        cout << " \n\n\nOpcion(1-4): ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cod = "";
            nombre = "";
            cant = 0;
            cout << "Entre los Datos de la Asignatura:\n ";
            cout << "Codigo de la Asignatura: \n";
            cin >> cod;
            cout << "Nombre de la Asignatura: \n";
            cin >> nombre;
            cout << "Cantidad de Horas:\n ";
            cin >> cant;

            insertar_delante(cod, nombre, cant);
            break;
        case 2:
            cout << "Codigo de la Asignatura a eliminar: \n";
            cin >> c;
            eliminar(c);

            break;
        case 3:
            mostrar();
            cout << "Oprima una tecla para salir";
            break;
        case 4:
            exit(0);
            break;
        }
    } while ((opc != 4));
    return 0;
}