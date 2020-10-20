#ifndef ARBOL
#define ARBOL

#include "gotoxy.h"
#include "consoleColor.h"
#include <stdio.h>
#include <stdlib.h>

#define IZQ 0   
#define DER 1   
//  DEFINE LA SEPARACION DEL BORDE IZQ DE LA CONSOLA DE LA IMPRESION DEL ARBOL
#define MARGEN_IZQ 5
//  PARA RESULTADOS OPTIMOS SOLO INGRESAR VALOR 2 o 3
#define DIST_ENTRE_NODOS 2

typedef struct nodo{    
    int dato;
    struct nodo* izq;
    struct nodo* der;
}nodo;
typedef nodo* Nodo;

Nodo inicArbol();
Nodo crearNodo(int dato);
Nodo insertar(Nodo r, int dato);
Nodo buscar(Nodo r, int dato);
Nodo preOrden(Nodo r);
int altura(Nodo r);
int grado(Nodo r);
void graficarArbol(Nodo r);
#endif
