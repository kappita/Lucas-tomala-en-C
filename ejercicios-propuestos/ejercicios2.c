#include <stdio.h>

// variable generales
int i;
int j;

// Ejercicio 9.5

#define filas_3 3
#define columnas_4 4

void leer_filas(int *A)
{
    for(i = 0; i < (filas_3); i++)
    {
        for(j = 0; j < (columnas_4); j++)
        {
            printf("Ingrese el valor %d %d de la matriz: ", i + 1, j + 1);
            scanf("%d", A);
            A++;
        }        
    }
}

void imprimir_columnas(int A[filas_3][columnas_4])
{
    printf("La matriz es: \n");

    for(i = 0; i < columnas_4; i++)
    {
        printf("(");
        for(j = 0; j < filas_3; j++)
        {
            if( ((j+1) % filas_3) == 0)
            {
                printf("%d)\n", A[j][i]);
            }
            else
            {
                printf("%d ", A[j][i]);
            }
        }
    }
}

// Ejercicio 9.6

#define filas_m 4

void generar_matriz(int *A)
{
    for(i = 0; i < (filas_m); i++)
    {
        for(j = 0; j < (filas_m); j++)
        {
            printf("Ingrese el valor %d %d de la matriz: ", i + 1, j + 1);
            scanf("%d", A);
            A++;
        }        
    }
}

void imprimir_matriz(int A[filas_m][filas_m])
{
    printf("La matriz es: \n");

    for(i = 0; i < filas_m; i++)
    {
        printf("(");
        for(j = 0; j < filas_m; j++)
        {
            if( ((j+1) % filas_m) == 0)
            {
                printf("%d)\n", A[i][j]);
            }
            else
            {
                printf("%d ", A[i][j]);
            }
        }
    }
}

int suma_matriz(int A[filas_m][filas_m])
{
    int total_m = 0;

    for(i = 0; i < filas_m; i++)
    {
        for(j = 0; j < filas_m; j++)
        {
            if(j != i)
            {
                total_m += A[i][j];
            }
        }
    }

    return total_m;
}

int main()
{
    // Ejercicio 9.5
    int matriz_1[filas_3][columnas_4];

    leer_filas(matriz_1);

    imprimir_columnas(matriz_1);

    // Ejercicio 9.6
    int matriz_2[filas_m][filas_m];

    generar_matriz(matriz_2);

    imprimir_matriz(matriz_2);

    printf("El valor de la suma de la matriz sin la diagonal es: %d", suma_matriz(matriz_2));
}