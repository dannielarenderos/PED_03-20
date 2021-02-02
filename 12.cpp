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
    void mostrarListaSimpleAsistentes();
    void insertarFinalLista(int);
    void insFinal(int, string, int, int, bool);
    bool buscarEnListaSimple(int carneBuscar);
    bool buscarEstudiantePresencial(int carneBuscar);
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
        cout << "Digite la asistencia (0. si no asistio y 1. si asistio): " << endl;
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

void ListaSimple::mostrarListaSimpleAsistentes()
{
    nodo *p;
    cout << "La lista de estudiantes es: " << endl;
    p = pInicioCola;
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
    else
    {
        nodo *s = pInicioCola;
        while (s->sig) //Extendido: s->sig != NULL
            s = s->sig;
        s->sig = nuevo;
    }
}

bool ListaSimple::buscarEnListaSimple(int carneBuscar)
{
    nodo *s;
    int cont = 1;
    s = pInicioPila;
    while (s && (s->carne != carneBuscar))
    {
        s = s->sig;
        cont++;
    }
    if (s)
    {
        cout << "Estudiante encontrado en la posicion " << cont << endl;
        return true;
    }
    else
    {
        cout << "Estudiante no encontrado " << endl;

        return false;
    }
}

bool ListaSimple::buscarEstudiantePresencial(int carneBuscar)
{
    nodo *s;
    int cont = 1;
    s = pInicioCola;
    while (s && (s->carne != carneBuscar))
    {
        s = s->sig;
        cont++;
    }
    if (s)
    {
        cout << "Estudiante encontrado en la posicion " << cont << endl;
        return true;
    }
    else
    {
        cout << "Estudiante no encontrado " << endl;

        return false;
    }
}

int main(void)
{
    ListaSimple objListaSimple;
    int opc, n, carne;
    do
    {
        cout << "1.Insertar estudiantes:" << endl;
        cout << "2.Mostrar todos estudiantes" << endl;
        cout << "3.Mostrar estudiantes con asistencia presencial" << endl;
        cout << "4.Buscar estudiante" << endl;
        cout << "5.Buscar estudiante con asistencia presencial" << endl;
        cout << "6. Salir" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Numero de estudiantes a ingresar ";
            cin >> n;
            objListaSimple.InsertarEstudianteLista(n);
            break;
        case 2:
            cout << "Mostrar todos estudiantes" << endl;
            objListaSimple.mostrarListaSimple();
            break;
        case 3:
            cout << "3.Mostrar estudiantes con asistencia presencial" << endl;
            objListaSimple.mostrarListaSimpleAsistentes();
            break;
        case 4:
            cout << endl<< "4.Buscar estudiante" << endl;
            cout << "Carne de estudiantes a buscar "<<endl;
            cin >> carne;
            objListaSimple.buscarEnListaSimple(carne);
            break;
        case 5:
            cout << endl<< "5.Buscar estudiante con asistencia presencial" << endl;
            cout << "Carne de estudiantes a buscar "<<endl;
            cin >> carne;
            objListaSimple.buscarEstudiantePresencial(carne);
            break;
        }
    } while (opc != 6);

    return 0;
}
