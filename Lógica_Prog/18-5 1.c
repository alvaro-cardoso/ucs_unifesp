#include <stdio.h>
#include <string.h>

int main()
{

    char strA[10], strB[10], strC[20];
    int i, j, k, t, cont = 0;

    printf("digite a primeira palavra\n");
    gets(strA);
    printf("digite a segunda palavra\n");
    gets(strB);
    t = (strlen(strA));
    k = (strlen(strB));
    if (t == k)
    {
        for (j = 0; j < t; j++)
        {
            strC[cont] = strA[j];
            strC[(cont + 1)] = strB[j];
            cont += 2;
        }
    }
    if (t > k)
    {
        for (j = 0; j < k; j++)
        {
            strC[cont] = strA[j];
            strC[(cont + 1)] = strB[j];
            cont += 2;
        }

        j = k;
        for (i = (cont); i < (k + t); i++)
        {
            strC[i] = strA[j];
            j++;
        }
    }
    cont = 0;
    if (k > t)
    {
        for (j = 0; j < t; j++)
        {
            strC[cont] = strA[j];
            strC[(cont + 1)] = strB[j];
            cont += 2;
        }

        j = t;
        for (i = (cont); i < (k + t); i++)
        {
            strC[i] = strB[j];
            j++;
        }
    }
    strC[(k + t)] = '\0';
    printf("%s\n%s\n%s\n", strA, strB, strC);
}
