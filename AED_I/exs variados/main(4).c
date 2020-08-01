#include <stdio.h>
#include <stdlib.h>
#include "TLista.h"

int main()
{
    TLista *lista;

    lista = (TLista *) malloc(sizeof(TLista));

    TItem item;

    TLista_Inicia(lista);
    item.Chave = 1;
    TLista_Insere(lista,0,item);
    item.Chave = 2;
    TLista_Insere(lista,1,item);
    item.Chave = 3;
    TLista_Insere(lista,2,item);
    printf("\n\n");
    TLista_Imprime(lista);
    TLista_Retira(lista,1,&item);
    printf("\n\n");
    TLista_Imprime(lista);

    while(!TLista_EhVazia(lista))
       TLista_Retira(lista,0,&item);

    free(lista);

    return 0;
}
