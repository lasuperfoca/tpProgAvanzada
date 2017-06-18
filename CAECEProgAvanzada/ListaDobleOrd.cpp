
#include "ListaDobleOrd.h"
/*#include "stdafx.h"

void ls_InsertarOrd( TListaDoble *pLs, int* pE)
{
	int* cE; //Elemento corriente
	int* sE; //Elemento Siguiente al corriente

	if( ls_Vacia(*pLs)) {
		ls_Insertar(pLs, LS_PRIMERO, pE);
	}
	else {
		ls_ElemCorriente(*pLs, cE);
//...Si es el ultimo Inserto en siguiente sin comparar 		
		if (cE <= pE) 
		{
				ls_Insertar(pLs, LS_SIGUIENTE, pE);
		}
		else 
		{
			if(cE > pE)
			{
//...Es menor que el Primer elemento (El menor de todos)
				if (pLs->Corriente == pLs->Primero) 
				{
					ls_Insertar(pLs, LS_ANTERIOR, pE);
				}
				else 
				{
					ls_MoverCorriente(pLs, LS_ANTERIOR);
				}
			}
		}
	}
} */