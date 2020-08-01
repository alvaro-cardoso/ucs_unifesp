#include <stdio.h>
#include <math.h>

void main()
{
    float i, s = 1, soma = 0;
    for (i = 1; i <= 99; i = i + 2)
    {
        soma = soma + (i / s);
        s++;
    }
    printf("o valor da soma eh %.2f", soma);
}