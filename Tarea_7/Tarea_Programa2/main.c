#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==== ESTRUCTURAS ====
typedef struct
{
    int id;
    char marca[30];
    char modelo[30];
    int ano;
    char placa[15];
    float consumo_ciudad;   //L/100Km
    float consumo_carretera;   //L/100Km
    float costo_seguro_anual;
    float costo_cambio_Km;
    int tiempo_depreciacion;
    float costo_vehiculo;
    float Km_promedio_anual;
    float costo_limpieza;
} Vehiculo;

typedef struct
{
    float gasolina_premium;
    float gasolina_regular;
    float gasoil_regular;
    float gasoil_optimo;
    float avtur;
    float kerosene;
    float glp;
    float gas_natural;
} combustible;

// ==== ARCHIVOS ====
#define ARCH_VEH "vehiculos.dat"
#define ARCH_COMB "combustible.dat"

// ==== PROTOTIPOS ====
void menu();
void agregarVehiculos();
void listarVehiculos();
void modificarVehiculo();
void agregarCombustible();
void modificarCombustible();
void listarCombustible();
void calcularViaje();
void guardarCombustible(combustible c);
combustible cargarcombustible();

// ==== MAIN ====

int main()
{
    menu();
    return 0;
}

// ==== MENU PRINCIPAL ====
void menu()
{
    int op;
    do
    {
        printf("\n===== CALCULO DE COSTO DE VIAJE ====\n");
        printf("1. Agregar Vehiculo\n");
        printf("2. Listar Vehiculos\n");
        printf("3. Modificar Vehiculo\n");
        printf("4. Agregar Combustibles (Inicializar precios)\n");
        printf("5. Modificar Combustible\n");
        printf("6. Listar Combustibles\n");
        printf("7. Calcular Viaje\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            agregarVehiculos();
            break;
        case 2:
            listarVehiculos();
            break;
        case 3:
            modificarVehiculo();
            break;
        case 4:
            agregarCombustible();
            break;
        case 5:
            modificarCombustible();
            break;
        case 6:
            listarCombustible();
            break;
        case 7:
            calcularViaje();
            break;
        case 0:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion no valida.\n");
        }
    }
    while(op != 0);

}

// ==== VEHICULOS ====
void agregarVehiculos()
{
    Vehiculo v;
    FILE *f =fopen(ARCH_VEH, "ab");
    if (!f)
    {
        printf("Error al abrir el archivo de vehiculos.\n");
        return;
    }

    printf("ID del vehiculo: ");
    scanf("%d", &v.id);
    printf("Marca: ");
    scanf("%s", v.marca);
    printf("Modelo: ");
    scanf("%s", v.modelo);
    printf("Año: ");
    scanf("d", &v.ano);
    printf("Placa: ");
    scanf("%s", v.placa);
    printf("Consumo en ciudad (L/100Km): ");
    scanf("%f", &v.consumo_ciudad);
    printf("Consumo en carretera (L/100Km): ");
    scanf("%f", &v.consumo_carretera);
    printf("Costo de seguro anual (RD$): ");
    scanf("%f", &v.costo_seguro_anual);
    printf("Costo de cambio por Km (RD$): ");
    scanf("%f", &v.costo_cambio_Km);
    printf("Tiempo de depreciacion (años): ");
    scanf("%d", &v.tiempo_depreciacion);
    printf("Costo del vehiculo (RD$): ");
    scanf("%f", &v.costo_vehiculo);
    printf("Km promedio por año: ");
    scanf("%f", &v.Km_promedio_anual);
    printf("Costo de limpieza (RD$): ");
    scanf("%F", &v.costo_limpieza);

    fwrite(&v, sizeof(Vehiculo), 1, f);
    fclose(f);
    printf("Vehiculo agregado correctamente.\n");

}

void listarVehiculos()
{
    Vehiculo v;
    FILE *f = fopen(ARCH_VEH, "rb");
    if (!f)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }
    printf("\n--- LISTA DE VEHICULOS ---\n");
    while (fread(&v, sizeof(Vehiculo), 1, f))
    {
        printf("ID: %d | %s %s (%d) | Placa: %s | Costo: %.2f\n", v.id, v.marca, v.modelo, v.ano, v.placa, v.costo_vehiculo);
    }
    fclose(f);
}

