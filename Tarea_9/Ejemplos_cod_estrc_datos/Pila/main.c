#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int pila[MAX];
int tope = -1;

void push(int dato) {
if (tope == MAX - 1){
    printf("Pila llena\n");
    return;
}
pila[++tope] = dato;
}

int pope()
if (tope == - 1){
    printf("Pila vacia\n");
    return -1;
}
return pila[tope--];
}

int main(){
push(10);
push(20);
push(30);

printf("Pop: %d\n", pop());
printf("Pop: %d\n", pop());

return 0;
}
