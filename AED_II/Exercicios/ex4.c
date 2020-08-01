#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define max 10000

typedef struct
{
    char palavra[100];
    char trad[100];
} word;

typedef struct TNo
{
    struct TNo *nxt;
    word Frase;
} TNo;

typedef struct
{
    int m;
    TNo **table;
} THash;

void Hash_Insert(word letra, THash *hash)
{
    int i, ind = strlen(letra.palavra) % hash->m;
    TNo *nw_No = malloc(sizeof(TNo));

    nw_No->Frase = letra;
    nw_No->nxt = hash->table[ind];
    hash->table[ind] = nw_No;
}

int Hash_Search(char temp2[], THash *hash)
{
    int i, ind = strlen(temp2) % hash->m;
    TNo *nw_No;

    nw_No = hash->table[ind];

    while (nw_No != NULL)
    {
        if (strcmp(temp2, nw_No->Frase.palavra) == 0)
        {
            fputs(nw_No->Frase.trad, stdout);
            return 0;
        }
        nw_No = nw_No->nxt;
    }

    fputs(temp2, stdout);
    return 1;
}

int main()
{
    int m, n, j, i, x, k = 0, linha[max];
    word temp[max], aux2[max], frase[max];
    char *temp2[10000];
    THash hash;

    hash.m = 103;
    hash.table = calloc(hash.m, sizeof(TNo *));

    scanf("%d %d ", &m, &n);

    for (i = 0; i < m; i++)
    {
        fgets(temp[i].palavra, 100, stdin);
        temp[i].palavra[strlen(temp[i].palavra) - 1] = '\0';
        fgets(temp[i].trad, 100, stdin);
        temp[i].trad[strlen(temp[i].trad) - 1] = '\0';
        Hash_Insert(temp[i], &hash);
    }

    for (i = 0; i < n; i++)
    {
        fgets(frase[i].palavra, 100, stdin);
        strcpy(aux2[i].palavra, frase[i].palavra);
    }

    j = 0;

    for (i = 0; i < n; i++)
    {
        char *tkn = strtok(aux2[i].palavra, " \n");
        while (tkn != NULL)
        {
            temp2[j] = tkn;
            tkn = strtok(NULL, " \n");
            j++;
        }
        for (x = k; x < j; x++)
        {
            Hash_Search(temp2[x], &hash);
            printf(" ");
        }
        printf("\n");
        k = j;
    }

    return 0;
}