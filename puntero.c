#include <stdio.h>

void puntero(int *a, int *b)
{
    int i  = 10;

    for(i; i > 0; i--)
    {
        *b += *a;
    }
}

void main()
{
    int a = 2, b = 6;

    printf("este es a:%d este es b:%d\n", a, b);

    puntero(&a, &b);

    printf("este es a:%d este es b:%d", a, b);
}