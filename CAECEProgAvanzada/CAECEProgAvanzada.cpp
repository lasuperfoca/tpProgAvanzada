// CAECEProgAvanzada.cpp: define el punto de entrada de la aplicación de consola.
//

//#include "stdafx.h"
# include <stdio.h>
#include  <ctype.h>
#include "stdlib.h"
#include "string.h"
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaDobleO.h"
#include "Consola.h"

int main()
{
	TListaSimple lS;
	TListaDoble  lD;
	TListaDoble  lDo;
	bool fin = FALSE;
	char salir[3];

//...Inicio
	Display_Header();
	Inicio_Programa(&lS, &lD, &lDo);
	printf("------------------------------------------------------------------------------\n");
	printf("Campos correspondientes a una Lista Simple:\n");
	printf("------------------------------------------------------------------------------\n\n");
	ls_Ver(&lS);
	printf("------------------------------------------------------------------------------\n");
	printf("Campos correspondientes a una Lista Doblemente enlasada:\n");
	printf("------------------------------------------------------------------------------\n\n");
	ld_Ver(&lD);
	printf("------------------------------------------------------------------------------\n");
	printf("Campos correspondientes a una Lista Ordenada:\n");
	printf("------------------------------------------------------------------------------\n\n");
	ld_Ver(&lDo);

/*	while (fin == FALSE) {
		scanf("%s", salir);
		if (salir == "FIN" || salir == "fin"){
			fin = TRUE;
		}
	}
*/
	return 0;
	}