/*
* Listasimple.c
*/

#include "ListaDoble.h"
#include "stdafx.h"
#include <malloc.h>
#include <memory.h>
#include <iostream>

/* ls_Crear
Pre: Ls no fue creada.
Post: Ls creada y vacía
*/
void ld_Crear(TListaDoble *pLd, int TamanioDato)
{
	pLd->Corriente = NULL;
	pLd->Primero   = NULL;
	pLd->Long      = 0;
	pLd->TamanioDato = TamanioDato;
}

/* ld_Vaciar
Pre:  Ld creada.
Post: Ld vacía.
*/
void ld_Vaciar(TListaDoble *pLd)
{
	TNodoDoble *pNodo, *siguiente;
	for (pNodo = pLd->Primero; (pNodo); pNodo = siguiente)
	{
		siguiente = pNodo->Siguiente;
		free(pNodo->Elem);
		free(pNodo);
	}
	pLd->Primero = pLd->Corriente = NULL;
}

/* ld_Vacia
Pre: Ld creada.
Post: Si Ls tiene elementos devuelve FALSE sino TRUE.
*/
int ld_Vacia(TListaDoble Ld)
{
	return (Ld.Primero == NULL);
}

/* ld_ElemCorriente
Pre: Ls creada y no vacía.
Post: Se devuelve en E el elemento corriente de la lista.
*/
void ld_ElemCorriente(TListaDoble *Ld, int *pE)
{
	//...Copia los primeros Ls->TamanioDato, apuntados por Ls->Corriente->Elem en el puntero pE.	
	memcpy(pE, Ld->Corriente->Elem, Ld->TamanioDato);
}

/* ld_ModifCorriente
Pre: Ld creada y no vacía.
Post: El contenido del elemento actual quedo actualizado con E.
*/
void ld_ModifCorriente(TListaDoble *pLd, int* pE)
{
	//...Copia los primeros pLd->TamanioDato, apuntados por pE en el puntero pLd->Corriente->Elem.	
	memcpy(pLd->Corriente->Elem, pE, pLd->TamanioDato);
}

/* ls_MoverCorriente
Pre: Ls creada y no vacía.
Post: Si Ls está vacía, devuelve FALSE. Sino:
Si M = LS_PRIMERO, el nuevo elemento corriente es el primero. Devuelve TRUE
Si M = LS_SIGUIENTE, el nuevo elemento corriente es el siguiente al
anterior. Si estaba en el último elemento, devuelve FALSE, sino TRUE.
Si M = LS_ANTERIOR, devuelve FALSE.
*/
bool ld_MoverCorriente(TListaDoble *pLd, TMovimiento_Ls M)
{
	switch (M)
	{
	case LS_PRIMERO: pLd->Corriente = pLd->Primero;
		break;
	case LS_SIGUIENTE:
		if (pLd->Corriente->Siguiente == NULL)
			return FALSE;
		else
			pLd->Corriente = pLd->Corriente->Siguiente;
		break;
	case LS_ANTERIOR:
			if (pLd->Corriente == pLd->Primero)
				return FALSE;
			else
				pLd->Corriente = pLd->Corriente->Anterior;
			break;
	default:
				return FALSE;
	}
	return TRUE;
}

/* ld_BorrarCorriente
Pre:  Ls creada y no vacía.
Post: Se eliminó el elemento corriente, El nuevo elemento es el siguiente o
el anterior si el corriente era el último elemento.*/
void ld_BorrarCorriente(TListaDoble *pLd)
{
	TNodoDoble *PNodo = pLd->Corriente;
	if (pLd->Corriente == pLd->Primero)
	{
		pLd->Primero = pLd->Corriente->Siguiente;
		pLd->Corriente = pLd->Primero;
		pLd->Corriente->Anterior = NULL;
	}
	else
	{
		TNodoDoble *PSig = pLd->Corriente->Siguiente;
		TNodoDoble *PAnt = pLd->Corriente->Anterior;
		pLd->Corriente = PAnt;
		pLd->Corriente->Siguiente = PSig;
		PSig->Anterior = pLd->Corriente;
	}
	pLd->Long--;
	free(PNodo->Elem);
	free(PNodo);
}

