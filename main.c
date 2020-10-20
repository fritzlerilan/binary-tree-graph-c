#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbol.h"

Nodo crearArbolAleatorio(Nodo a, int cantNodos);
void imprimirCodigoColores();
int main(){
    srand(time(NULL));
    Nodo a = inicArbol();
    /* Test de un arbol AVL manual
    a = insertar(a, 65);
    a = insertar(a, 32);
    a = insertar(a, 11);
    a = insertar(a, 6);
    a = insertar(a, 2);
    a = insertar(a, 26);
    a = insertar(a, 13);
    a = insertar(a, 23);
    a = insertar(a, 30);
    a = insertar(a, 28);
    a = insertar(a, 31);
    a = insertar(a, 55);
    a = insertar(a, 41);
    a = insertar(a, 40);
    a = insertar(a, 47);
    a = insertar(a, 57);
    a = insertar(a, 59);
    a = insertar(a, 74);
    a = insertar(a, 69);
    a = insertar(a, 67);
    a = insertar(a, 66);
    a = insertar(a, 68);
    a = insertar(a, 70);
    a = insertar(a, 86);
    a = insertar(a, 83);
    a = insertar(a, 76);
    a = insertar(a, 94);
    a = insertar(a, 90);
    a = insertar(a, 98);
    */
   a = crearArbolAleatorio(a, 40);
    imprimirCodigoColores();
    graficarArbol(a);
    system("pause");
    return 0;
}

Nodo crearArbolAleatorio(Nodo a, int cantNodos){
    for(int i = 0; i < cantNodos; i++){
        int r = rand()%300 - 150;
        if(!buscar(a, r)){
            a = insertar(a, r);
            graficarArbol(a);
            system("pause");
            system("cls");
        }
    }
    return a;
}

void imprimirCodigoColores(){
    printf("CODIGO DE COLORES: \n");
    color(NEGRO, BLANCO_L);
    printf("%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219);
    COLOR_RESET
    printf("RAIZ  \n");
    color(NEGRO, AZUL_L);
    printf("%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219);
    COLOR_RESET
    printf("Nodos con 2 hijos. \n");
    color(NEGRO, MOSTAZA_L);
    printf("%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219);
    COLOR_RESET
    printf("Nodos con 1 hijos. \n");
    color(NEGRO, ROJO_L);
    printf("%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219);
    COLOR_RESET
    printf("Nodos con 0 hijos. \n");
}
