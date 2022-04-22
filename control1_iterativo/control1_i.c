#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "lista.h"

// valores globales para iterar
int i;
int j;

// funcion que abre el archivo y verifica si fue abierto corretamente
FILE *abrir_archivo(char *nombre_archivo, char *modo)
{
    FILE *arch = fopen(nombre_archivo, modo);

    // se verifica si se abre
    if(arch == NULL)
    {
        printf("Nombre incorrecto o el archivo no existe\n");
        return NULL;
    }

    printf("Archivo abierto correctamente\n");
    return arch;
}

// funcion que lee el archivo y lo guarda en una matriz char
// a su vez guarda los valores del largo y el alto para usarlos en el main
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
            // se le agregan una columna y una fila al final para evitar
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

int verificar_mov(char **matriz, int x, int y)
{
    int movimientos = 0;

    if(matriz[x + 1][y] == 'o' || matriz[x + 1][y] == 's')
    {
        movimientos += 1;
    }
    else if(matriz[x][y + 1] == 'o' || matriz[x][y + 1] == 's')
    {
        movimientos += 1;
    }
    else if(matriz[x - 1][y] == 'o' || matriz[x - 1][y] == 's')
    {
        movimientos += 1;
    }
    else if(matriz[x][y - 1] == 'o' || matriz[x][y - 1] == 's')
    {
        movimientos += 1;
    }

    return movimientos;
}

Lista *movimientos(char **matriz, int *pos)
{
    Lista *l = crear_lista();
    Nodol *aux;
    Nodop *sepa;
    Pila *bifurca = crear_pila();
    int movimientos, sepa1, sepa2;
    int x = pos[0], y = pos[1], cont = 1;
    
    movimientos = verificar_mov(matriz, x, y);
    if(movimientos == 0)
    {
        return l;
    }
    else if(movimientos > 1)
    {
        push(bifurca, x, y);
        sepa = bifurca -> tope;
        sepa1 = sepa -> valor1;
        sepa2 = sepa -> valor2;
    }
    insertar_final(l, x, y);
    while(movimientos >= 0)
    {
        printf("(%d,%d)\n", x, y);
        if(matriz[x][y + 1] == 'o')
        {
            matriz[x][y + 1] = 'x';
            y += 1;
            insertar_final(l, x, y);
        }
        else if(matriz[x + 1][y] == 'o')
        {
            matriz[x + 1][y] = 'x';
            x += 1;
            insertar_final(l, x, y);
        }
        else if(matriz[x][y - 1] == 'o')
        {
            matriz[x][y - 1] = 'x';
            y -= 1;
            insertar_final(l, x, y);
        }
        else if(matriz[x - 1][y] == 'o')
        {
            matriz[x - 1][y] = 'x';
            x -= 1;
            insertar_final(l, x, y);
        }
        else if(bifurca -> tope == NULL || matriz[x][y] == 's')
        {
            return l;
        }
        // SECTOR MALO
        // se deberia hacer pop a la bifurcacion si es que no se puede mover desde el ultimo punto
        /*
        movimientos = verificar_mov(matriz, x, y);
        if(movimientos == 0 || isEmptyP(bifurca) == 0)
        {
            x = sepa1;
            y = sepa2;
            aux = l -> inicio;
            while(aux -> valor1 != x && aux -> valor2 != y)
            {
                aux = aux -> next;
                cont += 1;
            }
            while(aux -> next != NULL)
            {
                eliminar_pos(l, cont);
            }
        }
        else if(movimientos > 1)
        {
            push(bifurca, x, y);
        }
        movimientos = verificar_mov(matriz, sepa1, sepa2);
        if(movimientos == 0)
        {
            pop(bifurca);
            sepa = bifurca -> tope;
            sepa1 = sepa -> valor1;
            sepa2 = sepa -> valor2;
        }
        */
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

    // en caso de no existir el archivo se termina el programa
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