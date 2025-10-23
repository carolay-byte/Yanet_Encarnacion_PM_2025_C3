#include <stdio.h>
#include <stdlib.h>

/* Declaracion de cadenas de caracteres y asignacion de valores. */

void main(void)
{
    char *cad0;
    cad0 = "Argentina";             /* La declaracion y la asignacion son correctas. */
    puts(cad0);

    cad0 = "Brasil";
    puts(cad0);

    char *cad1;
    gets(*cad1);   gets(cad1);
    /*Incorrecto*/

    char *cad1 = "";
    gets(cad1);
    /*Correcto*/

    char cad1[];
    /*Incorrecto*/

    char cad2[20] = "Mexico";   /*Correcto*/
    puts(cad2);
    gets(cad2);

    puts(cad2);
    cad2[10] = "Guatemala";
}
