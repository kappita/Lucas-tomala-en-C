typedef struct nodol
{
    Pila *valor;
    struct nodol *next;
}Nodol;

typedef struct lista
{
    Nodol *inicio;
    int largo;
}Lista;

Nodol *crear_nodo(Pila valor);
Lista *crear_lista();
int isEmptyL(Lista *l);
void insertar_inicio(Lista *l, Pila valor);
void insertar_final(Lista *l, Pila valor);
void insertar_pos(Lista *l, int pos, Pila valor);
Pila valor_inicial(Lista *l);
Pila valor_final(Lista *l);
Pila valor_pos(Lista *l, int pos);
int eliminar_pos(Lista *l, int pos);
int eliminar_inicio(Lista *l);
int eliminar_final(Lista *l);