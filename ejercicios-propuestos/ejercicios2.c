#include <stdio.h>

// variable generales
int i;
int j;

// Ejercicio 9.9

#define largo 10

float promedio(int A[10])
{
    float total = 0;

    for(i = 0; i < largo; i++)
    {
        total += A[i];
    }
    
    total = total / largo;

    return total;
}

int suma(int A[10])
{
    int total_s = 0;

    for(i = 0; i < largo; i++)
    {
        total_s += A[i];
    }

    return total_s;
}

// Ejercicio 9.6

#define filas_m 4

void imprimir_matriz(int A[filas_m][filas_m])
{
    printf("La matriz es: \n");

    for(i = 0; i < filas_m; i++)
    {
        printf("(");
        for(j = 0; j < filas_m; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf(")\n");
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
    // Ejercicio 9.9
    int numeros[10];
       for(i = 0; i < largo; i++)
    {   
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("La suma de los 10 numeros es: %d\n", suma(numeros));
    printf("El promedio de los 10 numeros es: %0.5f", promedio(numeros));

    // Ejercicio 9.6
    int matriz[filas_m][filas_m];
    int num = 1;

    for(i = 0; i < filas_m; i++)
    {
        for(j = 0; j < filas_m; j++)
        {
            printf("Ingrese el valor %d %d de la matriz: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    imprimir_matriz(matriz);

    printf("El valor de la suma de la matriz sin la diagonal es: %d", suma_matriz(matriz));

    return 0;
}