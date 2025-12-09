#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int tabla[TAM];

int hash(int clave) {
 return clave % TAM;
}

void insertar(int clave) {
 int idx = hash(clave);
 while (tabla[idx] != 0) {
    idx = (idx + 1) % TAM;
 }
 tabla[idx] = clave;
}

int buscar(int clave) {
int idx = hash(clave);
int start = idx;

while (tabla[idx] != clave) {
    idx = (idx + 1) % TAM;
    if (idx == start) return -1;
}
return idx;
}

int main() {
    insertar(15);
    insertar(25);
    insertar(35);


    printf("25 encontrado en índice: %d\n", buscar(25));
    return 0;
}
