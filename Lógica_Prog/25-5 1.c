#include <stdio.h>
#include <string.h>
#include <math.h>
#define l 4
#define c 3

void main()
{

    int mat1[l][c], i, j, k = 0, cont = 1;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("digite o num da matriz\n");
            scanf("%d", &mat1[i][j]);
        }
    }

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            k = k + mat1[i][j];
        }
        printf("soma linha %d : %d\n", cont, k);
        cont++;
        k = 0;
    }

    cont = 1;
    for (i = 0; i < l - 1; i++)
    {
        for (j = 0; j < c; j++)
        {
            k = k + mat1[j][i];
        }
        printf("soma coluna %d : %d\n", cont, k);
        cont++;
        k = 0;
    }
}