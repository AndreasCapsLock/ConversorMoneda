#include <stdio.h>
#include <stdlib.h>  // Para usar la función exit() en caso de error

// Tasas de cambio (puedes actualizarlas según el mercado)
#define GTQ_TO_USD 0.13
#define GTQ_TO_EUR 0.12
#define USD_TO_GTQ 7.8
#define EUR_TO_GTQ 8.5
#define USD_TO_EUR 0.93
#define EUR_TO_USD 1.07

// Función para convertir monedas
void convertirMoneda(float cantidad, int opcion) {
    float resultado;

    switch (opcion) {
        case 1: // Quetzales a Dólares
            resultado = cantidad * GTQ_TO_USD;
            printf("%.2f GTQ equivalen a %.2f USD\n", cantidad, resultado);
            break;
        case 2: // Quetzales a Euros
            resultado = cantidad * GTQ_TO_EUR;
            printf("%.2f GTQ equivalen a %.2f EUR\n", cantidad, resultado);
            break;
        case 3: // Dólares a Quetzales
            resultado = cantidad * USD_TO_GTQ;
            printf("%.2f USD equivalen a %.2f GTQ\n", cantidad, resultado);
            break;
        case 4: // Dólares a Euros
            resultado = cantidad * USD_TO_EUR;
            printf("%.2f USD equivalen a %.2f EUR\n", cantidad, resultado);
            break;
        case 5: // Euros a Quetzales
            resultado = cantidad * EUR_TO_GTQ;
            printf("%.2f EUR equivalen a %.2f GTQ\n", cantidad, resultado);
            break;
        case 6: // Euros a Dólares
            resultado = cantidad * EUR_TO_USD;
            printf("%.2f EUR equivalen a %.2f USD\n", cantidad, resultado);
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }
}

// Función para leer y validar la cantidad
float leerCantidad() {
    float cantidad;
    int result;

    while (1) {
        printf("Ingrese la cantidad: ");
        result = scanf("%f", &cantidad);
        if (result == 1 && cantidad > 0) {
            return cantidad;  // Si es un número válido, retornamos la cantidad
        } else {
            // Si la entrada no es válida o es negativa, mostramos un error
            printf("Por favor ingrese un valor numérico positivo.\n");
            while (getchar() != '\n');  // Limpiar el buffer del teclado
        }
    }
}

int main() {
    int opcion;
    float cantidad;

    do {
        // Menú de opciones
        printf("\n--- Conversor de Monedas ---\n");
        printf("1. Quetzales a Dólares\n");
        printf("2. Quetzales a Euros\n");
        printf("3. Dólares a Quetzales\n");
        printf("4. Dólares a Euros\n");
        printf("5. Euros a Quetzales\n");
        printf("6. Euros a Dólares\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 6) {
            cantidad = leerCantidad();  // Leemos la cantidad con validación
            convertirMoneda(cantidad, opcion);
        } else if (opcion != 7) {
            printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 7);

    printf("Gracias por usar el conversor de monedas.\n");

    return 0;
}
