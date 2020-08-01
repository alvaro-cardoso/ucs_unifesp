#include <stdio.h>
#include <math.h>

int main()
{

    int vet[50], media = 0, cont = 0, porc, i;
    char p = '%';

    for (i = 0; i < 50; i++)
    {
        printf("digite o num do dado\n");
        scanf("%d", &vet[i]);
        media = media + vet[i];
    }
    media = media / 50;
    for (i = 0; i < 50; i++)
    {
        if (vet[i] == 6)
            cont++;
        if (vet[i] > media)
            printf("%d eh maior que a media de lancamentos\n", vet[i]);
    }
    porc = (cont * 100) / 50;
    printf("a porcentagem de lancamento 6 eh:\n%d %c", porc, p);
}