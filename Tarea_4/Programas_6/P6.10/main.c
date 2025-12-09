#include <stdio.h>
#include <stdlib.h>

/* Cuadrado magico.
El programa genera un cuadrado magico siguiendo los criterios enunciados
anteriormente. */

const int MAX = 50;

void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int);        /* Prototipos de funciones. */

void main(void)
{
    int CMA[MAX][MAX],TAM;
    do
    {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d", &TAM);
    }
    while ((TAM > MAX || TAM < 1) && (TAM % 2));
    /* Se verifica el tamaño del arreglo y el orden del mismo. */
    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);
}

void Cuadrado(int A[][MAX],int N)
/* Esta funcion se utiliza para escribir el cuadrado magico. */
{
    int I, J;
    for (J=0; J<N; J++)
        printf("\nElemento %d %d: %d",I+1, J+1, A[I][J]);
}
