#include <stdio.h>

int main()
{

    int vetor[50], repetido = 0, diferente = 0, i, j;
    for (i = 0; i < 5; i++)
    {
        printf("entre com valores pro seu vetor \n");
        scanf("%d", &vetor[i]);
    }
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {

            if (vetor[i] == vetor[j])
            {
                repetido = 1;
            }
        }
        if (repetido != 1)
        {
            diferente++;
        }
        repetido = 0;
    }

    printf("existem %d numeros diferente no vetor", diferente);
}