void modificarVehiculo()
{
    int id, encontrado = 0;
    Vehiculo v;
    FILE *f = fopen(ARCH_VEH, "r+b");
    if (!f)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    printf("Ingrese el ID del vehiculo a modificar: ");
    scanf("%d", &id);

    while (fread(&v, sizeof(Vehiculo), 1, f))
    {
        if (v.id == id)
        {
            printf("Modificando %s %s\n", v.marca, v.modelo);
            printf("Nuevo consumo ciudad (L/100Km): ");
            scanf("%f", &v.consumo_ciudad);
            printf("Nuevo consumo carretera (L/100Km): ");
            scanf("%f", &v.consumo_carretera);
            printf("Nuevo costo seguro anual (RD$): ");
            scanf("%f", &v.costo_seguro_anual);
            fseek(f, -sizeof(Vehiculo), SEEK_CUR);
            fwrite(&v, sizeof(Vehiculo), 1, f);
            encontrado = 1;
            break;
        }
    }
    fclose(f);

    if (encontrado) printf("Vehiculo modificado con exito.\n");
    else printf("Vehiculo no encontrado.\n");

}

// ==== COMBUSTIBLE ====
void agregarCombustible()
{
    combustible c;
    c.gasolina_premium = 290.10;
    c.gasolina_regular = 271.50;
    c.gasoil_regular = 224.80;
    c.gasoil_optimo = 242.10;
    c.avtur = 196.50;
    c.kerosene = 227.60;
    c.glp = 137.20;
    c.gas_natural = 43.97;
    guardarCombustible(c);
    printf("combustible inicializados correctamente.\n");
}


void listarCombustible()
{
    combustible c = cargarcombustible();
    printf("\n--- LISTA DE COMBUSTIBLES ---\n");
    printf("Gasolina Premium: %.2f RD$/galon\n", c.gasolina_premium);
    printf("Gasolina Regular: %.2f RD$/galon\n", c.gasolina_regular);
    printf("Gasoil Regular: %.2f RD$/galon\n", c.gasolina_premium);
    printf("GGasoil Optimo: %.2f RD$/galon\n", c.gasoil_optimo);
    printf("Avtur: %.2f RD$/galon\n", c.avtur);
    printf("Kerosene: %.2f RD$/galon\n", c.kerosene);
    printf("GLP: %.2f RD$/galon\n", c.glp);
    printf("Gas Natural: %.2f RD$/m³\n", c.gas_natural);
}


void modificarCombustible()
{
    combustible c = cargarcombustible();
    int op;
    printf("\n--- MODIFICAR COMBUSTIBLE ---\n");
    printf("1. Gasolina Premium\n2. Gasolina Regular\n3. Gasoil Regular\n4. Gasoil Optimo\n5. Avtur\n6. Kerosene\n7. GLP\n8. Gas Natural\n");
    printf("Seleccione el combustible a modificar: ");
    scanf("%d", &op);

    switch(op)
    {
    case 1:
        printf("Nuevo precio Gasolina Premium: ");
        scanf("%f", &c.gasolina_premium);
        break;
    case 2:
        printf("Nuevo precio Gasolina Regular: ");
        scanf("%f", &c.gasolina_regular);
        break;
    case 3:
        printf("Nuevo precio Gasoil Regular: ");
        scanf("%f", &c.gasoil_regular);
        break;
    case 4:
        printf("Nuevo precio Gasoil Optimo: ");
        scanf("%f", &c.gasoil_optimo);
        break;
    case 5:
        printf("Nuevo precio Avtur: ");
        scanf("%f", &c.avtur);
        break;
    case 6:
        printf("Nuevo precio Kerosene: ");
        scanf("%f", &c.kerosene);
        break;
    case 7:
        printf("Nuevo precio GLP: ");
        scanf("%f", &c.glp);
        break;
    case 8:
        printf("Nuevo precio Gas Natural: ");
        scanf("%f", &c.gas_natural);
        break;
    default:
        printf("Opcion invalida.\n");
        return;
    }

    guardarCombustible(c);
    printf("Precio modificado correctamente.\n");
}

