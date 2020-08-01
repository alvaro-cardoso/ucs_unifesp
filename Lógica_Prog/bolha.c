#include <stdio.h>

// func troca
int bolha(int v[], int n)
{
    int i, j, t, v1[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i] <= v[(j)])
            {
                t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }
    }
    printf(" \nresultado:\n");
    for (i = 0; i < n; i++)
        printf(" \n%d\n", v[i]);
    return v[i];
}
// programa
int main()
{
    int n = 0, i, v[n];
    printf("digite o tamanho do vetor\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("digite o num\n");
        scanf("%d", &v[i]);
    }
    bolha(v, n);
}