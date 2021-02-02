#include <iostream>
#include <conio.h>

using namespace std;

/*USANDO ESTRUCTURAS PARA CREAR CADA ELEMENTO DE LA LISTA, ELEMENTOS QUE NOMBRAREMOS "NODOS"*/
struct nodo
{
	int dato;				//LOS DATOS QUE SE ALMACENARAN EN LA LISTA SERAN ENTEROS
	struct nodo *siguiente; //EL PUNTERO QUE GUARDA LA DIRECCION DEL SIGUIENTE NODO
	struct nodo *anterior;	//EL PUNTERO QUE GUARDA LA DIRECCION DEL NODO ANTERIOR
} * nuevo,					//SE USARA PARA CREAR LOS NODOS NUEVOS PARA INCERTAR EN LA LISTA
	*inicio,				//SE USARA PARA GUARDAR LA POCISION DEL INICIO DE LA LISTA
	*fin,					//SE USARA PARA GUARDAR EL FINAL DEL LA LISTA
	*aux,					//UN AUXILIAR QUE SERVIRA A LA HORA DE HACER SIERTAS OPERACIONES
	*aux2					//UN SEGUNDO AUXILIAR QUE SERVIRA A LA HORA DE HACER CIERTAS OPERACIONES
	;

//VARIABLES GLOBALES
int dato;

//ESTE DATO ES EL QUE SE USARA PARA INGRESARLO EN LA LISTA
//PROTOTIPOS
void crear();				 //CREA EL NUEVO NODO QUE SE INSERTARA EN LA LISTA
void insertarFinal();		 //INSERTARA EL NODO NUEVO AL FINAL DE LA LISTA
void insertarInicio();		 //INSERTARA EL NODO NUEVO AL INICIO DE LA LISTA
void insertarDespuesDe(int); //INSERTARA EL NODO NUEVO DESPUES DE ALGUN DATO INGRESADO
void eliminarFinal();		 //ELIMINARA EL DATO AL FINAL DE LA LISTA
void eliminarInicio();		 //ELIMINARA EL DATO AL INICIO DE LA LISTA
void eliminarDato(int);		 //ELININARA UN DATO ELEJIDO DE LA LISTA
void mostrar();				 //MOSTRARA LOS DATOS QUE EXISTEN EN ESE MOMENTO EN LA LISTA
void menu();				 //MOSTRARA EL MENU
void limpiar();				 //LIMPIA LA MEMORIA AL SALIR DEL PROGRAMA
bool buscardato(int);		 //BUSCA UN DATO EN LA LISTA
//FUNCIONES
//funcion principal


