#pragma once
//...Tipo Movimiento
typedef enum
{
	BBIN, //Busqueda Binaria
	bbin, //Busqueda Binaria
	BSEC, //Busqueda Secuencial
	bsec, //Busqueda Secuencial 
	BPAR, //Busqueda Partida Paralela
	bpar, //Busqueda Partida Paralela
	LD,	  //Lista Doble	
	ld,	  //Lista Doble	
	LS,   //Lista Simple
	ls,   //Lista Simple
	LO,   //Lista Ordenada
	lo,   //Lista Ordenada
	SDO,  //Lista Simple + Doble + Ordenada
	sdo   //Lista Simple + Doble + Ordenada
} TComando; 

/**
Descripcion: Muestra ayuda al usuario
Pre:
Post:
**/
void ayuda();

/**
Descripcion: Valida el comando del Usuario
Pre: N/A
Post:Devuelve verdadero si el comando es Valido, Falso en caso contrario
**/
bool usr_Comando(char* comU);


bool Convert_to_upper(char* comU);