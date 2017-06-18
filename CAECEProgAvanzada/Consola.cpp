# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include  <ctype.h>
#include  <string.h>
#include  "stdafx.h"
# include "Consola.h"
# include "ListaSimple.h"
# include "ListaDoble.h"
# include "ListaDobleO.h"

void help()
{
	printf("Comandos del simulador\n");
	printf("======================\n\n");
	printf("CONNECT<nro. placa>\n\n");
	printf("DISCONNECT<nro. placa>\n\n");
	printf("SEND<placa origen><placa destino><puerto><indicador de prioridad (opcional) '!'><mensaje>\n\n");
	printf("EJ: send 10 25 8080 !Hola\n\n");
	printf("<placa Destino> es igual a <DIR_BROADCAST> se envia el mensaje a todas las placas conectadas\n\n");
	printf("RECV <placa><puerto>\n\n");
	printf("CLS - Borra pantalla\n\n");
	printf("LIST - Lista las placas creadas y conectadas \n\n");
	printf("EXIT - Salir del programa\n");
}

/*Cabecera de PROGRAMA*/
void Display_Header()
{
	printf("------------------------------------------------------------------------------\n\n");
	printf("\n\PROGRAMACION AVANZADA - CAECE\n\n");
	printf("------------------------------------------------------------------------------\n\n");
	printf(" El programa genera listas, Ord o Simples y evaluara los tiempos de bsuqueda. ?\n");
	printf("------------------------------------------------------------------------------\n\n");
}

/*Inicio del programa*/
void Inicio_Programa( TListaSimple* pLs, TListaDoble* pLd, TListaDoble* pLdo)
{
//...Defincion de Variables
	int  Elem;
	bool Flag;

//...Inicio Funcion
	printf("\n\LISTA CREAR\n\n");
	ls_Crear(pLs,  sizeof(TListaSimple));
	ld_Crear(pLd,  sizeof(TListaDoble));
	ld_Crear(pLdo, sizeof(TListaDoble));

	//...Cargar Lista
	Flag = TRUE;
	printf("\n\Ingrese valor de lista, finalice con 0 \n\n");
	while (Flag != FALSE) {
		scanf("%i", &Elem);; //("%i", ); //Ingreso de Enteros

		if (Elem == 0) {
			Flag = FALSE;
		}
		else 
		{ 
			ls_Insertar( pLs, LS_PRIMERO, &Elem); 
			ld_Insertar(pLd, LS_PRIMERO, &Elem);
			ld_InsertarOrd(pLdo, &Elem);
		}
	}
}

/*Convertir Instruccion en mayuscula*/
int Convert_to_upper(char* comandos)
{
	int i; /*contador*/
	int textoNorm;   /*  flag que cuenta la cantidad de espacios */
					 /* iniciializamos variables*/
	
	i = 0;
	textoNorm = 0;
	for (i = 0; comandos[i]; i++)
	{
		if (comandos[i] == ' ')
		{
			textoNorm++;
		}
		if (textoNorm<4)  //convierte en mayuscula todo el texto antes del tercer espacio
		{ 
			comandos[i] = tolower(comandos[i]); //toupper(comandos[i]);
		}
	}
	return 0;
}

/*int salir(TListaSimple *pLs, TListaSimpleOrd *terminar, TListaSimple *lista_Direcciones)
{
	T_elem_list elem_List;
	TMovimiento_Ls mov;
	printf("programa terminado");
	mov = LS_PRIMERO;
	*terminar = 0;
	while ((!ls_Vacia(*lista_Direcciones)) && (ls_MoverCorriente(lista_Direcciones, mov)))
	{
		mov = LS_SIGUIENTE;
		ls_ElemCorriente(*lista_Direcciones, &elem_List);
		Mux_Destruir(elem_List.Ptr_Mux);
		Placa_Destruir(elem_List.Ptr_placa);
		ls_BorrarCorriente(lista_Direcciones);
	}
	return 0;
}
*/