int main()
{
	char op = ' '; /*OPCION A ELEGIR EN EL MENU, RECOMENDADO USAR 'CHAR' PARA EVITAR PROBLEMAS A LA HORA DE INGRESAR UNA LETRA*/
	while (op != '8')
	{				   /*SE CREA UN BUCLE CON LA CONDICION DE: MIENTRAS LA OPCION SELECCIONADA SEA DIFERENTE A LA OPCION DE SALIDA*/
		 //SE LIMPIA LA PANTALLA
		menu();		   //SE IMPRIME EL MENU
		cin >> op;	   //SE RECIBE LA OPCION ELEGIDA POR EL USUARIO
		switch (op)
		{																  /*SE CREA UN SWITCH PARA PODER ELEJIR LA OPCION DEL MENU A EJECUTAR SEGUN LA OPCION ELEGIDA POR EL USUARIO*/
		case '1':														  //SE ABRE EL CASO EN QUE LA OPCION SEA 1
															  //SE LIMPIA LA PANTALLA
			cout << "\n\tDIGITE EL DATO QUE DESEA INGRESAR A LA LISTA: "; //SE IMPRIME LA INSTRUCCION DE INGRESO DE DATO
			cin >> dato;												  //SE RECIBE EL DATO INGRESADO POR EL USUARIO
			insertarFinal();											  //SE LLAMA LA FUNCION PARA INCERTAR EL DATO AL FINAL
			break;														  //INDICAMOS QUE SALGA DEL CASE
		case '2':
														  //SE LIMPIA LA PANTALLA
			cout << "\n\tDIGITE EL DATO QUE DESEA INGRESAR A LA LISTA: "; //SE IMPRIME LA INSTRUCCION DE INGRESO DE DATO
			cin >> dato;												  //SE RECIBE EL DATO INGRESADO POR EL USUARIO
			insertarInicio();											  //SE LLAMA LA FUNCION PARA INCERTAR EL DATO AL INICIO
			break;														  //INDICAMOS QUE SALGA DEL CASE
		case '3':
			//SE LIMPIA LA PANTALLA
			int ant;
			cout << "\n\tDIGITE EL DATO QUE DESEA INGRESAR A LA LISTA: ";				   //SE IMPRIME LA INSTRUCCION DE INGRESO DE DATO
			cin >> dato;																   //SE RECIBE EL DATO INGRESADO POR EL USUARIO
			cout << "\n\tDIGITE EL DATO ANTERIOR AL DATO QUE DESEA INGRESAR A LA LISTA: "; /*SE IMPRIME LA INSTRUCCION DE INGRESO DE DATO QUE VA ANTES DEL DATO A INGRESAR*/
			cin >> ant;																	   //SE RECIBE EL DATO INGRESADO POR EL USUARIO
			insertarDespuesDe(ant);														   //SE LLAMA LA FUNCION PARA INCERTAR EL DATO AL INICIO
			break;																		   //INDICAMOS QUE SALGA DEL CASE
		case '4':
			
			eliminarFinal();				//SE LLAMA LA FUNCION PARA ELIMINAR EL ULTIMO DATO DE LA LISTA
			cout << "\n\n\tDATO ELIMINADO"; //SE INDICA QUE EL DATO FUE ELIMINADO
			_getch();
			break; //INDICAMOS QUE SALGA DEL CASE
		case '5':
			
			eliminarInicio();				//SE LLAMA LA FUNCION PARA ELIMINAR EL PRIMER DATO DE LA LISTA
			cout << "\n\n\tDATO ELIMINADO"; //SE INDICA QUE EL DATO FUE ELIMINADO
			_getch();
			break; //INDICAMOS QUE SALGA DEL CASE
		case '6':
			int anterior;										 //SE VREA UNA VARIABLE PARA GUARDAR EL NUMERO QUE EL USUARIO DESEA ELIMINAR
												 //SE LIMPIA LA PANTALLA
			cout << "\n\n\tINGRESE EL VALOR QUE DESEA BORRAR: "; //SE PIDE EL DATO QUE EL USUARIO DESEA ELIMINAR
			cin >> anterior;									 //SE RECIBE EL DATO QUE SE DESEA ELIMINAR
			if (buscardato(anterior) == true)
			{									//SI EL DATO EXISTE EN LA LISTA
				eliminarDato(anterior);			//SE LLAMA LA FUNCION PARA ELIMINAR UN DATO EN CONCRETO
				cout << "\n\n\tDATO ELIMINADO"; //SE INDICA QUE EL DATO FUE ELIMINADO
			}
			else
				cout << "\n\n\tDATO INEXISTENTE";
			_getch();
			break; //INDICAMOS QUE SALGA DEL CASE
		case '7':
			 //SE LIMPIA LA PANTALLA
			if (inicio)
				mostrar();
			else
				cout << "\n\n\tLista vacia";
			break; //INDICAMOS QUE SALGA DEL CASE
		case '8':
			//SE LIMPIA LA PANTALLA
			limpiar();
			cout << "\n\nsaliendo...";
			_getch();
			break; //INDICAMOS QUE SALGA DEL CASE
		}
	}

	return 0;
}

//funcion menu
void menu()
{
	cout << "\n\n\t\tMENU";
	cout << "\n\t1| INCERTAR AL FINAL DE LA LISTA";
	cout << "\n\t2| INCERTAR AL INICIO DE LA LISTA";
	cout << "\n\t3| INCERTAR DESPUES DE UN DATO";
	cout << "\n\t4| BORRAR EL ULTIMO DATO DE LA LISTA";
	// cout << "\n\t5| BORRAR EL PRIMER DATO DE LA LISTA";
	// cout << "\n\t6| BORRAR UN DATO ELEJIDO DE LA LISTA";
	cout << "\n\t7| MOSTRAR LA LISTA";
	cout << "\n\t8| SALIR";
	cout << "\n\tingrese una opcion: ";
}

//funcion crear
void crear()
{
	nuevo = new nodo; //SE RESERVA EL ESPACIO DE MEMORIA PARA EL PUNTERO "NUEVO"
	if (nuevo)
	{							 //SI EL ESPACIO DE NUEVO ES DIFERENTE DE NULL, ES DECIR SI NUEVO TIENE UN ESPACIO DE MEMORIA
		nuevo->siguiente = NULL; //SE IGUALA EL ELEMENTO QUE APUNTA AL SIGUIETE ELEMENTO A NULL
		nuevo->dato = dato;		 //SE INGRESA EL DATO DIGITADO POR EL USUARIO A EL DATO EN EL NODO
		nuevo->anterior = NULL;	 //SE IGUALA EL ELEMENTO QUE APUNTA AL ANTERIOR ELEMENTO A NULL
	}
}

