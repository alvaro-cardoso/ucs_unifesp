#include <stdio.h>
#include <string.h>
#include <math.h>

void main()
{

    int c, l, i, j, soma = 0, cont = 0, n = 0;
    printf("digite o num de linhas e colunas da sua matriz quadrada\n");
    scanf("%d", &l);
    c = l;
    int vetl[c], vetc[c], vetd[c], mat[l][c];

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("digite o num\n");
            scanf("%d", &mat[i][j]);
        }
    }
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            soma = soma + mat[i][j];
        }
        vetl[cont] = soma;
        cont++;
        soma = 0;
    }
    cont = 0;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            soma = soma + mat[j][i];
        }
        vetc[cont] = soma;
        cont++;
        soma = 0;
    }
    cont = 0;
    for (i = 0; i < l; i++)
    {
        soma = soma + mat[i][i];
    }
    vetd[cont] = soma;

    soma = 0;
    cont++;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (j == (c - 1 - i))
            {
                soma = soma + mat[i][j];
            }
        }
    }
    vetd[cont] = soma;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (vetl[i] == vetc[j])
                n = 1;
        }
    }
    for (i = 0; i < 2; i++)
    {
        if (vetl[i] == vetd[i])
            n = 1;
        else
            n = 0;
    }
    if (n == 1)
        printf("a matriz é um quadrado mágico");
    else if (n != 1)
        printf("a matriz não é um quadrado mágico");
}