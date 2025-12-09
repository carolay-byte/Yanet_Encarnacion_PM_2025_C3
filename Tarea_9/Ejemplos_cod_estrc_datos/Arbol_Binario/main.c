#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
int dato;
struct Nodo* izq;
struct Nodo* der;
} Nodo;

Nodo* nuevoNodo(int valor) {
Nodo* n = malloc(sizeof(Nodo));\
n->dato = valor;
n->izq = n->der = NULL;
return n;
}

Nodo* insertar(Nodo* raiz, int valor){
if (raiz == NULL) return nuevoNodo(valor);

if (valor < raiz->dato)
    raiz->izq = insertar(raiz->izq, valor);
else
    raiz->der = insertar(raiz->der, valor);

    return raiz;
}

void inorden(Nodo* raiz) {
if(raiz != NULL) {
    inorden(raiz->izq);
    printf("%d", raiz->dato);
    inorden(raiz->der);
}
}

int main(){
Nodo* raiz = NULL;
raiz = insertar(raiz, 50);
insertar(raiz, 30);
insertar(raiz, 70);
insertar(raiz, 20);

inorden(raiz);
return 0;
}
