#pragma once

#include "Movimientos.h"

#ifndef __ListaDoble_h__
#define __ListaDoble_h__
#if !defined(NULL)
#define NULL 0
#endif
#if !defined(FALSE)
#define FALSE 0
#endif
#if !defined(TRUE)
#define TRUE 1
#endif
//...Tipo Movimiento
//typedef enum
//{
//	LS_PRIMERO,
//	LS_SIGUIENTE,
//	LS_ANTERIOR
//} TMovimiento_Ls;

//...Tipo de nodo en la Lista
typedef struct TNodoDoble
{
	int* Elem;
	struct TNodoDoble *Siguiente;
	struct TNodoDoble *Anterior;
} TNodoDoble;

//...Tipo de Lista Simple
typedef struct
{
	TNodoDoble *Primero, *Corriente;
	int TamanioDato;
	int Long;
} TListaDoble;


/* ld_Crear
Pre: Ld no fue creada.
Post: Ld creada y vacía
*/
void ld_Crear(TListaDoble *pLd, int TamanioDato);

/* ld_Vaciar
Pre: Ld creada.
Post: Ld vacía.
*/
void ld_Vaciar(TListaDoble *pLd);

/* ld_Vacia
Pre: Ld creada.
Post: Si Ld tiene elementos devuelve FALSE sino TRUE.
*/
int ld_Vacia(TListaDoble Ld);

/* ld_ElemCorriente
Pre: Ld creada y no vacía.
Post: Se devuelve en E el elemento corriente de la lista.
*/
void ld_ElemCorriente(TListaDoble *pLd, int* pE);

/* ls_ModifCorriente
Pre: Ld creada y no vacía.
Post: El contenido del elemento actual quedo actualizado con E.
*/
void ld_ModifCorriente(TListaDoble *pLd, int* pE);

/* ls_MoverCorriente
Pre:  Ls creada y no vacía.
Post: Si Ls está vacía, devuelve FALSE. Sino:
Si M = LS_PRIMERO, el nuevo elemento corriente es el primero. Devuelve TRUE
Si M = LS_SIGUIENTE, el nuevo elemento corriente es el siguiente al
anterior. Si estaba en el último elemento, devuelve FALSE, sino TRUE.
Si M = LS_ANTERIOR, devuelve FALSE.
*/
bool ld_MoverCorriente(TListaDoble *pLd, TMovimiento_Ls M);

/* ld_BorrarCorriente
Pre:  Ld creada y no vacía.
Post: Se eliminó el elemento corriente, El nuevo elemento es el siguiente o
el anterior si el corriente era el último elemento.
*/
void ld_BorrarCorriente(TListaDoble *pLd);

/* ld_Insertar
Pre:  Ld creada.
Post: E se agregó a la lista y es el actual elemento corriente.
Si M=LS_PRIMERO: se insertó como primero de la lista.
Si M=LS_SIGUIENTE: se insertó después del elemento corriente.
Si M=LS_ANTERIOR: se insertó antes del elemento corriente.
Si pudo insertar el elemento devuelve TRUE, sino FALSE.
*/
int ld_Insertar(TListaDoble *pLd, TMovimiento_Ls M, int* E);


/* Ver_Lista
Pre:  Ld creada no vacia.
Post: Imprime contenido de la lista por pantalla
*/
void ld_Ver(TListaDoble* pLd);

/* ld_CompSig
Pre:  Ld creada no vacia.
Post: Si siguiente es mayor devuelve TRUE
*/
bool ld_CompSig(TListaDoble* pLd);

/* ld_IntrCorr
Pre:  Ld creada no vacia.
Post: Cambia el corriente con el movimiento
*/
bool ld_IntrCorr(TListaDoble* pLd, TMovimiento_Ls M);
#endif

