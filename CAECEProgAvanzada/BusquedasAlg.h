#pragma once

#include "ListaDoble.h"
#include "ListaSimple.h"

/* bus_SecuencialLS
Desc: Busqueda secuencial
Pre:  Ls creada.
Post: Devuelve TRUE si existe elemento en LS, FALSE en caso contrario
*/
bool bus_SecuencialLS(TListaSimple* pLs, int bus);

/* bus_SecuencialLD
Desc: Busqueda secuencial, del primero al ultimo
Pre:  Ld o Ldo creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_SecuencialLD(TListaDoble* pLd, int bus);

/* bus_ParcialLS
Desc: Busqueda Partida (Busca del corriente para adelante y para atras)
Pre:  Ls  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_ParcialLS(TListaSimple* pLs, int bus);

/* bus_ParcialLD
Desc: Busqueda Partida (Busca del corriente para adelante y para atras)
Pre:  Ld o Lo  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_ParcialLD(TListaDoble* pLd, int bus);


/* bus_BinariaLO
Desc: Busqueda Binaria, Dicotomica
Pre:  Lo  creada.
Post: Devuelve TRUE si existe elemento, FALSE en caso contrario
*/
bool bus_BinariaLO(TListaDoble* pLo, int bus);


/* bus_BinariaLS
Desc: Busqueda Binaria, Dicotomica (Previo Ordenamiento)
Pre:  Ls  creadas.
Post: Ordena la lista y devuelve TRUE si existe elemento, FALSE en caso contrario
*/
//bool bus_BinariaLS(TListaSimple* pLs, int bus);

/* ord_BurbujeoLS
Desc: Ordenamiento de Lista
Pre:  Ls  creadas.
Post: Ordena la lista
*/
void ord_BurbujeoLS(TListaSimple* pLs);

/* ord_BurbujeoLD
Desc: Ordenamiento de Lista
Pre:  Ld  creadas.
Post: Ordena la lista
*/
void ord_BurbujeoLD(TListaDoble* pLd);


