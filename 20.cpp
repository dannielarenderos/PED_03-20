
#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
            int nro;    //los datos seran de tipo entero
            struct nodo *sgte; //puntero
            };

typedef struct nodo;//definimos a nodo como un tipo de variable
nodo *fin;//puntero que ira siempre al final de la piniciolista
nodo *piniciolista;//puntero que para nosotros apuntara a la cabeza de nuestra piniciolista

void menu1(); //declaramos las funciones a usar
void insertarInicio();
void insertarFinal();
void mostrar();
void buscarElemento();
void eliminarElemento();
void eliminarElementos();

/*                        Funcion Principal
---------------------------------------------------------------------*/

int main(void)
{
    piniciolista = NULL;
    int op;     // opcion del menu


    do
    {
        menu1();
        cin>>op;

        switch(op)
        {
            case 1:
                    insertarInicio();
                    break;

            case 2:
                    insertarFinal();
                    break;
            case 3:
                    cout<<"\n\n pinicioLista Circular \n\n";
                    mostrar();
                    break;

            case 4:
                    buscarElemento();
                    break;

            case 5:
                    eliminarElemento();
                    break;
            case 6:
                    eliminarElementos();
                    break;

            default: cout<<"OPCION NO VALIDA...!!!";
                     break;


        }

        cout<<endl<<endl;
    

    }while(op!=7);

   return 0;
}

//////////////////////MOSTRAR MENU///////////////////////////////

