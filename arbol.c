#include "arbol.h"
Nodo inicArbol(){
    return NULL;
}
Nodo crearNodo(int dato){
    Nodo n = (Nodo)malloc(sizeof(nodo));
    n->dato = dato;
    n->izq = NULL;
    n->der = NULL;
    return n;
}
int altura(Nodo r){
    if(!r){
        return 0;
    }else{
        int izq, der;
        izq = altura(r->izq);
        der = altura(r->der);
        return (izq > der) ? 1 + izq : 1 + der;
    }
}
int grado(Nodo r){
    int g = 0;
    if(r->izq && r->der){
        g = 2;
    }else{
        if(r->izq || r->der){
            g = 1;
        }
    }
    return g;
}
Nodo insertar(Nodo r, int dato){
    if(!r){
        return crearNodo(dato);
    }else{
        if(dato > r->dato){
            r->der = insertar(r->der, dato);
        }else{
            r->izq = insertar(r->izq, dato);
        }
    }
    return r;
}
Nodo buscar(Nodo r, int dato){
    if(r){
        if(dato == r->dato){
            return r;
        }else{
            if(dato > r->dato){
                return buscar(r->der, dato);
            }else{
                return buscar(r->izq, dato);
            }
        }
    }
    return r;
}
Nodo preOrden(Nodo r){
    if(r){
        printf("[%d]", r->dato);
        preOrden(r->izq);
        preOrden(r->der);
    }
}

int menoresQue(Nodo r, int d){
    if(r){
        int izq = menoresQue(r->izq, d);
        int der = menoresQue(r->der, d);
        if(r->dato < d){
            return 1 + izq + der;
        }else{
            return izq + der;
        }
    }else{
        return 0;
    }
}
void colorearNodo(Nodo r){
    int g = grado(r);
    color(NEGRO, ROJO_L);
    if(g == 2){
        color(NEGRO, AZUL_L);
    }else{
        if(g == 1){
            color(NEGRO, MOSTAZA_L);
        }
    }
}
void graficar(Nodo r, Nodo padre, int dir, int posX, int posY){
    if(r){
        
        int posX2 = menoresQue(padre, r->dato) * DIST_ENTRE_NODOS + MARGEN_IZQ;
        graficar(r->izq, padre, IZQ, posX2, posY + 2);
        gotoxy(posX2, posY);
        
        if(dir != -1){
            colorearNodo(r);
        }
        
        printf("%d ", r->dato);

        if(dir == IZQ){
            gotoxy(posX2, posY-1);
            printf("_/");
            for(int i = posX2 + 2; i < posX; i++){
                gotoxy(i, posY-1);
                printf("%c", 238);
            }
        }else if(dir == DER){
                gotoxy(posX +2, posY-1);
            for(int i = posX +2; i < posX2; i++){
                gotoxy(i, posY-1);
                printf("%c", 238);
            }
            printf("%c_", 92);
        }
        COLOR_RESET
        graficar(r->der, padre,  DER, posX2, posY + 2);
    }
}
void graficarArbol(Nodo r){
    int posY = whereY();
    int posX;
    graficar(r, r, -1, posX, posY);
    gotoxy(0, posY + altura(r)*2);      /// Me posiciono al final del arbol
}

