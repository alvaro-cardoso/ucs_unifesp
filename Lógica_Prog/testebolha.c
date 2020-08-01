#include <stdio.h>
// teste
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
    int n = 23, i, v[] = {64, -3, 0, 7, 2343, 3, -5, 2, 34, 14, 34, 25, 12, 22, 11, 90, 27, 123, -39, 27, 23, 13, 1273};
    bolha(v, n);
}