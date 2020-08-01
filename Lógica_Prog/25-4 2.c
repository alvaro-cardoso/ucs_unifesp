#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{

    int n, i, t = 0, s;

    printf("digite num de linhas\n");
    scanf("%d", &n);
    if (n >= 0)
    {
        for (i = 1; i <= n; i++)
        {
            for (s = 1; s <= i; s++)
            {
                t++;
                printf("%d ", t);
            }
            printf("\n");
        }
    }
    else
        printf("num invalido");
}