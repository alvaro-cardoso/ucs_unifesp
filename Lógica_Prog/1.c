#include <stdio.h>
#include <math.h>

void main()
{
    int n, n1, n2, n3, n4;
    printf("digite o numero");
    scanf("%d", &n);
    n1 = (n / 100);
    n2 = (n % 100);
    n3 = sqrt(n);
    n4 = n1 + n2;
    if (n4 == n3)
        printf("a raiz de %d eh igual a soma de suas dezenas", n);
    else
        printf("a raiz de %d eh diferente da soma de suas dezenas", n);
}