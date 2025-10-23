#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Temperaturas.
El programa recibe como datos 24 numeros reales que representan las
temperaturas en el exterios en un periodo de 24 horas. Calcula el
promedio del dia y las temperaturas maxima y minima con la hora en la
que se registraron. */

void Acutem(float);
void Maxima(float, int);              /* Prototipos de funciones. */
void Minima (float, int);

float ACT = 0.0;
float MAX = -50.0;                    /* Variables globales. */
float MIN = 60.0;
int HMAX;
int HMIN;

void main(void)
{
    float TEM;
    int I;
    for (I = 1; I <= 24; I++)
    {
        printf("Ïngresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);
        Acutem(TEM);
        Maxima(TEM, I);        /* Llamada a las funciones. Paso de parametros
                               por valor. */
    Minima(TEM, I);
}
printf("\nPromedio del dia: %5.2f", (ACT / 24));
printf("\nMaxima del dia: %5.2f, \tHora: %d", MAX, HMAX);
printf("\nMinima del dia: %5.2f, \tHora: %d", MIN, HMIN);
}

void Acutem(float T)
/* Esta funcion acumula las temperaturas en la variable global ACT
para posteriormente calcular el promedio. */
{
    ACT += T;
}
void Maxima(float T, int H)
{
    if (MAX < T)
    {
        MAX = T;
        HMAX = H;
    }
}
void Minima(float T, int H)
{
    if (MIN > T)
    {
        MIN = T;
        HMIN = H;
    }
}
