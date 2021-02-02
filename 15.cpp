#include<iostream>
#include<stdlib.h>
 
using namespace std;
 
 
typedef struct nodo elemento;


struct nodo {
    int dato;
    nodo*sig;
    nodo*ant;
    };
 
elemento* nuevonodo() {
    return ((elemento*) malloc (sizeof(elemento)));
}

int main (int argc,char** argv){
 
    elemento *p,*q,*j,*d,*i,*l;
    char r,r2;
    int c=1;
    do{
       p = nuevonodo();
        cout<<"por favor ingrese el dato: ";
        cin>>p->dato;  // 7
 
        if (c==1){
            p->sig=NULL;
            p->ant=NULL;   // null <-8 -> null
            d= p;             // null <- 8 -> null
            i= p;          // null <-8 -> null
        }
        else{
            cout<<"Quieres Insertar al derecha o izquierda? D=derecha / I=final\n";
            cin>>r2;
            if(r2 == 'd'|| r2 == 'D'){
                p->sig=NULL;       /// null <- 8 -> <- 7 -> null
                p->sig= d;
                p->ant= i;     
            }
            else{
                p->ant=NULL;                 // null <- 8 -> null
                i->ant= p;
                p->sig= i;
                i=p;
            }
        }
        c++;

        cout<<"desea agregar un nuevo valor? S=si / N=no";
        cin>>r;
    }while(r =='s'|| r=='S');
    q=i;

    
cout<<"recorrido de Izquierda..\n";
do{
    cout<<"\t"<<q->dato;
    q = q->sig;
}while (q!=NULL);


q=d;
cout<<"\nRecorrido de Derecha..?n";
do{
    cout<<"\t"<<q->dato;
    q = q->ant;
}while(q !=NULL);
 
return 0;
 
}