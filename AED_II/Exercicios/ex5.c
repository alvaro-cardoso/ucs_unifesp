#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10000

typedef struct
{
    char RNA[max];
    char amin;
} TFita;

typedef struct TNo
{
    struct TNo *nxt;
    TFita fita;
} TNo;

typedef struct
{
    int m;
    TNo **table;
} THash;

void Hash_Insert(TFita fita, THash *hash)
{
    int i, ind = (fita.RNA[0] + fita.RNA[1] + fita.RNA[2]) % hash->m;
    TNo *nw_No = malloc(sizeof(TNo));

    nw_No->fita = fita;
    nw_No->nxt = hash->table[ind];
    hash->table[ind] = nw_No;
}

int Hash_Search(char RNA[], THash *hash)
{
    int ind = (RNA[0] + RNA[1] + RNA[2]) % hash->m;
    ;
    TNo *nw_No;

    nw_No = hash->table[ind];
    while (nw_No != NULL)
    {
        if (strncmp(nw_No->fita.RNA, RNA, 3) == 0)
        {
            printf("%c", nw_No->fita.amin);
            return 0;
        }
        nw_No = nw_No->nxt;
    }

    fputs("*", stdout);
    return 1;
}

int main()
{
    int m, n, i, j = 0, k = 0, o = 0, cont;
    TFita fita[100], fita_dic, aux[100];
    THash hash;

    hash.m = 103;
    hash.table = calloc(hash.m, sizeof(TNo *));

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", fita_dic.RNA);
        scanf("\t%c", &fita_dic.amin);
        Hash_Insert(fita_dic, &hash);
    }

    scanf("%d\n", &m);

    for (i = 0; i < m; i++)
    {

        while ((fita[i].RNA[j] = getchar()) != '\n')
        {
            j++;
        }
        fita[i].RNA[j] = '\0';
        j = 0;
        cont = 0;
        while (fita[i].RNA[cont] != '\0')
        {
            for (k = 0; k < 3; k++)
            {
                aux[i].RNA[k] = fita[i].RNA[o + k];
                cont++;
            }
            Hash_Search(aux[i].RNA, &hash);
            o += 3;
        }
        o = 0;
        if (m - 1 > i)
            printf("\n");
    }

    return 0;
}