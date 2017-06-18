#pragma once

#include "ListaSimple.h"
#include "ListaDoble.h"

/**
Descripcion: convierte los comandos ingresados por consola a mayuscula
	Pre: comandos[] no esta vacio
	Post: retorna los comandos recibidos por parametro en mayuscula y <> 0 si no se pudo convertir
**/
int Convert_to_upper(char* comandos);

/*
Descripcion: Muestra ayuda al usuario
	Pre:  N/A
	Post: Imprime Ayuda por pantalla
*/
void help();

/*
Descripcion: Muestra encabezado
	Pre: N/A
	Post:Imprime encabezado al inicio del Programa
*/
void Display_Header();

/**
Descripcion: Inicio del programa, crea la lista
Pre: N/A
Post: Se crea una lista con los datos ingresados por el usuario
**/
void Inicio_Programa(TListaSimple* pLs, TListaDoble* pLd, TListaDoble* pLdo);