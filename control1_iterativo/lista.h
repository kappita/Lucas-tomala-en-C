typedef struct nodol
{
    int valor1;
    int valor2;
    struct nodol *next;
}Nodol;

typedef struct lista
{
    Nodol *inicio;
    int largo;
}Lista;

Nodol *crear_nodo(int *valor);
Lista *crear_lista();
int isEmptyL(Lista *l);
void insertar_inicio(Lista *l, int *valor);
void insertar_final(Lista *l, int *valor);
void insertar_pos(Lista *l, int pos, int *valor);
int *valor_inicial(Lista *l);
int *valor_final(Lista *l);
int *valor_pos(Lista *l, int pos);
int *eliminar_pos(Lista *l, int pos);
int *eliminar_inicio(Lista *l);
int *eliminar_final(Lista *l);