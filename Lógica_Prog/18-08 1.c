#include <stdio.h>
#include <math.h>

void main()
{
    int n, i, soma = 0;
    printf("digite um numero\n");
    scanf("%d", &n);
    if (n > 0)
    {
        for (i = 1; i < n; i++)
            if (n % i == 0)
                soma = soma + i;
        if (soma == n)
            printf("o numero %d eh perfeito", n);
        else if (soma != n)
            printf("o numero %d nao eh perfeito", n);
    }
    else
        printf("o num digitado eh menor que 0");
}
