#include <stdlib.h>
#include <stdio.h>
#define MAX 1000

int main()
{

    int vet[MAX], aux, num, i, j, cont = 0;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d", &vet[i]);
    }
    for (i = num - 1; i > 0; i--)
    {
        for (j = 0; j < num - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = aux;
                cont++;
            }
        }
    }
    if (cont % 2 != 0)
    {
        printf("Marcelo");
    }
    else
        printf("Carlos");
    return 0;
}
