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

void escribir_archivo(FILE *arch_e, FILE *arch_s)
{
    char linea[50];

    while(fgets(linea, 50, arch_e) != NULL)
    {
       fputs(linea, arch_s);
    }
}

int main(int argc, char *argv[])
{
    FILE *fp_e = abrir_archivo(argv[2], "r");
    FILE *fp_s = abrir_archivo(argv[3], "w");

    escribir_archivo(fp_e, fp_s);
}
