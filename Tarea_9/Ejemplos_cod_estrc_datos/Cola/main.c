#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cola[MAX];
int frente = 0, fin = 0, cantidad = 0;


void enqueue(int dato) {
if (cantidad == MAX) {
    printf("Cola llena\n");
    return;
}
cola[fin] = dato;
fin = (fin + 1) % MAX;
cantidad++;
}

int dequeue() {
if (cantidad == 0) {
    printf("Cola vacia\n");
    return -1;
}
int dato = cola[frente];
frente = (frente + 1) % MAX;
cantidad--;
return dato;
}

int main() {
enqueue(5);
enqueue(10);
enqueue(15);

printf("Dequeue: %d\n", dequeue());
printf("Dequeue: %d\n", dequeue());

    return 0;
}
