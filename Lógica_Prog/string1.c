#include <stdio.h>
#include <string.h>

int main()
{

    char strB[100], strA[100];
    int t, i, j, cont = 0;
    printf("digite a frase\n");
    scanf("%s", strA);
    t = strlen(strA);
    for (i = (t - 1); i >= 0; i--)
    {
        strB[cont] = strA[i];
        cont++;
    }

    strB[t] = '\0';
    j = strcmp(strA, strB);
    if (j == 0)
        printf("a palavra %s eh um palindromo", strA);
    else
        printf("a palavra %s n eh um palindromo", strA);
}