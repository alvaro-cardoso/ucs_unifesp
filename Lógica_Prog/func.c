#include <stdio.h>
#include <math.h>
#include <string.h>

int menor(int v[], int n)
{
    int i, min;
    min = n;
    for (i = 0; i < 10; i++)
    {
        if (min >= v[i])
            min = v[i];
        else if (min < v[i])
            min = min;
    }
    return min;
}

void main()
{

    int v[10] = {1, 5, 6, 8, 11, 45, 68, 89, 72, 0};
    int m, n = 10;
    m = menor(v, n);
    printf("\no menor elemento eh %d", m);
}