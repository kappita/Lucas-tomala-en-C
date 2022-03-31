#include <stdio.h>

FILE *abrir_archivo(char nombre_archivo[50], char *modo)
{
    FILE *fp = fopen(nombre_archivo, modo);

    if(fp == NULL)
    {
        printf("Nombre incorrecto o el archivo no existe");
        return;
    }

    printf("Archivo abierto correctamente");

    return fp;
}

void verificacion(FILE *archivo)
{
    if(archivo == NULL)
    {
        printf("Nombre incorrecto o el archivo no existe\n");
        return;
    }

    printf("Archivo abierto correctamente\n");
}

int main(int argc, char *argv[])
{
    FILE *fp;

    fp = abrir_archivo(argv[2], "r");

    fclose(fp);
}