#include <stdio.h>
#include <math.h>

void main()
{
    int i, a = 0, b = 0;
    for (i = 1; i <= 5; i++)
    {
        if (a >= 0 && b >= 0)
        {
            printf("digite os numeros\n");
            scanf("%d %d", &a, &b);
            for (a = a; a <= b; a++)
                if (a < b && a % 2 == 0)
                    printf("%d\n", a);
        }
    }
    printf("fim");
}