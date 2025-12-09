#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// --------------------
// ESTRUCTURA DEL LIBRO
// --------------------
typedef struct Libro {
int anio;
char autor[MAX];
char titulo[MAX];
char descripcion[MAX];
float precio;
int codigo;
struct Libro *next;
} Libro;

// --------------
// PROTOTIPOS
// --------------
Libro* cargarLibrosDesdeArchivo(const char *filename);
void guardarLibrosEnArchivo(const char *filename, Libro *head);
Libro* agregarLibro(Libro *head);
void mostrarLibros(Libro *head);
void buscarPorTitulo(Libro *head, const char *titulo);
void buscarPorAutor(Libro *head, const char *autor);

// --------------------
// FUNCION PRINCIPAL
// --------------------
int main() {
    Libro *lista = NULL;
    int opcion;
    char busqueda[MAX];

    lista = cargarLibrosDesdeArchivo("libros.txt");


    do {
        printf("\n===== MENU ======\n");
        printf("1. Mostrar libros\n");
        printf("2. Agregar libro\n");
        printf("3. Buscar por titulo\n");
        printf("4. Buscar por autor\n");
        printf("5. Guardar y salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch(opcion) {
    case 1:
        mostrarLibros(lista);
        break;
    case 2:
        lista = agregarLibro(lista);
        break;
    case 3:
        printf("Ingrese titulo a buscar: ");
        fgets(busqueda, MAX, stdin);
        busqueda[strcspn(busqueda, "\n")] = 0;
        buscarPorTitulo(lista, busqueda);
        break;
    case 4:
        printf("Ingrese autor a buscar: ");
        fgets(busqueda, MAX, stdin);
        busqueda[strcspn(busqueda, "\n")] = 0;
        buscarPorAutor(lista, busqueda);
        break;
    case 5:
         guardarLibrosEnArchivo("libros.txt", lista);
                printf("Datos guardados. Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 5);


    return 0;
}

// ----------------------------------------
// Cargar la lista desde un archivo de texto
// ----------------------------------------
Libro* cargarLibrosDesdeArchivo(const char *filename) {
FILE *file = fopen(filename, "r");
if (!file) {
    printf("No existe el archivo, iniciando lista vacia...\n");
    return NULL;
}

Libro *head = NULL, *temp = NULL;

while (!feof(file)) {
    Libro *nuevo = (Libro*) malloc(sizeof(Libro));
     if (fscanf(file, "%d|%99[^|]|%99[^|]|%99[^|]|%f|%d\n",
                   &nuevo->anio, nuevo->autor, nuevo->titulo,
                   nuevo->descripcion, &nuevo->precio, &nuevo->codigo) != 6) {
               free(nuevo);
               break;
}

nuevo->next = NULL;

if (!head) head = nuevo;
else temp->next = nuevo;

temp = nuevo;
}

fclose(file);
return head;
}

// -----------------------------
// Guardar libros en archivo
// -----------------------------
void guardarLibrosEnArchivo(const char *filename, Libro *head) {
FILE *file = fopen(filename, "w");
if (!file){
    printf("Error al abrir archivo para guardar.\n");
    return;
}

Libro *temp = head;
while (temp) {
    fprintf(file, "%d|%s|%s|%s|%.2f|%d\n",
            temp->anio, temp->autor, temp->titulo, temp->descripcion,
            temp->precio, temp->codigo);
    temp = temp->next;
}

fclose(file);
}

// ---------------------
// Agregar un libro
// ---------------------
Libro* agregarLibro(Libro *head) {
Libro *nuevo = (Libro*) malloc(sizeof(Libro));

printf("Anio: ");
scanf("%d", &nuevo->anio);
getchar();

printf("Autor: ");
fgets(nuevo->autor, MAX, stdin);
nuevo->autor[strcspn(nuevo->autor, "\n")] = 0;

printf("Titulo: ");
fgets(nuevo->titulo, MAX, stdin);
nuevo->autor[strcspn(nuevo->autor, "\n")] =0;

printf("Descripcion: ");
fgets(nuevo->titulo, MAX, stdin);
nuevo->autor[strcspn(nuevo->autor, "\n")] =0;

printf("Precio: ");
scanf("%f", &nuevo->precio);

printf("Precio: ");
scanf("%d", &nuevo->codigo);

nuevo->next = NULL;

if (!head) return nuevo;

Libro *temp = head;
while (temp->next) temp = temp->next;

temp->next = nuevo;
return head;
}

// -----------------------
// Mostrar libros
// -----------------------
void mostrarLibros(Libro *head) {
if (!head){
    printf("No hay libros.\n");
    return;
}

Libro *temp = head;
printf("\n---- LISTA DE LIBROS ----\n");
while (temp) {
    printf("Titulo: %s\nAutor: %s\nAnio: %d\nDescripcion: %s\nPrecio: %.2f\nCodigo: %d\n\n", temp->titulo, temp->autor, temp->anio, temp->descripcion, temp->precio, temp->codigo);
    temp = temp->next;
}
}

// ------------------------
// Buscar por titulo
// ------------------------
void buscarPorTitulo(Libro *head, const char *titulo) {
Libro *temp = head;
int encontrado = 0;

while (temp) {
    if (strcasecmp(temp->titulo, titulo)== 0) {
        printf("\nLibro encontrado:\nTitulo: %s\nAutor: %s\nAnio: %d\nDescripcion: %s\nPrecio: %.2f\nCodigo: %d\n",
               temp->titulo, temp->autor, temp->anio, temp->descripcion,
               temp->precio, temp->codigo);
               encontrado = 1;
    }
    temp = temp->next;
}

if (!encontrado)
    printf("lNo se encontro un libro con ese titulo.\n");
}

// ------------------------------------
// Buscar por autor
// ------------------------------------
void buscarPorAutor(Libro *head, const char *autor) {
Libro *temp = head;
int encontrado = 0;

while (temp) {
    if (strcasecmp(temp->autor, autor) == 0) {
        Libro *temp = head;
        int encontrado = 0;

        while (temp) {
            if (strcasecmp(temp->autor, autor) == 0)  printf("\nLibro encontrado:\nTitulo: %s\nAutor: %s\nAnio: %d\nDescripcion: %s\nPrecio: %.2f\nCodigo: %d\n",
               temp->titulo, temp->autor, temp->anio, temp->descripcion,
               temp->precio, temp->codigo);
               encontrado = 1;
    }
    temp = temp->next;
        }

        if (!encontrado)
            printf("No se encontro un libro con ese autor.\n");
}
}