//funcion incertar al final
void insertarFinal()
{
	crear(); //SE CREA EL NUEVO NODO
	if (!inicio)
	{							//SI INICIO ES IGUAL A NULL, ES DECIR QUE LA LISTA ESTA VACIA
		inicio = new nodo;		//SE APARTA EL ESPACIO DE INICIO   b   // <-6  ->  <-5 -> <- null
		fin = new nodo;			//SE APARTA EL ESPACIO DE FIN
		inicio = nuevo;			//INICIO SE IGUALA A NUEVO, PARA GUARDAR LA UBICACION DEL PRIMER ELEMENTO EN INICIO.
		nuevo->siguiente = fin; /*SE INDICA QUE EL SIGUIENTE ELEMENTO DE LA LISTA ES FIN PARA PODER MANTENER EL ULTIMO ELEMENTO*/
		fin->anterior = nuevo;	/*SE INDICA QUE EL ELEMENTO ANTERIOR A FIN ES EL NODO PARA MANTENER LA REGLA DE LA LISTA DOBLEMENTE ENCADENADA*/
	}
	else
	{								  //EN CASO CONTRARIO
		aux = inicio;				  //IGUALAMOS AUX A INICIO, PARA PODER RECORRER LA LISTA Y NO CAMBIAR EL VALOR DE INICIO
		while (aux->siguiente != fin) /*RECORREMOS LA LISTA CON LA CONDICION: MIENTRAS EL SIGUIENTE ELEMENTO A AUXILIAR SEA DIFERENTE AL FINAL*/
			aux = aux->siguiente;  
			                                   //       4                 //  <- 6  ->  <- 5 -> <- 4 -> <-null
				  //SE IGUALA EL AUXILIAR AL SIGUIENTE ELEMENTO
		aux->siguiente = nuevo;		  //IGUALAMOS QUE EL SIGUIENTE DATO DESPUES DE AUXILIAR ES EL NUEVO NODO
		nuevo->anterior = aux;		  //Y QUE EL DATO ANTERIOR AL NUEVO NODO ES EL AUXILIAR
		nuevo->siguiente = fin;		  //LUEGO INDICAMOS QUE EL NODO NUEVO APUNTA A FIN
		fin->anterior = nuevo;		  //Y QUE EL ANTERIOR A FIN ES EL NUEVO NODO
	}
}

//funcion insertar al incio
void insertarInicio()
{
	crear(); //SE CREA EL NUEVO NODO
	if (!inicio)
	{							//SI INICIO ES IGUAL A NULL, ES DECIR QUE LA LISTA ESTA VACIA
		inicio = new nodo;		//SE APARTA EL ESPACIO DE INICIO
		fin = new nodo;			//SE APARTA EL ESPACIO DE FIN
		inicio = nuevo;			//INICIO SE IGUALA A NUEVO, PARA GUARDAR LA UBICACION DEL PRIMER ELEMENTO EN INICIO.
		nuevo->siguiente = fin; /*SE INDICA QUE EL SIGUIENTE ELEMENTO DE LA LISTA ES FIN PARA PODER MANTENER EL ULTIMO ELEMENTO*/
		fin->anterior = nuevo;	/*SE INDICA QUE EL ELEMENTO ANTERIOR A FIN ES EL NODO PARA MANTENER LA REGLA DE LA LISTA DOBLEMENTE ENCADENADA*/
	}
	else
	{							//EN CASO CONTRARIO
		aux = inicio;			//IGUALAMOS AUX A INICIO, PARA NO CAMBIAR EL VALOR DE INICIO
		nuevo->siguiente = aux; //SE INDICA QUE EL SIGUIENTE ELEMENTO A NUEVO SERA AUXILIAR ( ANRIGUO INCIO )
		aux->anterior = nuevo;	//SE INDICA QUE EL VALOR ANTERIOR AL AUXILIAR SERA NUEVO
		inicio = nuevo;			//SE INDICA QUE EL INICIO AHORA ES NUEVO
	}
}

