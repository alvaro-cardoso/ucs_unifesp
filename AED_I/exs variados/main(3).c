#include <stdio.h>
#include <stdlib.h>
#include "lista-ponteiro-dupla.h"

int main()
{
TLista *lista;
    TItem item;

    lista = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(lista);
    item.Chave = 1;
    TLista_Insere(lista,TLista_Retorna(lista,1),item);
    printf("\n");
    TLista_Imprime(lista);
    item.Chave = 2;
    TLista_Insere(lista,TLista_Retorna(lista,2),item);
    printf("\n");
    TLista_Imprime(lista);
    item.Chave = 3;
    TLista_Insere(lista,TLista_Retorna(lista,2),item);
    printf("\n");
    TLista_Imprime(lista);
    TLista_Retira(lista,TLista_Retorna(lista,2),&item);
    printf("\n");
    TLista_Imprime(lista);
    free(lista);

    return 0;
}
