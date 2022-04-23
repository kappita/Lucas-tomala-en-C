#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista *crear_lista()
{
    Lista *l;
    l = (Lista*)malloc(sizeof(Lista));
    l -> inicio = NULL;
    l -> largo = 0;
    return l;
}

Nodol *crear_nodo(int *valor)
{
    Nodol *n;
    int *valor_aux = (int*)malloc(sizeof(int) * 2);
    valor_aux[0] = valor[0]; valor_aux[1] = valor[1];
    n = (Nodol*)malloc(sizeof(Nodol));
    n -> valor1 = valor_aux[0];
    n -> valor2 = valor_aux[1];
    n -> next = NULL;
    return n;
}

int isEmptyL(Lista *l)
{
    if(l -> inicio == NULL)
    {
        return 1;
    }
    return 0;
}

void insertar_inicio(Lista *l, int *valor)
{
    Nodol *n;
    n = crear_nodo(valor);
    if(isEmptyL(l) == 1)
    {
        l -> inicio = n;
    }
    else
    {
        n -> next = l -> inicio;
        l -> inicio = n;
    }
    l -> largo += 1;
}

void insertar_final(Lista *l, int *valor)
{
    Nodol *n;
    n = crear_nodo(valor);
    if(isEmptyL(l) == 1)
    {
        l -> inicio = n;
    }
    else
    {
        Nodol *aux = l -> inicio;
        while(aux -> next != NULL)
        {
            aux = aux -> next;
        }
        aux -> next = n;
    }
    l -> largo += 1;
}

void insertar_pos(Lista *l, int pos, int *valor)
{
    Nodol *n, *aux1, *aux2;
    n = crear_nodo(valor);
    if(isEmptyL(l) == 1)
    {
        l -> inicio = n;
        l -> largo += 1;
    }
    else
    {
        
        if(pos > l -> largo)
        {
            printf("Posicion no valida");
        }
        else if(pos == 0)
        {
            insertar_inicio(l, valor);
            l -> largo += 1;
        }
        else
        {
            aux1 = l -> inicio;
            aux2 = l -> inicio -> next;
            for(int i = 1; i < pos; i++)
            {
                aux1 = aux1 -> next;
                aux2 = aux2 -> next;
            }
            aux1 -> next = n;
            n -> next = aux2;
            l -> largo += 1;
        }    
    }
}

int *valor_inicial(Lista *l)
{
    int *inicial = (int*)malloc(sizeof(int) * 2);
    inicial[0] = l -> inicio -> valor1;
    inicial[1] = l -> inicio -> valor2;
    return inicial;
}

int *valor_final(Lista *l)
{    
    int *final = (int*)malloc(sizeof(int) * 2);
    Nodol *aux = l -> inicio;
    while(aux -> next != NULL)
    {
        aux = aux -> next;
    }
    final[0] = aux -> valor1;
    final[1] = aux -> valor2;
    return final;
}

int *valor_pos(Lista *l, int pos)
{
    int *posi = (int*)malloc(sizeof(int) * 2);
    Nodol *aux;
    if(pos > l -> largo)
    {
        posi[0] = -1;
        posi[1] = -1;
    }
    else if(pos == 0)
    {
        posi = valor_inicial(l);
    }
    else
    {
        aux = l -> inicio;
        for(int i = 1; i <= pos; i++)
        {
            aux = aux -> next;
        }
        posi[0] = aux -> valor1;    
        posi[1] = aux -> valor2;    
    }
    return posi;
}

int *eliminar_inicio(Lista *l)
{
    int *inicio = (int*)malloc(sizeof(int) * 2);
    if(isEmptyL(l) == 1)
    {
        printf("lista vacia");
        inicio[0] = -1;
        inicio[1] = -1;
        return inicio;
    }
    else
    {
        Nodol *aux = l -> inicio;
        l -> inicio = aux -> next;
        inicio[0] = aux -> valor1;
        inicio[1] = aux -> valor2;
        free(aux);
        return inicio;
    }
}

int *eliminar_final(Lista *l)
{
    int *final = (int*)malloc(sizeof(int) * 2);
    if(isEmptyL(l) == 1)
    {
        printf("lista vacia");
        final[0] = -1;
        final[1] = -1;
        return final;
    }
    else
    {
        Nodol *aux1 = l -> inicio;
        Nodol *aux2 = l -> inicio -> next;
        while(aux2 -> next != NULL)
        {
            aux1 = aux1 -> next;
            aux2 = aux2 -> next;
        }
        final[0] = aux2 -> valor1;
        final[1] = aux2 -> valor2;
        free(aux2);
        return final;
    }
}

int *eliminar_pos(Lista *l, int pos)
{
    int *posi = (int*)malloc(sizeof(int) * 2);
    Nodol *aux1, *aux2;   
    if(pos > l -> largo || isEmptyL(l) == 1)
    {
        printf("Posicion no valida");
        posi[0] = -1;
        posi[1] = -1;
        return posi;
    }
    else
    {
        aux1 = l -> inicio;
        aux2 = l -> inicio -> next;
        for(int i = 1; i < pos-1; i++)
        {
            aux1 = aux1 -> next;
            aux2 = aux2 -> next;
        }
        aux1 -> next = aux2 -> next;
        posi[0] = aux2 -> valor1;
        posi[1] = aux2 -> valor2;
        free(aux2);
        l -> largo -= 1;
    }
    return posi;
}