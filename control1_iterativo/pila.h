typedef struct nodop
{
    int valor1;
    int valor2;
    struct nodop *next;
}Nodop;

typedef struct pila
{
    Nodop *tope;
}Pila;

Pila *crear_pila();
Nodop *crear_nodoP(int valor1, int valor2);
int isEmptyP(Pila *p);
void push(Pila *p, int valor1, int valor2);
int *pop(Pila *p);
int *tope(Pila *p);
void destruirPila(Pila *p);