/* ld_Insertar
Pre:  Ld creada.
Post: E se agregó a la lista y es el actual elemento corriente.
	Si M=LS_PRIMERO: se insertó como primero de la lista.
	Si M=LS_SIGUIENTE: se insertó después del elemento corriente.
	Si M=LS_ANTERIOR: se insertó antes del elemento corriente.

Si pudo insertar el elemento devuelve TRUE, sino FALSE.
*/
int ld_Insertar(TListaDoble *pLd, TMovimiento_Ls M, int* pE)
{
	TNodoDoble *pNodo = (TNodoDoble*)malloc(sizeof(TNodoDoble));
	if (!pNodo)
		return FALSE; /*No hay memoria disponible*/

//...Si está vacía o hay que insertar en el primero o hay que insertar en el 
//...anterior y el actual es el primero
	if ((pLd->Primero == NULL) || (M == LS_PRIMERO) ||
			((M == LS_ANTERIOR) && (pLd->Primero == pLd->Corriente)))
		{
			pNodo->Siguiente		= pLd->Primero;
			pNodo->Anterior			= NULL;

			if (pLd->Primero != NULL) {
				pLd->Primero->Anterior = pNodo;
			}
			pLd->Primero = pLd->Corriente = pNodo;
		}

//...Si cargo en el LS_SIGUIENTE o LS_ANTERIOR 
	else
	{
		switch (M)
		{
			//...Siguiente al elemento Corriente
		case LS_SIGUIENTE:
			if (pLd->Corriente->Siguiente == NULL) {
				pNodo->Siguiente = pLd->Corriente->Siguiente;
				pNodo->Anterior  = pLd->Corriente;
				pLd->Corriente->Siguiente = pNodo;
			}
			else {
				pNodo->Anterior  = pLd->Corriente;
				pNodo->Siguiente = pLd->Corriente->Siguiente;
				pLd->Corriente->Siguiente->Anterior = pNodo;
				pLd->Corriente->Siguiente = pNodo;
			}
			break;
			//...Anterior al elemento Corriente
		case LS_ANTERIOR:
			pNodo->Siguiente = pLd->Corriente;
			pNodo->Anterior  = pLd->Corriente->Anterior;
			pLd->Corriente->Anterior->Siguiente = pNodo;
			pLd->Corriente->Anterior = pNodo;
			break;

		default:
			break;
		}
	}
//...Casteo de datos malloc devuelve void y Elem es int
	pNodo->Elem = (int *)malloc(pLd->TamanioDato); 
	memcpy(pNodo->Elem, pE, pLd->TamanioDato);
	pLd->Long++;
	pLd->Corriente = pNodo;
	return TRUE;
}

/* Ver_Lista
Pre:  Ls creada no vacia.
Post: Imprime contenido de la lista por pantalla
*/
void ld_Ver(TListaDoble *pLd)
{
	//...Defincion de Variables
	int  Elem;
	bool Flag = TRUE;
//	char Text;

	//...Inicio Funcion
	ld_MoverCorriente(pLd, LS_PRIMERO);
	while (Flag != FALSE) {
		ld_ElemCorriente(pLd,  &Elem);
		printf("Campo: %d\n" ,  Elem);
		ld_MoverCorriente(pLd, LS_SIGUIENTE);

		if (pLd->Corriente->Siguiente == NULL) {
			ld_ElemCorriente(pLd, &Elem);
			printf("Campo: %d\n", Elem);
			Flag = FALSE;
		}
	}
}

/* ld_CompSig
Pre:  Ld creada no vacia.
Post: Si siguiente es mayor devuelve TRUE
*/
bool ld_CompSig(TListaDoble* pLd) {
	if (pLd->Corriente->Siguiente == NULL)
		return FALSE;
	if (pLd->Corriente->Elem > pLd->Corriente->Siguiente->Elem)
		return TRUE;
	return FALSE;
}

/* ld_IntrCorr
Pre:  Ld creada no vacia.
Post: Cambia el corriente con el movimiento
*/
bool ld_IntrCorr(TListaDoble* pLd, TMovimiento_Ls M) {
	int *eAux;

	switch (M)
	{
	case LS_PRIMERO:
		eAux = pLd->Corriente->Elem;
		pLd->Corriente->Elem = pLd->Primero->Elem;
		pLd->Primero->Elem   = eAux;

	case LS_SIGUIENTE:
		if (pLd->Corriente->Siguiente == NULL)
			return FALSE;
		else 
		{
			eAux = pLd->Corriente->Elem;
			pLd->Corriente->Elem            = pLd->Corriente->Siguiente->Elem;
			pLd->Corriente->Siguiente->Elem = eAux;
		}
		break;
	case LS_ANTERIOR:
		if (pLd->Corriente == pLd->Primero)
			return FALSE;
		else
		{
			eAux = pLd->Corriente->Elem;
			pLd->Corriente->Elem = pLd->Corriente->Anterior->Elem;
			pLd->Corriente->Anterior->Elem = eAux;
		}
		break;
	default:
		return FALSE;
	}
	return TRUE;
}
