#include <stdio.h>
#include <stdlib.h>

void main() {
    int filas, columnas, fil, col;
    int miColumna = 0, miFila = 0, pivote, i, j;
    printf("Ingrese el largo de las filas que tendra la matriz\n");
    scanf("%d", &filas);

    printf("Ingrese el largo de las columnas que tendra la matriz\n");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    //Ingreso de datos a la matriz
    for (fil = 0; fil < filas; fil++) {
        for (col = 0; col < columnas; col++) {
            printf("Posición (%d,%d):    ", fil + 1, col + 1);
            scanf("%d", &matriz[fil][col]);
        }
    }
    printf("\nLa matriz es:\n");
    //Imprimir matriz
    for (fil = 0; fil < filas; fil++) {
        printf("[");
        for (col = 0; col < columnas; col++) {
            printf("  %d  ", matriz[fil][col]);
        }
        printf("]\n");
    }
    printf("\n");
    for (fil = 0; fil < filas; fil++) {
        for (col = 0; col < columnas; col++) {
            pivote = matriz[fil][col];
            for (j = 0; j < columnas; j++) {   
                if (pivote > matriz[fil][j]) {
                    miColumna = miColumna + 1;
                }
            }
            for (i = 0; i < filas; i++) {
                if (pivote < matriz[i][col]) {
                    miFila = miFila + 1;
                }
            }
            if (miColumna == 0 && miFila == 0) {
                printf("\nHay un punto de silla en la matriz es: %d y se encuentra en la fila: %d y la columna: %d\n", pivote, (fil + 1), (col + 1));
            }
            miFila = 0;
            miColumna = 0;
        }
    }
}
