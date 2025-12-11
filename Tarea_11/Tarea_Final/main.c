#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Libro
{
    int ano;
    char autor[50];
    char titulo[50];
    char descripcion[100];
    float precio;
    int codigo;

    struct Libro *next;
} Libro;


/* ============================
          FUNCIONES
===============================*/

Libro* crearLibro()
{
    Libro *nuevo = (Libro*)malloc(sizeof(Libro));

    printf("Ano: ");
    scanf("%d", &nuevo->ano);

    printf("Autor: ");
    getchar();
    fgets(nuevo->autor, 50, stdin);
    nuevo->autor[strcspn(nuevo->autor, "\n")] = '\0';

    printf("Titulo: ");
    fgets(nuevo->titulo, 50, stdin);
    nuevo->titulo[strcspn(nuevo->titulo, "\n")] = '\0';

    printf("Descripcion: ");
    fgets(nuevo->descripcion, 100, stdin);
    nuevo->descripcion[strcspn(nuevo->descripcion, "\n")] = '\0';

    printf("Precio: ");
    scanf("%f", &nuevo->precio);

    printf("codigo: ");
    scanf("%f", &nuevo->codigo);

    nuevo->next = NULL;
    return nuevo;
}

void agregarLibro(Libro **lista)
{
    Libro *nuevo = crearLibro();

    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        Libro *temp = *lista;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = nuevo;
    }
}

/* ==========================
      IMPRIMIR LISTA
============================*/

void imprimirLibros(Libro *lista)
{
    if (lista == NULL)
    {
        printf("\nLa lista esta vacia.\n");
        return;
    }

    Libro *temp = lista;
    printf("\n========= LISTA DE LIBROS =========\n");
    while (temp != NULL)
    {
        printf("Ano: %d\n", temp->ano);
        printf("Autor: %s\n", temp->autor);
        printf("Titulo: %s\n", temp->titulo);
        printf("Descripcion: %s\n", temp->descripcion);
        printf("Precio: %.2f\n", temp->precio);
        printf("Codigo: %d\n", temp->codigo);
        printf("-----------------------------------\n");
        temp = temp->next;

    }
}
/* ==========================
      BUSCAR POR AUTOR
============================*/

void buscarPorAutor(Libro *lista, char autorBuscado[])
{
    Libro *temp = lista;
    int encontrado = 0;

    printf("\nResultados para autor '%s':\n", autorBuscado);
    printf("-----------------------------------\n");

    while (temp != NULL)
    {
        if (strcmp(temp->autor, autorBuscado) == 0)
        {
            printf("Titulo: %s | Precio: %.2f | Ano: %d | Codigo: %d\n",
                   temp->titulo, temp->precio, temp->ano, temp->codigo);
            encontrado = 1;
        }
        temp = temp->next;
    }
    if (!encontrado)
        printf("No se encontraron libros de ese autor.\n");
}


/* ====================================
      ORDENAR POR PRECIO (BUBBLE SORT)
=======================================*/

void bubbleSort(Libro *lista)
{
    if (lista == NULL) return;

    int cambiado;
    Libro *ptr;
    Libro *ultimo = NULL;

    do
    {
        cambiado = 0;
        ptr = lista;

        while (ptr->next != ultimo)
        {
            if (ptr->precio > ptr->next->precio)
            {
                // intercambiar valores
                float tempPrecio = ptr->precio;
                ptr->precio = ptr->next->precio;
                ptr->next->precio = tempPrecio;

                int tempAno = ptr->ano;
                ptr->ano = ptr->next->ano;
                ptr->next->ano = tempAno;

                int tempCod = ptr->codigo;
                ptr->codigo = ptr->next->codigo;
                ptr->next->codigo = tempCod;

                char tempAutor[50], tempTitulo[50], tempDesc[100];

                strcpy(tempAutor, ptr->autor);
                strcpy(ptr->autor, ptr->next->autor);
                strcpy(ptr->next->autor, tempAutor);

                strcpy(tempTitulo, ptr->titulo);
                strcpy(ptr->titulo, ptr->next->titulo);
                strcpy(ptr->next->titulo, tempTitulo);

                strcpy(tempDesc, ptr->descripcion);
                strcpy(ptr->descripcion, ptr->next->descripcion);
                strcpy(ptr->next->descripcion, tempDesc);


                cambiado = 1;
            }
            ptr = ptr->next;
        }
        ultimo = ptr;
    }
    while (cambiado);
}

/* =======================
           MAIN
==========================*/

int main()
{
    Libro *lista = NULL;
    int opcion;
    char autor[50];

    do
    {
        printf("\n============ MENU ============\n");
        printf("1. Agregar libro\n");
        printf("2. Buscar por autor\n");
        printf("3. Ordenar por precio (Bubble Sort)\n");
        printf("4. Imprimir lista\n");
        printf("5. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarLibro(&lista);
            break;

        case 2:
            printf("Ingrese el autor a buscar:");
            getchar();
            fgets(autor, 50, stdin);
            autor[strcspn(autor, "\n")] = '\0';
            buscarPorAutor(lista, autor);
            break;

        case 3:
            bubbleSort(lista);
            printf("\nLa lista ha sido ordenada por precio.\n");
            break;

        case 4:
            imprimirLibros(lista);
            break;

        case 5:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida.\n");

        }
    }
    while (opcion != 5);

    return 0;
}
