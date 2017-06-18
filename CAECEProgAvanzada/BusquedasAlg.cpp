#include "Movimientos.h"
#include "ListaDoble.h"
#include "ListaSimple.h"
#include "stdafx.h"

/* bus_SecuencialLS
Desc: Busqueda secuencial
Pre:  Ls creada.
Post: Devuelve TRUE si existe elemento en LS, FALSE en caso contrario
*/
bool bus_SecuencialLS(TListaSimple* pLs, int bus) {
	bool salir		= FALSE;
	bool encontre	= FALSE;
	int  *cE; //Elemento Corriente;

//...Lista vacia no encuentra nada
	if (ls_Vacia(*pLs)) { return encontre; }
	ls_MoverCorriente(pLs, LS_PRIMERO);

//...Recorro secuencialmete la Lista
	while (salir == FALSE )
	{
		ls_ElemCorriente(pLs, cE);
//...Encuentro dato
		if (*cE == bus)
		{
			salir	 = TRUE;
			encontre = FALSE;
		}
		else 
		{
//...No encuentro y llegue al fin de la Lista - Sino muevo corriente y Sigo
			if(ls_MoverCorriente(pLs, LS_SIGUIENTE) != TRUE)
			{
				salir = TRUE;
			}
		}
	}
}

/* bus_SecuencialLD
Desc: Busqueda secuencial, del primero al ultimo
Pre:  Ld o Ldo creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_SecuencialLD(TListaDoble* pLd, int bus)
{
bool salir = FALSE;
bool encontre = FALSE;
int  *cE; //Elemento Corriente;

//...Lista vacia no encuentra nada
if (ld_Vacia(*pLd)) { return encontre; }
ld_MoverCorriente(pLd, LS_PRIMERO);

//...Recorro secuencialmete la Lista
 while (salir == FALSE)
 {
	ld_ElemCorriente(pLd, cE);
//...Encuentro dato
	if (*cE == bus)
	{
		salir    = TRUE;
		encontre = FALSE;
	}
	else
	{
//...No encuentro y llegue al fin de la Lista - Sino muevo corriente y Sigo
		if (ld_MoverCorriente(pLd, LS_SIGUIENTE) != TRUE)
		{
			salir = TRUE;
		}
	}
 }
}

/* bus_ParcialLS
Desc: Busqueda Partida (Busca del corriente para adelante y para atras)
Pre:  Ls  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_ParcialLS(TListaSimple* pLs, int bus)
{
	bool salir = FALSE;
	bool encontre = FALSE;
	int  *cE; //Elemento Corriente;
	
	if (ls_Vacia(*pLs)) { return encontre; }
	
	while (salir != FALSE) 
	{
		ls_ElemCorriente(pLs, cE);
//...Encuentro dato
		if (*cE == bus)
		{
			salir = TRUE;
			encontre = FALSE;
		}
		else
		{
//...No encuentro y llegue al fin de la Lista - Sino muevo corriente y Sigo
			if (ls_MoverCorriente(pLs, LS_SIGUIENTE) != TRUE)
			{
				salir = TRUE;
			}
		}
	}

//...Si no encontre busco en la otra mitad
	ls_MoverCorriente(pLs, LS_PRIMERO);
	while (salir != FALSE && encontre == FALSE)
	{
		ls_ElemCorriente(pLs, cE);
//...Encuentro dato
		if (*cE == bus)
		{
			salir = TRUE;
			encontre = FALSE;
		}
		else
		{
//...No encuentro y llegue al fin de la Lista - Sino muevo corriente y Sigo
			if (ls_MoverCorriente(pLs, LS_SIGUIENTE) != TRUE)
			{
				salir = TRUE;
			}
		}
	}
	return encontre;
}



/* bus_ParcialLD
Desc: Busqueda Partida (Busca del corriente para adelante y para atras)
Pre:  Ld o Lo  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_ParcialLO(TListaDoble* pLd, int bus) 
{
	bool salir    = FALSE;
	bool encontre = FALSE;
	int  *cE; //Elemento Corriente;
	TNodoDoble *pNAux;

	if (ld_Vacia(*pLd)) { return encontre; }

//...Guardo el corriente para buscar la otra mitad
	pNAux = pLd->Corriente;
	while (salir != FALSE)
	{
		ld_ElemCorriente(pLd, cE);
//...Encuentro dato
		if (*cE == bus)
		{
			salir = TRUE;
			encontre = FALSE;
		}
		else
		{
//...No encuentro y llegue al fin de la Lista - Sino muevo corriente y Sigo
			if (ld_MoverCorriente(pLd, LS_SIGUIENTE) != TRUE)
			{
				salir = TRUE;
			}
		}
	}

//...Si no encontre busco en la otra mitad
	pLd->Corriente = pNAux;
	while (salir != FALSE && encontre == FALSE)
	{
		ld_ElemCorriente(pLd, cE); //Pierdo una vuelta pero es Infimo
//...Encuentro dato
		if (*cE == bus)
		{
			salir    = TRUE;
			encontre = FALSE;
		}
		else
		{
//...No encuentro y llegue al fin de la Lista - Sino muevo corriente y Sigo
			if (ld_MoverCorriente(pLd, LS_ANTERIOR) != TRUE)
			{
				salir = TRUE;
			}
		}
	}
	return encontre;
}


/* bus_BinariaLO
Desc: Busqueda Binaria, Dicotomica
Pre:  Lo  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_BinariaLO(TListaDoble* pLo, int bus) {
	bool salir    = FALSE;
	bool encontre = FALSE;
	int  *cE; //elemento corriente
	int  indSup	  = pLo->Long - 1;
	int  indInf   = 0;
	int  indCen;
	int  cont;

	ld_MoverCorriente(pLo, LS_PRIMERO);

	indCen = (indSup + indInf) / 2;
	for (cont = indInf; cont < indCen; cont++) {
		ld_MoverCorriente(pLo, LS_SIGUIENTE);
	}

	while (indInf <= indSup && salir == FALSE)
	{
//...Comparo
		ld_ElemCorriente(pLo, cE);
		if (*cE == bus) {
			encontre = TRUE;
			salir    = TRUE;
		}
		else
//...Voy para Atras			
			if (bus < *cE){
				indSup = indCen - 1;
				indCen = (indSup + indInf) / 2;
				for (cont = indInf; cont <= indCen; cont++) {
					ld_MoverCorriente(pLo, LS_ANTERIOR);
				}
			}
			else 
			{
				indInf = indCen + 1;
				indCen = (indSup + indInf) / 2;
				for (cont = indInf; cont <= indCen; cont++) {
					ld_MoverCorriente(pLo, LS_SIGUIENTE);
				}
			}
	}
	return encontre;
}


/* ord_BurbujeoLS
Desc: Ordenamiento de Lista
Pre:  Ls  creadas.
Post: Ordena la lista
*/
void ord_BurbujeoLS(TListaSimple* pLs) {

}

