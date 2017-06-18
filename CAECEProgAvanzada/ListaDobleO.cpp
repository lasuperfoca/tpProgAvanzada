
#include "ListaDobleO.h"
#include "stdafx.h"

/* Ver_Lista
Pre:  ld creada no vacia.
Post: Imprime contenido de la lista por pantalla
*/
void ld_InsertarOrd(TListaDoble *pld, int* pE)
{
	int cE; //Elemento corriente

//...Lista Vacia se carga LS_PRIMERO
	if (ld_Vacia(*pld)) {
		ld_Insertar(pld, LS_PRIMERO, pE);
	}

//...Lista No Vacia
	else {
		ld_ElemCorriente(pld, &cE);

//...Corriente menor al Nuevo Valor 		
		if (cE <= *pE)
		{
			if (ld_MoverCorriente(pld, LS_SIGUIENTE) == TRUE) {
				ld_ElemCorriente(pld, &cE);
//...Corrien->Siguiente es menor sigo Recorriendo
				if (cE <= *pE) {
					ld_InsertarOrd(pld, pE);
				}

//...Corrien->Siguiente es Mayor (Movi corriente por lo que inserto Antes)
				else 
				{
					ld_Insertar(pld, LS_ANTERIOR, pE);
				}
			}
			else {
				ld_Insertar(pld, LS_SIGUIENTE, pE);
			}

	}
		else
		{
//...Corriente Mayor al Nuevo Valor 		
			if (pld->Corriente == pld->Primero)
			{
				ld_Insertar(pld, LS_ANTERIOR, pE);
			}
			else
			{
				ld_MoverCorriente(pld, LS_ANTERIOR);
				ld_InsertarOrd(pld, pE);
			}
		}
	}
}