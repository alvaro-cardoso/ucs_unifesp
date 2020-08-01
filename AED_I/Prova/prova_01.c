#include <stdio.h>
#include <stdlib.h>
#include "TPilha.h"

int main()
{
    char palavra[30];
    int tam,i;
    TItem item;

    TPilha *pilha;
    pilha = (TPilha *) malloc(sizeof(TPilha));
    TPilha_Inicia(pilha);

    printf("Digite uma palavra:");
    fgets(palavra,sizeof(palavra),stdin);
    tam = strlen(palavra);

    for(i=0;i<tam-1;i++){
       item.Chave = palavra[i];
       TPilha_Empilha(pilha,item);
    }
    while(!TPilha_EhVazia(pilha)){
       TPilha_Desempilha(pilha,&item);
       printf("%c",item.Chave);
    }

    free(pilha);

    return 0;
}