void guardarCombustible(combustible c)
{
    FILE *f = fopen(ARCH_COMB, "wb");
    if (f)
    {
        fwrite(&c, sizeof(combustible), 1, f);
        fclose(f);
    }
}

combustible cargarcombustible()
{
    combustible c;
    FILE *f = fopen(ARCH_COMB, "rb");
    if (f)
    {
        fread(&c, sizeof(combustible), 1, f);
        fclose(f);
    }
    else
    {
        c.gasolina_premium = 290.10;
        c.gasolina_regular = 272.50;
        c.gasoil_regular = 224.80;
        c.gasoil_optimo = 242.10;
        c.avtur = 196.50;
        c.kerosene = 227.60;
        c.glp = 137.20;
        c.gas_natural = 43.97;
    }
    return c;
}

// ==== CALCULAR VIAJE ====
void calcularViaje()
{
    Vehiculo v;
    combustible c = cargarcombustible();
    int id, op;
    float km, porc_ciudad, consumo_medio, costo_combustible, costo_total, costo_km;

    FILE *f = fopen(ARCH_VEH, "rb");
    if (!f)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    printf("Ingrese el ID del vehiculo: ");
    scanf("%d", &id);

    int encontrado = 0;
    while (fread(&v, sizeof(Vehiculo), 1, f))
    {
        if (v.id == id)
        {
            encontrado = 1;
            break;
        }
    }
    fclose(f);

    if(!encontrado)
    {
        printf("Vehicullo no encontrado.\n");
        return;

    }

    printf("Ingrese cantidad de KM del viaje: ");
    scanf("%f", &km);
    printf("Ingrese %% de KM en ciudad (0-100): ");
    scanf("%f", &porc_ciudad);

    printf("\nSeleccione el tipo de combustible:\n");
    printf("1. Gasolina Premium\n2. Gasolina Regular\n3. Gasoil Regular\n4. Gasoil Optimo\n5. Avtur\n6. Kerosene\n7. GLP\n8. Gas Natural\n");
    scanf("%d", &op);


    switch(op)
    {
    case 1:
        costo_combustible = c.gasolina_premium;
        break;
    case 2:
        costo_combustible = c.gasolina_regular;
        break;
    case 3:
        costo_combustible = c.gasoil_regular;
        break;
    case 4:
        costo_combustible = c.gasoil_optimo;
        break;
    case 5:
        costo_combustible = c.avtur;
        break;
    case 6:
        costo_combustible = c.kerosene;
        break;
    case 7:
        costo_combustible = c.glp;
        break;
    case 8:
        costo_combustible = c.gas_natural;
        break;
    default:
        printf("Opcion invalida.\n");
        return;
    }

    // ---- Nuevo calculo de depreciacion ----
    // 25% anual del valor del vehiculo
    float depreciacion_anual = v.costo_vehiculo * 0.25;

    // Consumo ponderado segun % de ciudad y carretera
    consumo_medio = (porc_ciudad/100) * v.consumo_ciudad + ((100 - porc_ciudad)/100) * v.consumo_carretera;

    float litros_totales = (km * consumo_medio) / 100.0;
    float costo_comb = litros_totales * costo_combustible;

    // Costo de depreciacion por Km = 25% del valor anual / Km promedio anual
    float costo_Km_depreciacion = depreciacion_anual / v.Km_promedio_anual;

    costo_total = costo_comb +
                  (v.costo_seguro_anual / 12) +
                  (v.costo_cambio_Km * km) +
                  v.costo_limpieza +
                  (costo_Km_depreciacion * km);

    costo_km = costo_total / km;

    printf("\n==== RESULTADO DEL VIAJE ====\n");
    printf("Vehiculo: %s %s\n", v.marca, v.modelo);
    printf("Combustible: RD$%.2f\n", costo_combustible);
    printf("Consumo medio: %.2f L/100Km\n", consumo_medio);
    printf("Costo total del viaje: RD$%.2f\n", costo_total);
    printf("Costo por Km: RD$%.2f\n", costo_km);
    printf("Depreciacion aplicada: 25% anual (RD$%.2f por año)\n", depreciacion_anual);

}
