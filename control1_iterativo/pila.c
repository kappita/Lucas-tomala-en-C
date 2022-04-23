#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

Pila *crear_pila()
{
    Pila *p;
    p = (Pila*)malloc(sizeof(Pila));
    p -> tope = NULL;
    return p;
}

Nodop *crear_nodoP(int *valor)
{
    Nodop *n;
    n = (Nodop*)malloc(sizeof(Nodop));
    n -> valor1 = valor[0];
    n -> valor2 = valor[1];
    n -> next = NULL;
    return n;
}

int isEmptyP(Pila *p)
{
    if(p -> tope == NULL)
    {
        return 1;
    }
    return 0;
}

void push(Pila *p, int *valor)
{
    Nodop *n;
    n = crear_nodoP(valor);
    printf("%d, %d\n", n -> valor1, n -> valor2);
    if(isEmptyP(p) == 1)
    {
        p -> tope = n;
    }
    else
    {
        n -> next = p -> tope;
        p -> tope = n;
    }
}

int *pop(Pila *p)
{
    int *popeado = (int*)malloc(sizeof(int) * 2);
    if(isEmptyP(p) == 1)
    {
        printf("Pila vacia\n");
        return 0;
    }
    Nodop *aux;
    aux = p -> tope;
    p -> tope = aux -> next;
    popeado[0] = aux -> valor1;
    popeado[1] = aux -> valor2;
    free(aux);
    return popeado;
}

int *tope(Pila *p)
{
    int *tope_p = (int*)malloc(sizeof(int) * 2);
    Nodop *aux = p -> tope;
    tope_p[0] = aux -> valor1;
    tope_p[1] = aux -> valor2;
    return tope_p;
}

void destruirPila(Pila *p)
{
    while(p -> tope != NULL)
    {
        pop(p);
    }
    printf("Pila destruida\n");
}
