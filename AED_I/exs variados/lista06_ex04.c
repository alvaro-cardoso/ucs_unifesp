#include <stdio.h>
#include <stdlib.h>
#include "TLista.h"

int main()
{
    TLista *lista, *lista_aux;
    TItem x;
    int tam, i;

    lista = (TLista *) malloc(sizeof(TLista));
    lista_aux = (TLista *) malloc(sizeof(TLista));

    TLista_Inicia(lista);
    TLista_Inicia(lista_aux);

    x.Chave = 'a';
    TLista_InsereUltimo(lista,x);
    x.Chave = 'b';
    TLista_InsereUltimo(lista,x);
    x.Chave = 'c';
    TLista_InsereUltimo(lista,x);
    x.Chave = 'v';
    TLista_InsereUltimo(lista,x);
    x.Chave = 'd';
    TLista_InsereUltimo(lista,x);
    x.Chave = 'e';
    TLista_InsereUltimo(lista,x);
    TLista_Imprime(lista);

    tam = TLista_Tamanho(lista);
    for(i=0;i<tam;i++){
       TLista_RetiraPrimeiro(lista,&x);
       if(x.Chave != 'v')
          TLista_InsereUltimo(lista_aux,x);
    }
    printf("\n\n");
    TLista_Imprime(lista_aux);

    while(!TLista_EhVazia(lista_aux))
       TLista_RetiraPrimeiro(lista_aux,&x);

    free(lista);
    free(lista_aux);

    return 0;
}
