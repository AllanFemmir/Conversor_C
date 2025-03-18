#include <stdio.h>

// Tasas de cambio (puedes actualizar estos valores según el mercado)
#define USD_TO_GTQ 7.8
#define USD_TO_EUR 0.91
#define GTQ_TO_USD (1 / USD_TO_GTQ)
#define GTQ_TO_EUR (GTQ_TO_USD * USD_TO_EUR)
#define EUR_TO_USD (1 / USD_TO_EUR)
#define EUR_TO_GTQ (EUR_TO_USD * USD_TO_GTQ)

// Función para convertir monedas
double convertir(double cantidad, double tasa) {
    return cantidad * tasa;
}

int main() {
    int opcionOrigen, opcionDestino;
    double cantidad, resultado;

    printf("=== Conversor de Monedas ===\n");
    printf("1. Quetzales (GTQ)\n");
    printf("2. Dólares (USD)\n");
    printf("3. Euros (EUR)\n");

    // Seleccionar moneda de origen
    printf("Seleccione la moneda de origen (1-3): ");
    scanf("%d", &opcionOrigen);

    // Seleccionar moneda de destino
    printf("Seleccione la moneda de destino (1-3): ");
    scanf("%d", &opcionDestino);

    // Validar opciones
    if (opcionOrigen < 1 || opcionOrigen > 3 || opcionDestino < 1 || opcionDestino > 3 || opcionOrigen == opcionDestino) {
        printf("Opción no válida. Intente nuevamente.\n");
        return 1;
    }

    // Ingresar cantidad a convertir
    printf("Ingrese la cantidad a convertir: ");
    scanf("%lf", &cantidad);

    // Determinar la tasa de conversión
    switch (opcionOrigen) {
        case 1: // GTQ
            if (opcionDestino == 2) resultado = convertir(cantidad, GTQ_TO_USD);
            else if (opcionDestino == 3) resultado = convertir(cantidad, GTQ_TO_EUR);
            break;
        case 2: // USD
            if (opcionDestino == 1) resultado = convertir(cantidad, USD_TO_GTQ);
            else if (opcionDestino == 3) resultado = convertir(cantidad, USD_TO_EUR);
            break;
        case 3: // EUR
            if (opcionDestino == 1) resultado = convertir(cantidad, EUR_TO_GTQ);
            else if (opcionDestino == 2) resultado = convertir(cantidad, EUR_TO_USD);
            break;
    }

    // Mostrar resultado
    printf("El resultado de la conversión es: %.2f\n", resultado);

    return 0;
}
