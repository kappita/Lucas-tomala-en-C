#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "lista.h"

// valores globales para iterar
int i;
int j;

// funcion que abre el archivo pos[1] verifica si fue abierto corretamente
FILE *abrir_archivo(char *nombre_archivo, char *modo)
{
    FILE *arch = fopen(nombre_archivo, modo);

    // se verifica si se abre
    if(arch == NULL)
    {
        printf("Nombre incorrecto o el archivo no epos[0]iste\n");
        return NULL;
    }

    printf("Archivo abierto correctamente\n");
    return arch;
}

// funcion que lee el archivo pos[1] lo guarda en una matriz char
// a su vez guarda los valores del largo pos[1] el alto para usarlos en el main
char **cargar_laberinto(FILE *arch , int *a, int *b)
{
    char **matriz;
    int largo, alto;
    fscanf(arch, "%d %d", &alto, &largo);
    *a = alto, *b = largo;

    matriz = (char**)malloc(sizeof(char*) * alto);
    for(i = 0; i <= alto; i++)
    {
        matriz[i] = (char*)malloc(sizeof(char) * largo);
    }

    for(i = 0; i <= alto; i++)
    {
        // para corregir el salto de linea restante al leer las medidas
        getc(arch);
        for(j = 0; j <= largo; j++)
        {
            // se le agregan una columna pos[1] una fila al final para evitar
            // errores con los indices despues
            if(j == largo || i == alto)
            {
                matriz[i][j] = 'x';
            }
            else
            {
                matriz[i][j] = fgetc(arch);
            }
        }
    }

    printf("laberinto cargado con exito\n");
    return matriz;
}

int *encontrar_entrada(char **matriz, int alto, int largo)
{
    int *pos;
    pos = (int*)malloc(sizeof(int) * 2);

    for(i = 0; i < alto; i++)
    {
        for(j = 0; j < largo; j++)
        {
            if (matriz[i][j] == 'e')
            {
                pos[0] = i;
                pos[1] = j;
            }
        }
    }

    return pos;
}

int verificar_mov(char **matriz, int *pos)
{
    int movimientos = 0;

    if(matriz[pos[0] + 1][pos[1]] == 'o' || matriz[pos[0] + 1][pos[1]] == 's')
    {
        movimientos += 1;
    }
    else if(matriz[pos[0]][pos[1] + 1] == 'o' || matriz[pos[0]][pos[1] + 1] == 's')
    {
        movimientos += 1;
    }
    else if(matriz[pos[0] - 1][pos[1]] == 'o' || matriz[pos[0] - 1][pos[1]] == 's')
    {
        movimientos += 1;
    }
    else if(matriz[pos[0]][pos[1] - 1] == 'o' || matriz[pos[0]][pos[1] - 1] == 's')
    {
        movimientos += 1;
    }

    return movimientos;
}

Lista *movimientos(char **matriz, int *pos)
{
    Lista *l = crear_lista();
    Nodol *aux;
    Pila *bifurca = crear_pila();
    int movimientos, mov_aux, cont = 1;
    int *pos_aux = (int*)malloc(sizeof(int) * 2);
    int *sepa = (int*)malloc(sizeof(int) * 2);
    pos_aux[0] = pos[0], pos_aux[1] = pos[1];
    // contea de manera erronea
    movimientos = verificar_mov(matriz, pos);
    printf("movs: %d\n", movimientos);
    if(movimientos == 0)
    {
        return l;
    }
    else if(movimientos > 1)
    {
        push(bifurca, pos);
        printf("PUSHEO");
        sepa = tope(bifurca);
    }
    insertar_final(l, pos[0], pos[1]);
    while(movimientos >= 0)
    {
        // Se cae al intentar bajar
        printf("(%d,%d)\n", pos_aux[0], pos_aux[1]);
        if(matriz[pos_aux[0]][pos_aux[1] + 1] == 'o')
        {
            matriz[pos_aux[0]][pos[1] + 1] = 'x';
            pos_aux[1] += 1;
            insertar_final(l, pos_aux[0], pos_aux[1]);
        }
        else if(matriz[pos_aux[0] + 1][pos_aux[1]] == 'o')
        {
            matriz[pos_aux[0] + 1][pos_aux[1]] = 'x';
            pos[0] += 1;
            insertar_final(l, pos_aux[0], pos_aux[1]);
        }
        else if(matriz[pos_aux[0]][pos_aux[1] - 1] == 'o')
        {
            matriz[pos_aux[0]][pos_aux[1] - 1] = 'x';
            pos[1] -= 1;
            insertar_final(l, pos_aux[0], pos_aux[1]);
        }
        else if(matriz[pos_aux[0] - 1][pos_aux[1]] == 'o')
        {
            matriz[pos_aux[0] - 1][pos_aux[1]] = 'x';
            pos_aux[0] -= 1;
            insertar_final(l, pos_aux[0], pos_aux[1]);
        }
        else if(isEmptyP(bifurca) == 1 || matriz[pos[0]][pos[1]] == 's')
        {
            return l;
        }
        // SECTOR MALO
        // se deberia hacer pop a la bifurcacion si es que no se puede mover desde el ultimo punto
        // mov_aux = verificar_mov(matriz, pos_aux);
        // printf("%d, %d\n", sepa[0], sepa[1]);
        // if(mov_aux == 0)
        // {
        //     printf("POPEO");
        //     pop(bifurca);
        //     while
        // }
        // else if(mov_aux > 1)
        // {
        //     printf("PUSHEO");
        //     push(bifurca, pos_aux);
        //     sepa[0] = pos_aux[0];
        //     sepa[1] = pos_aux[1];
        // }
        // else if(mov_aux >= 1 && verificar_mov(matriz, pos_aux) == 0)
        // {
        //     printf("REGRESO");
        //     pos[0] = pos_aux[0];
        //     pos[1] = pos_aux[1];
        // }
    }
}

int main(int argc, char *argv[])
{
    FILE *arch;
    char **matriz;
    int alto, largo;
    int *pos_entrada;
    char salida;
    Lista *l;

    arch = abrir_archivo(argv[2], "r");

    // en caso de no epos[0]istir el archivo se termina el programa
    if(arch == NULL)
    {
        return 0;
    }
    
    matriz = cargar_laberinto(arch, &alto, &largo);
    pos_entrada = encontrar_entrada(matriz, alto, largo);
    l = movimientos(matriz, pos_entrada);

    if(l -> inicio == NULL || l -> inicio -> valor1 == -1)
    {
        printf("El laberinto no tiene solucion");
    }
    else
    {
        printf("Hay salida y el recorrido es:\n");
        for(i = 0; i < alto; i++)
        {
            for(j = 0; j < largo; j++)
            {
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }
        printf("%d, %d\n", valor_pos(l, 2)[0], valor_pos(l, 2)[1]);
        printf("%d", l -> largo);
    }
    
    return 0;
}