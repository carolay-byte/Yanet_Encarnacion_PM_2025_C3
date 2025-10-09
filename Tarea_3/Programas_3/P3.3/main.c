#include <stdio.h>
#include <stdlib.h>

/* Suma pagos.
El programa, al reciir como datos un conjunto de pagos realizados
en el ultimo mes, obtiene la suma de los mismos.

PAG y SPA: variables de tipo real. */

void main(void)
{
    float PAG, SPA;
    SPA = 0;
    printf("Ingrese el primer pago:\t");
    scanf("%f", &PAG);
    while (PAG)
        /* Observa que la proposicion que modifica la condicion es una lectrua. */
    {
        printf("\nEl total de pagos del mes es: %.2f", SPA);
    }
}
