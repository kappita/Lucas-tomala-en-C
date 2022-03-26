#include <stdio.h>

void main()
{
    long long int i, j, num1, num2, resultado = 0;

    scanf("%llu %llu", &num1, &num2);

    for(i = 1; i < num2; i++)
    {
        if (i == 1)
        {
            for(j = 0; j < num1; j++)
            {
                resultado += num1;
            }
        }
        else
        {
            for(j = 1; j < num1; j++)
            {
                resultado += resultado;
            }
        }
    }

    printf("%llu", resultado);
}