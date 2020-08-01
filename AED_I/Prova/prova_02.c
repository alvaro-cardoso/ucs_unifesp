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

    remove_v(pilha);

    free(pilha);

    return 0;
}

void remove_v(TPilha *pilha){
   TPilha *pilhaAux;
   TItem item;
   pilhaAux = (TPilha *) malloc(sizeof(TPilha));
   TPilha_Inicia(pilhaAux);

   while(!TPilha_EhVazia(pilha)){
      TPilha_Desempilha(pilha,&item);
      if(item.Chave!='v')
         TPilha_Empilha(pilhaAux,item);
      //else
      //   break;
   }
   while(!TPilha_EhVazia(pilhaAux)){
      TPilha_Desempilha(pilhaAux,&item);
      TPilha_Empilha(pilha,item);
   }

   free(pilhaAux);
}
