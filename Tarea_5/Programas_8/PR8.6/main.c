#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Comercializadora farmaceutica.
El programa maneja informacion sobre ventas, inventario, reabastecimiento y
nuevos productos de una comercializadora farmaceutica. */

typedef struct             /* Declaracion de la estructura producto. */
{
    int clave;
    char nombre[15];
    float precio;
    int existencia;
} producto;

void Lectura(producto *, int);
void Ventas(producto *, int);
void Reabastecimiento(producto *, int);
void Nuevos_Productos(producto *, int *);
void Inventario(producto *, int);
void main(void)
{
    producto INV[100];
    /* Se declara un arreglo unidimensional de tipo estructura producto. */
    int TAM, OPE;
    do
    {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    /* Se verifica que el numero de productos ingresados sea correcto. */
    Lectura(INV, TAM);
    printf("\nIngrese operacion a realizar. \n\t\t1 - Ventas \n\t\t 2 -Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 - Inventario \n\t\t 0 - Salir: ");
           scanf("%d", &OPE);
           while (OPE)
           {
               switch (OPE)
               {
                   case 1: Ventas(INV, TAM);
                   break;
                   case 2: Reabastecimiento(INV, TAM);
                   break;
                   case 3: Nuevos_Productos(INV, &TAM);
                   /* Se pasa el parametro por referencia, porque se puede modificar el
                   numero
                   de elementos del arreglo en la funcion. */
                   break;
                   case 4: Inventario(INV, TAM);
                   break;
               };
               printf("\nIngrese operacion a realizar. \n\t\t - Ventas \n\t\t 2 Reabastecimiento \n\t\t 3 - Nuevos Productos \n\t\t 4 - Inventario \n\t\t 0 - Salir: ");
                      scanf("%d", &OPE);
           }
}

void Lectura(producto A[], int T)
/* Esta funcion se utliza para leer un arreglo unidimensional de tipo
estructura producto de T elementos. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese informacion del producto %d", I+1);
        printf("\n\tClave: ");
        scanf("%d", &A[I].clave);
        fflush(stdin);
        printf("\tNombre:");
        gets(A[I].nombre);
        printf("\tPrecio:");
        scanf("%f", &A[I].precio);
        printf("\tExistencia: ");
        scanf("%d", &A[I].existencia);
    }
}

void Ventas(producto A[], int T)
/* Esta funcion se utiliza para manejar la venta a un cliente. Se ingresan
productos y cantidades, el fin de datos esta dado por el cero. Ademas de
obtener el total de las ventas, se actualiza el inventario. */
{
    int CLA, CAN, I, RES;
    float TOT, PAR;
    printf("\nIngrese clave del producto -0 para salir-: ");
    scanf("%d", &CLA);
    TOT = 0.0;
    while (CLA)
    {
        printf("\tCantidad: ");
        scanf("%d", &CAN);
        I = 0;
        while ((I < T) && (A[I].clave > CLA))
            /* Se realiza una busqueda para localizar la clave del producto. */
            I++;
        if ((I == T) || (A[I].clave > CLA))
            printf("\nLa clave del producto es incorrecta");
        else
            if (A[I].existencia >= CAN)
            /* Se analiza si el stock es suficiente para satisfacer el pedido. */
        {
            A[I].existencia -= CAN;    /* Se actualiza el stock del producto. */
            PAR = A[I].precio * CAN;
            TOT += PAR;
        }
        else
        {
          printf("\nNo existe en inventario la cantidad soliictada. Solo hay %d", A[I].existencia);
          printf(" \nLos lleva 1 - Si  0 - No?: ");
          scanf("%d", &RES);
          if (RES)
          {
              PAR = A[I].precio * A[I].existencia;
              A[I].existencia = 0;
              TOT += PAR;
          }
        }
        printf("\nIngrese la siguiente clave del producto -0 para salir-:");
        scanf("%d", &CLA);
        }
        printf("\nTotal de la venta: %f", TOT);
    }



}
