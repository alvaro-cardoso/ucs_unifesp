#include <stdio.h>
#include <stdlib.h>
#include "TPilhaFila.h"

int main()
{
    char palavra[30];
    int tam,i;
    TItem item;

    TFila *fila;
    fila = (TFila *) malloc(sizeof(TFila));
    TFila_Inicia(fila);

    printf("Digite uma palavra:");
    fgets(palavra,sizeof(palavra),stdin);
    tam = strlen(palavra);

    for(i=0;i<tam-1;i++){
       item.Chave = palavra[i];
       TFila_Enfileira(fila,item);
    }
    inverte_fila(fila);
    while(!TFila_EhVazia(fila)){
       TFila_Desenfileira(fila,&item);
       printf("%c",item.Chave);
    }
    free(fila);
}

void inverte_fila(TFila *fila){
   TPilha *pilha;
   TItem item;
   pilha = (TPilha *) malloc(sizeof(TPilha));
   TPilha_Inicia(pilha);

   while(!TFila_EhVazia(fila)){
      TFila_Desenfileira(fila,&item);
      TPilha_Empilha(pilha,item);
   }
   while(!TPilha_EhVazia(pilha)){
      TPilha_Desempilha(pilha,&item);
      TFila_Enfileira(fila,item);
   }
   free(pilha);
}
