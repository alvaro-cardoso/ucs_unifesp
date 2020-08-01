#include <stdio.h>

int main()
{

    int cont = 0, vetX[10], vetY[10], vetI[20], vetU[20], i, j;

    for (i = 0; i < 10; i++)
    {
        printf("entre com valores pro seu vetor X \n");
        scanf("%d", &vetX[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("entre com valores pro seu vetor Y \n");
        scanf("%d", &vetY[i]);
    }
    printf("vet inicio:\n X   Y\n");
    for (i = 0; i < 10; i++)
        printf(" %d   %d\n", vetX[i], vetY[i]);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (vetX[i] == vetY[j] && vetX[i] != vetX[(j + 1)])
            {
                vetI[cont] = vetX[i];
                cont++;
            }
            else if (vetX[i] == vetY[j] && vetX[i] == vetX[(j + 1)])
                cont = cont;
        }
    }
    printf("Int:\n");
    for (i = 0; i < 10; i++)
        printf(" %d \n", vetI[i]);
}