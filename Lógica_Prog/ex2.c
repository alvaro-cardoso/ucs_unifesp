#include <stdio.h>
#include <math.h>

void main()
{
    int N, i, H = 0;
    printf("digite um num ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        H = H + 10;
    }
    printf("o resultado final eh %d", H);
}