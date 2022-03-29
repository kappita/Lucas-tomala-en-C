#include <stdio.h>

FILE *abrir_archivo(char nombre_archivo[50], char *modo)
{
    FILE *fp = fopen(nombre_archivo, modo);

    if(fp == NULL)
    {
        printf("Nombre incorrecto o el archivo no existe\n");
        return NULL;
    }

    printf("Archivo abierto correctamente\n");

    return fp;
}

void mostrar_contenido_archivo(FILE *fp)
{
    char caracter;
    
    while((caracter = getc(fp)) != EOF)
    {
        printf("%c", caracter);
    }
}

int main(int argc, char *argv[])
{
    FILE *fp;

    fp = abrir_archivo(argv[2], "r");

    mostrar_contenido_archivo(fp);
}