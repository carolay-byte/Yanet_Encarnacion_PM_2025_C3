#include <stdio.h>
#include <stdlib.h>

/* Funciones y parametros. */

int z, y;

int F1(float);
void F2(float, int *);

void main(void)
{
    int W;
    float X;
    z = 5;
    y = 7;
    W = 2;
    X = (float)y / z;
    printf("\nPrograma Principal: %d %d %.2f %d", z, y, X, W);
    F2 (X, &W);
    printf("\nPrograma Principal: %d %d %.2f %d", z, y, X, W);
}
int F1 (float x)
{
int k;
if (x!= 0)
{
    k = z - y;
    x++;
}
else
    k = z + y;
 printf("\nF1: %d %d %.2f %d", z, y, X, K);
 return(K);
}

void F2(float t, int *r)
{
    int y;
    y = 5;
    z = 0;

   printf("\nF2: %d %d %.2f %d", z, y, t, *r);
   if (z == 0)
   {
       z = (*r) * 2;
       t = (float) z / 3;
       printf("\nIngresa el valor: ");
       scanf("%d", r);                /* El usuario debe  ingresar el valor 6. */
       printf("\nF2: %d %d %.2f %d", z, y, t, *r);
   }
   else
   {
       z = (*r) * 2;
       printf("\nF2: %d %d %.2f %d", z, y, t, *r);
   }
   *r = F1(t);
}
