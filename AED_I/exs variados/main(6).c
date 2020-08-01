#include <stdio.h>
#include <stdlib.h>
#include "Tpilha.h"

int main()
{
    TPilha *pilha1, *pilha2;
    TItem item;

    pilha1 = (TPilha *) malloc(sizeof(TPilha));

    pilha2 = (TPilha *) malloc(sizeof(TPilha));

    TPilha_Inicia(pilha1);

    TPilha_Inicia(pilha2);

    item.Chave = 1;
    TPilha_Empilha(pilha1,item);
    item.Chave = 2;
    TPilha_Empilha(pilha1,item);
    item.Chave = 3;
    TPilha_Empilha(pilha1,item);

    TPilha_ImprimePilha(pilha1);

    TPilha_Desempilha(pilha1,&item);

    printf("Item desempilhado: %d\n",item.Chave);

    TPilha_ImprimePilha(pilha1);

    return 0;
}
