#include <stdio.h>
#include <math.h>

int main()
{

    int i, j, vetA[10], vetB[10], vetC[10];

    for (i = 0; i < 10; i++)
    {
        printf("entre com valores pro seu vetor \n");
        scanf("%d", &vetA[i]);
    }
    printf("vet inicio:\n A \n");
    for (i = 0; i < 10; i++)
        printf(" %d \n", vetA[i]);
    for (i = 0; i < 10; i = i + 2)
    {
        vetB[(i + 1)] = vetA[i];
    }
    for (i = 1; i < 10; i = i + 2)
    {
        vetB[(i - 1)] = vetA[i];
    }
    printf("vet fim:\n A \n");
    for (i = 0; i < 10; i++)
        printf(" %d \n", vetB[i]);
}