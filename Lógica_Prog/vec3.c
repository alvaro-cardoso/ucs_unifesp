#include <stdio.h>
#include <math.h>

int main()
{
    int v[30], n, i, s = 0;
    printf("digite o num a ser proc");
    scanf("%d", &n);
    for (i = 0; i < 30; i++)
    {
        printf("digite num\n");
        scanf("%d", &v[i]);
    }
    for (i = 0; i < 30; i++)
    {
        if (v[i] == n)
        {
            s++;
            printf("o num aparece na posição %d\n", i);
        }
    }
    printf("o num aparece %d\n", s);
}