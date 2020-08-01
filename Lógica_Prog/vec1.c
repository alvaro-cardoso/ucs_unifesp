#include <stdio.h>
#include <math.h>

int main()
{
    int n, i = 0;
    printf("digite a qnt de num");
    scanf("%d", &n);
    int vetor[n];
    for (i = 0; i < n; i++)
    {
        printf("digite o num");
        scanf("%d", &vetor[i]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        printf("\nO valor armazenado na posicao %d eh %d\n", i, vetor[i]);
    }
}