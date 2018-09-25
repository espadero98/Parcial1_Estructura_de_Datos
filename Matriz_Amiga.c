#include <stdio.h>
#include <stdlib.h>

//MATRIZ AMIGA

int main() {
    int filas, columnas, i, j;
    int sumas = 0, sumfil = 0, sumcol = 0, sumd = 0;
    int pivote = 0,fil=0,col=1;
    int sumatotal=15,sum1,sum2,sum3;
    printf("Ingrese el numero de filas de la matriz:	");
    scanf("%d", &filas);
    printf("Ingrese el numero de filas de la matriz:	");
    scanf("%d", &columnas);
    int matriz[filas][columnas];

    printf("\nIngrese la matriz:\n");
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            printf("Posicion(%d,%d): ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nLa matriz ingresada es:\n");
    for (i = 0; i < filas; i++) {
        printf("[");
        for (j = 0; j < columnas; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("]\n");
    }
    //SE DEFINE CUANTO SERA LA SUMA EN COMUN
    j=0;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            sumas = sumas + matriz[i][j];
        }
        sumatotal=sumas;
        sumas=0;
        break;
    }
    //SUMA DE FILAS
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            sumas = sumas + matriz[i][j];
        }
        if (sumas == sumatotal) {
            sumfil++;
            sumas = 0;
        }
    }
    //SUMA DE COLUMNAS
    for (i = 0; i < columnas; i++) {
        for (j = 0; j < filas; j++) {
            sumas = sumas + matriz[j][i];
        }
        if (sumas ==sumatotal) {
            sumcol++;
            sumas = 0;
        }
    }  
    //SUMA DE DIAGONALES
    //Diagonal1
    for (fil = 0; fil < filas; fil++) {
        sumas=sumas+matriz[fil][columnas-col];
        col=col+1;
    }
    if (sumas==sumatotal) {
        sumd++;
    }
    col = 0;
    sumas = 0;   
    //Diagonal2
    for (fil = 0; fil < filas; fil++) {
        sumas = sumas + matriz[fil][col];
        col = col + 1;
    } 
    if (sumas==sumatotal) {
        sumd++;
    }

    if (sumfil==filas && sumcol==columnas && sumd==2) {
        printf("\nLa matriz es Amiga...");

    }else{
        printf("\nLa matriz no es Amiga...");
    }
    return 0;
}
