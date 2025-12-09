#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
int dato;
struct Nodo* sig;
} Nodo;

void insertarInicio(Nodo** cabeza, int valor){
Nodo* nuevo = malloc(sizeof(Nodo));
nuevo->dato = valor;
nuevo->sig = *cabeza;
*cabeza = nuevo;
}

void mostrar(Nodo* cabeza){
while (cabeza != NULL){
    printf("%d -> ", cabeza->dato);
    cabeza = cabeza->sig;
}
printf("NULL\n");
}

int main(){
Nodo* lista = NULL;

insertarInicio(&lista, 10);
insertarInicio(&lista, 20);
insertarInicio(&lista, 30);

mostrar(lista);
return 0;
}