/* ord_BurbujeoLD
Desc: Ordenamiento de Lista
Pre:  Ld  creadas.
Post: Ordena la lista
*/
void ord_BurbujeoLD(TListaDoble* pLd)
{
	int *cAux;
	int cont;
	int iAux;
	int iPaso  = 1;
	bool salir = FALSE ;
	do
		{
		salir = TRUE;
			for (cont = 0; cont <= pLd->Long - iPaso; cont++)
			{				
				if (ld_CompSig(pLd))
				{
					ld_IntrCorr(pLd, LS_SIGUIENTE);
					salir = FALSE;
				}
			}
			iPaso++;
		} while (!salir);
}

/* bus_BinariaLD
Desc: Busqueda Binaria, Dicotomica
Pre:  Lo  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_BinariaLD(TListaDoble* pLd, int bus) {
	bool salir = FALSE;
	bool encontre = FALSE;
	int  *cE; //elemento corriente
	int  indSup = pLd->Long - 1;
	int  indInf = 0;
	int  indCen;
	int  cont;

	ord_BurbujeoLD(pLd);
	ld_MoverCorriente(pLd, LS_PRIMERO);

	indCen = (indSup + indInf) / 2;
	for (cont = indInf; cont < indCen; cont++) {
		ld_MoverCorriente(pLd, LS_SIGUIENTE);
	}

	while (indInf <= indSup && salir == FALSE)
	{
		//...Comparo
		ld_ElemCorriente(pLd, cE);
		if (*cE == bus) {
			encontre = TRUE;
			salir = TRUE;
		}
		else
			//...Voy para Atras			
			if (bus < *cE) {
				indSup = indCen - 1;
				indCen = (indSup + indInf) / 2;
				for (cont = indInf; cont <= indCen; cont++) {
					ld_MoverCorriente(pLd, LS_ANTERIOR);
				}
			}
			else
			{
				indInf = indCen + 1;
				indCen = (indSup + indInf) / 2;
				for (cont = indInf; cont <= indCen; cont++) {
					ld_MoverCorriente(pLd, LS_SIGUIENTE);
				}
			}
	}
	return encontre;
}