//funcion insertar después de otro dato
void insertarDespuesDe(int anterior)
{
	crear(); //SE CREA EL NUEVO NODO
	if (!inicio)
	{							//SI INICIO ES IGUAL A NULL, ES DECIR QUE LA LISTA ESTA VACIA
		inicio = new nodo;		//SE APARTA EL ESPACIO DE INICIO
		fin = new nodo;			//SE APARTA EL ESPACIO DE FIN
		inicio = nuevo;			//INICIO SE IGUALA A NUEVO, PARA GUARDAR LA UBICACION DEL PRIMER ELEMENTO EN INICIO.
		nuevo->siguiente = fin; /*SE INDICA QUE EL SIGUIENTE ELEMENTO DE LA LISTA ES FIN PARA PODER MANTENER EL ULTIMO ELEMENTO*/
		fin->anterior = nuevo;	/*SE INDICA QUE EL ELEMENTO ANTERIOR A FIN ES EL NODO PARA MANTENER LA REGLA DE LA LISTA DOBLEMENTE ENCADENADA*/
	}
	else
	{				  //EN CASO CONTRARIO
		aux = inicio; //IGUALAMOS AUX A INICIO, PARA PODER RECORRER LA LISTA Y NO CAMBIAR EL VALOR DE INICIO
		while (aux->siguiente != fin)
		{							   /*RECORREMOS LA LISTA CON LA CONDICION: MIENTRAS EL SIGUIENTE ELEMENTO A AUXILIAR SEA DIFERENTE AL FINAL*/
			if (aux->dato == anterior) /*SE CREA UNA CONDICION DENTRO DEL BUCLE PARA QUE CUANDO EL VALOR DEL DATO ANTERIOR SEA IGUAL AL DATO EN LA LISTA, LA DIRECCION DE ESTE SE GUARDE EN AUXILIAR 2*/
				aux2 = aux;			   //SE IGUALA EL AUXILIAR 2 A AUXILIAR
			aux = aux->siguiente;	   //SE IGUALA EL AUXILIAR AL SIGUIENTE ELEMENTO
		}
		if (!aux2)							 //SI EL AUXILIAR 2 QUEDA BASILLO
			cout << "EL ELEMENTO NO EXISTE"; //SE INDICA QUE EL DATO NO EXISTE, POR LO QUE NO SE INGRESARA EL NUEVO DATO
		else
		{								//SI EL AUXILIAR 2 SI TIENE ALGUN DATO
			if (aux2->siguiente == fin) //SI EL AUXILIAR 2 ES EL ULTIMO DATO DE LA LISTA
				insertarFinal();		//SE USA LA FUNCION DE INCERTAR AL FINAL
			else
			{							 //SI EL AUXILIAR 2 ES UN DATO DIFERENTE AL DATO FINAL ( INCLUYENDO AL DATO INICIAL)
				aux = aux2->siguiente;	 //SE TOMA EL SIGUIETE DATO Y SE GUARDA EN AUXILIAR
				aux2->siguiente = nuevo; //SE INCERTA EL NUEVO NODO COMO EL SIGUIENTE DATO
				nuevo->anterior = aux2;	 //SE INDICA QUE EL DATO ANTERIOR AL NUEVO DATO ES EL AUXILIAR 2
				aux->anterior = nuevo;	 //SE INDICA QUE EL DATO ANTERIOR AL DATO GUARDADO EN AUXILIAR ES NUEVO
				nuevo->siguiente = aux;	 /*SE TERMINA LA CONECCION DE LOS DATOS DE LA LISTA INDICANDO QUE DESPUES DE NUEVO VA EL AUXILIAR*/
			}
		}
	}
}

//funcion mostrar
void mostrar()
{
	aux = inicio; //SE IGUALA AUXILIAR A INICIO PARA QUE AL RECORRER LA LISTA NOS SE PIERDA EL VALOR DE INICIO
	while (aux->siguiente != fin)
	{							  //MIENTRAS EL AUXILIAR NO SEA ULTIMO DATO
		cout << " " << aux->dato; //SE IMPRIME EL DATO DE AUXILIAR
		aux = aux->siguiente;	  //SE PASA AL DATO SIGUIENTE
	}
	cout << " " << aux->dato; //SE IMPRIME EL ULTIMO DATO
	_getch();				  //SE DEJA EN ESPERA POR EL USUARIO A QUE PRECIONE ALGUNA TECLA
}

void limpiar()
{
	if (inicio)
	{
		aux = inicio->siguiente; //SE IGUALA AUXILIAR AL SEGUNDO DATO
		free(inicio);			 //SE LIBERA EL ESPACIO DE MEMORIA DEL PRIMER DATO
		while (aux->siguiente != fin)
		{						  //MIENTRAS EL DATO NO SEA EL ULTIMO DATO
			aux = aux->siguiente; //SI IGUALA AUXILIAR AL DATO SIGUIENTE
			free(aux->anterior);  //SE LIBERA EL ESPACIO DE MEMORIA DEL DATO ANTERIOR
		}
		free(aux); //SE LIBERA EL ESPACIO DE MEMORIA DEL ULTIMO DATO
		free(fin); //SE LIBERA EL ESPACIO DE MEMORIA DEL FINAL DE LA LISTA
	}
}

