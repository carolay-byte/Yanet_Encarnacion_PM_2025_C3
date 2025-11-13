#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para presentar un producto

typedef struct {
   char nombre[50];
   int cantidad;
   float precio;
} Producto;

// Prototipos de funciones
Producto* cargarInventario(const char *nombreArchivo, int *numProductos);
void guardarInventario(const char *nombreArchivo, Producto *inventario, int numProductos);
void agregarProducto(Producto **inventario, int *numProductos);
void imprimirInventario(Producto *inventario, int numProductos);

int main(){
    Producto *inventario = NULL;
    int numProductos = 0;
    int opcion;

    inventario = cargarInventario("ïnventario.txt", &numProductos);

    printf("\nInventario cargado correctamente. Productos: %d\n", numProductos);

    printf("\n¿Desea agregar un nuevo producto? (1 = Si, 0 = No): ");
    scanf("%d", &opcion);

    if (opcion == 1){
        agregarProducto(&inventario, &numProductos);
        guardarInventario("inventario.txt", inventario, numProductos);
        printf("\nProducto agregado y guardado con éxito.\n");
    }

  printf("\n¿Desea imprimir el inventario? (1 = Si, 0 = No): ");
  scanf("%d", &opcion);

  if (opcion == 1){
    imprimirInventario(inventario, numProductos);
  }

  // Liberar memoria
  free(inventario);

  return 0;
}

// Cargar inventario desde archivo usando memoria dinamica
Producto* cargarInventario(const char *nombreArchivo, int *numProductos){
FILE *archivo = fopen(nombreArchivo, "r");
if (!archivo){
    printf("No se encontro el archivo. Se creara uno nuevo.\n");
    *numProductos = 0;
    return NULL;
}

Producto *inventario = NULL;
Producto temp;
*numProductos = 0;


while (fscanf(archivo, "%49[^,],%d,%f\n", temp.nombre, &temp.cantidad, &temp.precio)== 3){
    inventario = realloc(inventario, (*numProductos + 1)* sizeof(Producto));
    inventario[*numProductos] = temp;
    (*numProductos)++;
}

fclose(archivo);
return inventario;
}

// Guardar inventario en archivo
void guardarInventario(const char *nombreArchivo, Producto *inventario, int numProductos) {
FILE *archivo = fopen(nombreArchivo, "w");
if (!archivo){
    printf("Error al abrir el archivo para escribir.\n");
    return;
}

for (int i = 0; i < numProductos; i++){
    fprintf(archivo, "%s,%d,%.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
}

fclose(archivo);
}

// Agregar un nuevo producto al inventario
void agregarProducto(Producto **inventario, int *numProductos){
Producto nuevo;

printf("\nIngrese el nombre del producto: ");
getchar(); // limpiar buffer
fgets(nuevo.nombre, 50, stdin);
nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0'; // quitar salto de linea

printf("Ingrese la cantidad: ");
scanf("%d", &nuevo.cantidad);

printf("Ingrese el precio: ");
scanf("%f", &nuevo.precio);

*inventario = realloc(*inventario, (*numProductos + 1) * sizeof(Producto));
(*inventario)[*numProductos] = nuevo;
(*numProductos)++;

}

// Imprimir todos los productos del inventario
void imprimirInventario(Producto *inventario, int numProductos){
if (numProductos == 0) {
    printf("\nEl inventario esta vacio. \n");
    return;
}

printf("\n--- Inventario ---\n");
for (int i = 0; i < numProductos; i++) {
    printf("%d. %s - Cantidad: %d - Precio: %.2f\n",
           i + 1, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
}
}
