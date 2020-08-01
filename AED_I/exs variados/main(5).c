#include <stdio.h>
#include <stdlib.h>
#include "TFila-ponteiro.h"

int main()
{
    TFila *pFila;
    TItem item;

    pFila = (TFila *) malloc(sizeof(TFila));

    TFila_Inicia(pFila);
    item.Chave = 1;
    TFila_Enfileira(pFila,item);
    item.Chave = 2;
    TFila_Enfileira(pFila,item);
    item.Chave = 3;
    TFila_Enfileira(pFila,item);
    TFila_Imprime(pFila);
    TFila_Desenfileira(pFila,&item);
    printf("\n\n");
    TFila_Imprime(pFila);
    TFila_Desenfileira(pFila,&item);
    printf("\n\n");
    TFila_Imprime(pFila);
    item.Chave = 8;
    TFila_Enfileira(pFila,item);
    printf("\n\n");
    TFila_Imprime(pFila);

    while(!TFila_EhVazia(pFila))
        TFila_Desenfileira(pFila,&item);

    free(pFila);

    return 0;
}