void menu1()
{
    cout<<"\n\t\tpinicioLISTA ENLAZADA CIRCULAR\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. REPORTAR pinicioLISTA                   "<<endl;
    cout<<" 4. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 5. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 6. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 7. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

//////////////////////INSERTAR AL INICIO//////////////////////////

void insertarInicio()
{
   nodo *nuevo;
   nuevo=new struct nodo;

   cout<<"\n***INSERTA AL INICIO*****\n";
   cout<<"\nINGRESE DATO:";
   cin>>nuevo->nro;
   nuevo->sgte=NULL;

   if(piniciolista==NULL)    //20
                       //   9
    {
        cout<<"PRIMER ELEMENTO..!!!";
        piniciolista=nuevo;
        piniciolista->sgte=piniciolista;
        fin=nuevo;
      }
   else
     {
        nuevo->sgte = piniciolista;  // 20 -> 9 -> PInicio
        piniciolista = nuevo;   
        fin->sgte = piniciolista;
     }

}
//////////////////INSERTAR AL FINAL/////////////////////
void insertarFinal()
{
    nodo *nuevo;
    nuevo=new struct nodo;
    cout<<"\n***INSERTA AL INICIO*****\n";
    cout<<"\nINGRESE DATO:";
    cin>>nuevo->nro;
    nuevo->sgte=NULL;      // null

     if(piniciolista==NULL)   // 5 -> pInicio
        {
             cout<<"PRIMER ELEMENTO..!!!";
             piniciolista=nuevo;  
             piniciolista->sgte=piniciolista;
             fin=nuevo;
        }
     else   // 6
        {                            // 5 -> 6 -> pInicio
          fin->sgte = nuevo;
          nuevo->sgte = piniciolista;
          fin = nuevo;
        }
}
//////////////////MOSTRAR TODOS LOS DATOS////////////////////////
void mostrar()
{   nodo *aux;
    aux=piniciolista;
    int i=1;

    if(piniciolista!=NULL)
     {                      // 5 -> 6 -> 5  -> 7->  5 -> pInicio
          do
          {    cout<<" Numero "<< i<<" de la lista: "<<aux->nro ;
               aux = aux->sgte;
               i++;
          }while(aux!=piniciolista);
      }
     else
         cout<<"\n\n\tpinicioLista vacia...!"<<endl;


}
//////////////////BUSCAR ELEMENTO///////////////////////
void buscarElemento() //esta funcion muestra la posicion del primer dato coincidente
                      //encontrado en la piniciolista
{
     nodo *aux;
     int i = 1, valor , flag = 0;

     cout<<"\nINGRESE ELEMENTO A BUSCAR:";
     cin>>valor;
     if(piniciolista !=NULL)  //7
     {
          aux = piniciolista;  // 5 -> 6 -> 5  -> 7->  5 -> pInicio

          do
          {
               if(aux->nro == valor)
               {
                   cout<<"\n\n Encontrado en posicion "<< i <<endl;
                   flag=1;
               }
               else
               {
                   aux = aux->sgte;
                   i++;
               }
          }while(aux!=piniciolista);

          if(flag==0) cout<<"\n\n\tNumero no econtrado..!"<<endl;

     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;

}
////////////////ELIMINAR ELEMENTO DETERMINADO//////////////////////
void eliminarElemento()  // 7
{
    nodo *aux, *r, *q;
    int i = 1, flag = 0,valor;  


    cout<<"\n INGRESE ELEMENTO A ELIMINAR:";
    cin>>valor;

    if(piniciolista !=NULL)    // 6 -> 10  -> 7 ->  5 -> 0 -> pInicio
     {
          aux = piniciolista;

          do
          {
               if(aux->nro == valor)  // 0
                {
                    if(aux==piniciolista)//si es que el dato a eliminar es el primero
                    {   r = piniciolista;   // r = 5 pInicio  pInicio = 6   aux = 6 fin-> 6
                        piniciolista=piniciolista->sgte;     // 5 -> 6 -> 5  ->  5 0 -> pInicio
                        aux=aux->sgte;
                        fin->sgte=piniciolista;             // 5 -> 
                        r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            piniciolista==NULL;
                            aux==NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                        else
                        {
                            delete(r);  //  6 -> 5  ->  5 -> 0 -> pInicio
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                    }
                   else
                    {
                        if(aux==fin)//si es que el dato a eliminar es al que apunta a fin
                            {
                            r=aux;                  // R = 0  AUX = PInicio  Q = 5 
                            aux=aux->sgte;             //  6 -> 10  -> 7 ->  5 ->  pInicio
                            q->sgte= aux;
                            fin=q;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                            }
                        else
                        {
                            r=aux;         // R = 7     AUX = 5    Q = 10
                            aux=aux->sgte;              //  6 -> 10 ->  5 -> 0 -> pInicio
                            q->sgte=aux;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                  }
                  flag=1;
                }
                else
                {   q=aux;    //   5 
                    aux = aux->sgte;   // 0
                    i++;                   // 6 -> 10  -> 7 ->  5 -> 0 -> pInicio
                }
          }while(aux!=piniciolista);

          if(flag==0)
          cout<<"\n\n\tNumero no econtrado..!"<<endl;


    }
    else
      cout<<"pinicioLISTA VACIA...!!!!";


}
//////////////////////ELIMINAR REPETIDOS/////////////////////
void eliminarElementos()
{
     nodo *aux, *r, *q;
     int  flag = 0,valor;

     cout<<"\n DATO REPETIDO A ELIMINAR:";
     cin>>valor;

     if(piniciolista !=NULL)
        { aux=piniciolista;

            while(aux->nro==valor)//si los primeros elementos son repetidos
                if(aux==piniciolista)    //esta funcion borra a estos
                  {
                   r=piniciolista;
                   aux=piniciolista->sgte;
                   piniciolista=piniciolista->sgte;
                   fin->sgte=piniciolista;
                   r->sgte=NULL;
                    if(fin->sgte==NULL)
                     {
                        piniciolista==NULL;
                        aux==NULL;
                        delete(r);
                        flag=1;
                      }
                    else
                     {
                        delete(r);
                        flag=1;
                     }
                   }
          do
          {
               if(aux->nro == valor)
                {
                    while(aux==piniciolista)
                    {
                         r=piniciolista;
                         aux=piniciolista->sgte;
                         piniciolista=piniciolista->sgte;
                         fin->sgte=piniciolista;
                         r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            piniciolista==NULL;
                            aux==NULL;
                            delete(r);
                        }
                      else
                        delete(r);

                    }

                   if(aux==fin)//para si el elemento a borrar es apuntado por *fin
                    {
                        r=aux;
                        aux=aux->sgte;
                        q->sgte=aux;
                        fin=q;
                        r->sgte=NULL;
                        delete(r);
                    }
                    else
                    {
                        r=aux;
                        aux=aux->sgte;
                        q->sgte=aux;
                        r->sgte=NULL;
                        delete(r);
                    }

                    flag=1;
               }
               else
               {   q=aux;
                   aux = aux->sgte;
               }
          }while(aux!=piniciolista);

          if(flag==0)
            cout<<"\n\n\tNumero no econtrado..!"<<endl;
        }
          else
            cout<<"pinicioLISTA VACIA...!!!!";
}