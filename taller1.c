#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char nombres[10][50];
    float precios[10];

    int opc, opc1, contP = 0;

    float total = 0;
    float promedio = 0;
    float max = 0, min = 0;

    char buscar[50];

    do {
        printf("\nSeleccione una opcion:\n");
        printf("1. Registrar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular precio total\n");
        printf("4. Producto mas caro y mas barato\n");
        printf("5. Calcular precio promedio\n");
        printf("6. Buscar producto\n");
        printf("7. Salir\n");
        printf(">> ");

        scanf("%d", &opc);

        switch (opc) {

            case 1:
                if (contP < 10) {

                    printf("Ingrese los datos del producto:\n");
                    printf("Nombre: ");
                    scanf(" %49[^\n]", nombres[contP]);

                    do {
                        printf("Precio: ");
                        scanf("%f", &precios[contP]);

                        if (precios[contP] < 0) {
                            printf("El precio no puede ser negativo.\n");
                        }

                    } while (precios[contP] < 0);

                    contP++;

                } else {
                    printf("El inventario esta lleno.\n");
                }

                break;

            case 2://inventario(erick)

                printf("N.\tNombre\tPrecio\n");
                for(int i=0; i < contP; i++){

                    printf("%d.\t%s\t%.2f$\n",i,nombres[i], precios[i]);
                }

                // Erick: aqui va tu codigo para mostrar el inventario
                break;

            case 3:
                // Royer: aqui va tu codigo para calcular el precio total
                total = 0;
                if (contP > 0) {
                    for (int i = 0; i < contP; i++) {
                        total += precios[i];
                    }
                    printf("El precio total del inventario es: %.2f$\n", total);
                } else {
                    printf("No hay productos en el inventario para calcular.\n");
                }
                break;

            case 4:
                // Royer: aqui va tu codigo para encontrar el producto mas caro y mas barato
                if (contP > 0) {
                    max = precios[0];
                    min = precios[0];
                    int posMax = 0;
                    int posMin = 0;

                    for (int i = 1; i < contP; i++) {
                        if (precios[i] > max) {
                            max = precios[i];
                            posMax = i;
                        }
                        if (precios[i] < min) {
                            min = precios[i];
                            posMin = i;
                        }
                    }
                    printf("Producto mas caro: %s (%.2f$)\n", nombres[posMax], max);
                    printf("Producto mas barato: %s (%.2f$)\n", nombres[posMin], min);
                } else {
                    printf("No hay productos en el inventario para comparar.\n");
                }
                break;

            case 5:
                // Royer: aqui va tu codigo para calcular el precio promedio
                if (contP > 0) {
                    total = 0;
                    for (int i = 0; i < contP; i++) {
                        total += precios[i];
                    }
                    promedio = total / contP;
                    printf("El precio promedio de los productos es: %.2f$\n", promedio);
                } else {
                    printf("No hay productos en el inventario para calcular el promedio.\n");
                }
                break;

            case 6:   
                if (contP == 0) {
                    printf("El inventario esta vacio.\n");
                } else
                {
                    printf("Ingrese el nombre del producto que desea buscar: ");
                    scanf(" %49[^\n]", buscar);

                    int encontrado = 0;

                    for (int i = 0; i < contP; i++) {
                    if (strcmp(buscar, nombres[i]) == 0) {
                        encontrado = 1;
                        printf("Producto encontrado: %s\n", nombres[i]);
                        printf("Precio: %.2f$\n", precios[i]);
                    }
                }
                    if (encontrado == 0) {
                    printf("Producto no encontrado.\n");
                }
                }
                break;

            case 7:
                printf("Programa finalizado.\n");
                return 0;

            default:
                printf("No existe la opcion.\n");
                break;
        }

        printf("\nDesea seleccionar otra opcion? 1.Si / 2.No: ");
        scanf("%d", &opc1);

    } while (opc1 == 1);

    return 0;
}