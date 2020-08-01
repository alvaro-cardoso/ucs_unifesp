#include <stdio.h>
#include <math.h>

int main()
{
    int i, v1[10], v2[10], v3[10];
    for (i = 0; i < 10; i++)
    {
        printf("digite num ");
        scanf("%d", &v1[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("digite num ");
        scanf("%d", &v2[i]);
    }
    for (i = 0; i < 10; i++)
    {
        v3[i] = v1[i] * v2[i];
        printf("%d\n", v3[i]);
    }
}