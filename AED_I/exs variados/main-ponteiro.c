#include <stdio.h>
#include <stdlib.h>
#include "TLista-ponteiro.h"

int main()
{
    TLista *lista;
    TItem item;

    lista = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(lista);
    item.Chave = 1;
    TLista_Insere(lista,TLista_Retorna(lista,0),item);
    item.Chave = 2;
    TLista_Insere(lista,TLista_Retorna(lista,0),item);
    item.Chave = 3;
    TLista_Insere(lista,TLista_Retorna(lista,0),item);
    printf("\n");
    TLista_Imprime(lista);
    TLista_Retira(lista,TLista_Retorna(lista,2),&item);
    printf("\n");
    TLista_Imprime(lista);
    TLista_Retira(lista,TLista_Retorna(lista,0),&item);
    printf("\n");
    TLista_Imprime(lista);
    while(!TLista_EhVazia(lista))
        TLista_Retira(lista,TLista_Retorna(lista,0),&item);
    free(lista);
    return 0;
}
