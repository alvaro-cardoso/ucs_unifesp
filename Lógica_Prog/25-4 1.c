#include <stdio.h>
#include <stdlib.h>
void main()
{

    int i = 0, n1, n2;
    srand(time(NULL));
    n1 = rand() % 10;
    n2 += n2;
    while (n1 != n2)
    {
        printf("digite o num");
        scanf("\n%d", &n2);
        if (n2 > n1)
        {
            printf("MENOR\n");
        }
        else if (n2 < n1)
        {
            printf("MAIOR\n");
        }
        i++;
    }
    printf("\n%d tentativa(s)", i);
}