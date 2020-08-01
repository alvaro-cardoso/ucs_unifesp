#include <stdio.h>

void main()
{
    float n, n2, n3, menor, meio, maior;
    maior = 0, meio = 0, menor = 0;
    printf("digite o primeiro numero");
    scanf("%f", &n);
    printf("digite o segundo numero");
    scanf("%f", &n2);
    printf("digite o terceiro numero");
    scanf("%f", &n3);
    if (n > n2 && n > n3)
    {
        maior = n;
        if (n2 > n3)
            meio = n2, menor = n3;
        else
            meio = n2, menor = n3;
    }
    if (n2 > n && n2 > n3)
    {
        maior = n2;
        if (n > n3)
            meio = n, menor = n3;
        else
            meio = n3, menor = n;
    }
    if (n3 > n && n3 > n2)
    {
        maior = n3;
        if (n > n2)
            meio = n, menor = n2;
        else
            meio = n2, menor = n;
    }
    printf("%.2f %.2f %.2f", maior, meio, menor);
}