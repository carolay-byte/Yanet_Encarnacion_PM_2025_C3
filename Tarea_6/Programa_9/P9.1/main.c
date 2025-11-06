#include <stdio.h>

/* Archivos y caracteres.
El programa lee caracteres de un archivo. */

void main(void)
{
    char pl;
    FILE *ar;

    if ((ar = fopen("arc.txt", "r")) != NULL)
    {
        while
        {

            pl = fgetc(ar); /* Lee el caracter del archivo. */

            putchar(p1); /* Despliega el caracter en la pantalla. */

    }
    fclose(ar);

}