//funcion eliminar el ultimo dato
void eliminarFinal()
{
	if (inicio->siguiente == fin) //SI EL PRIMER DATO ES EL UNICO DATO DE LA LISTA
		free(inicio);			  //ELIMINAMOS EL UNICO DATO
	else
	{
		aux = inicio;					//SE IGUALA AUXILIAR A INICIO PARA QUE AL RECORRER LA LISTA NO SE PIERDA EL VALOR DE INICIO
		while (aux->siguiente != fin)	//MIENTRAS AUXILIAR SEA DIFERENTE DEL DATO FINAL
			aux = aux->siguiente;		//AUXILIAR PASA A SER EL SIGUIENTE DATO
		aux->anterior->siguiente = fin; //SE INDICA QUE EL VALOR ANTERIOR AL ULTIMO DATO ES EL ULTIMO DATO
		fin->anterior = aux->anterior;	//INDICAMOS QUE EL VALOR ANTERIOR AL FIN DE LA LISTA ES FIN
		free(aux);						//LIBERAMOS AUXILIAR
	}
}

//funcion eliminar el primer dato
void eliminarInicio()
{
	if (inicio->siguiente == fin) //SI EL PRIMER DATO ES EL UNICO DATO DE LA LISTA
		free(inicio);			  //ELIMINAMOS EL UNICO DATO
	else
	{
		aux = inicio;			 //SE IGUALA AUXILIAR A INICIO PARA PODER BORRAR EL INICIO SIN AFECTAR LA LISTA
		inicio = aux->siguiente; //SE INDICA QUE EL NUEVO INICIO ES EL SEGUNDO DATO
		free(aux);				 //SE LIBERA EL AUXILIAR
	}
}

//funcion eliminar dato en concreto
void eliminarDato(int dat)
{
	if (inicio->siguiente == fin) //SI EL PRIMER DATO ES EL UNICO DATO DE LA LISTA
		free(inicio);			  //ELIMINAMOS EL UNICO DATO
	else
	{
		aux = inicio;		  //SE IGUALA AUXILIAR A INICIO PARA QUE AL RECORRER LA LISTA NO SE PIERDA EL VALOR DE INICIO
		if (aux->dato == dat) //SI EL DATO A ELIMINAR ES EL PRIMER DATO DE LA LISTA
			eliminarInicio(); //SE EJECUTA LA FUNCION PARA ELIMINAR EL PRIMER DATO
		else
		{
			while (aux->dato != dat)  //MIENTRAS AUXILIAR SEA DIFERENTE DEL DATO FINAL
				aux = aux->siguiente; //AUXILIAR PASA A SER EL SIGUIENTE DATO
			if (aux->siguiente = fin) //SI EL DATO A ELIMINAR ES EL ULTIMO DATO DE LA LISTA
				eliminarFinal();	  //SE EJECUTA LA FUNCION ELIMINAR EL ULTIMO DATO
			else
			{
				aux2 = aux->siguiente;			 //GUARDAMOS EL SIGUIENTE VALOR EN AUXILIAR 2
				aux->anterior->siguiente = aux2; //INDICAMOS QUE EL DATO ANTERIOR AL QUE SE ELIMINARA ES SEGUIDO POR EL SIGUIENTE DEL QUE SE ELIMINARA
				aux2->anterior = aux->anterior;	 //INDICAMOS QUE EL VALOR ANTERIOR AL SIGUIENTE A BORRAR ES EL VALOR ANTERIOR AL QUE SE BORRARA
				free(aux);						 //SE ELIMINA EL VALOR
			}
		}
	}
}

bool buscardato(int dat)
{
	aux = inicio; //IGUALAMOS AUXILIAR A INICIO PARA NO PERDER EL VALOR DE INICIO
	while (aux->siguiente != fin)
	{						  //RECORREMOS LA LISTA PARA BUSCAR EL VALOR
		if (aux->dato == dat) //SI EL DATO EN LA LISTA ES IGUAL AL DATO QUE SE BUSCA
			return true;	  //REGRESA VERDADERO
		aux = aux->siguiente; //SI NO CONTINUA BUSCANDO
	}
	return false; //SI NO SE ENCONTRO EL DATO REGRESA FALSO
}