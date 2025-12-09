#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int destino;
    struct Nodo* sig;
} Nodo;

typedef struct
{
    Nodo* lista[5];
} Grafo;

void agregarArista(Grafo* g, int u, int v)
{
    Nodo* n1 = malloc(sizeof(Nodo));
    n1->destino = v;
    n1->sig = g->lista[u];
    g->lista[u] = n1;

    Nodo* n2 = malloc(sizeof(Nodo));
    n2->destino = u;
    n2->sig = g->lista[v];
    g->lista[v] = n2;
}

void mostrar(Grafo g){
for (int i = 0; i < 5; i++){
    printf("Nodo %d: ", i);
    Nodo* temp = g.lista[i];
    while (temp){
        printf("%d -> ", temp->destino);
        temp = temp->sig;
    }
    printf("NULL\n");
}
}

int main(){
Grafo g = {0};

agregarArista(&g, 0, 1);
agregarArista(&g, 0, 4);
agregarArista(&g, 1, 2);

mostrar(g);
return 0;
}
