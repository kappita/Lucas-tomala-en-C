#include <stdio.h>

struct producto
{
    char nombre[50];
    int precio;
    int cantidad;
};

int main()
{
    struct producto prod, productos[10];
    int i, opcion = 1;

    for(i = 0; i < 10; i++)
    {
        strcpy(productos[i].nombre, "x");
        productos[i].precio = 0;
        productos[i].cantidad = 0;
    }

    while((opcion == 1 || 2 || 3) && (opcion != 4))
    {
        printf("1) Dar de alta un producto nuevo.\n2) Buscar un producto por su nombre.\n3) Modificar el stock y precio de un producto dado.\n4) salir\n");

        printf("\nElija una opcion:\n");
        scanf("%d", &opcion);

        if(opcion == 1)
        {

        }
        else if(opcion == 2)
        {

        }
        else if(opcion == 3)
        {

        }
    }   
    return 0;
}