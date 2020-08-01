#include <stdio.h>
#include <math.h>

int main()
{

    int i, vetA[10] = {41, 2, 3, 8, 7, 3, 9, 7, 6, 10}, vetB[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11}, vetC[10];

    printf("vet inicio:\n A   B\n");
    for (i = 0; i < 10; i++)
        printf(" %d   %d\n", vetA[i], vetB[i]);
    for (i = 0; i < 10; i++)
    {
        vetC[i] = vetB[i];
        vetB[i] = vetA[i];
    }
    for (i = 0; i < 10; i++)
    {
        vetA[i] = vetC[i];
    }
    printf("vet fim:\n A   B\n");
    for (i = 0; i < 10; i++)
        printf(" %d   %d\n", vetA[i], vetB[i]);
}