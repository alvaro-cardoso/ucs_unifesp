#include <stdio.h>
#include <stdlib.h>
#include "Tpilha.h"

int main()
{
    char palavra[30];
    int tam;

    fgets(palavra,sizeof(palavra),stdin);
    tam = strlen(palavra);
    palavra[tam-1] = '\0';
    if(palindromo(palavra))
       printf("Eh palindromo");
    else
       printf("Nao eh palindromo");

    return 0;
}

int palindromo(char *palavra){
   TPilha *pilha;
   TItem item;
   int i,j,tam;

   pilha = (TPilha *) malloc(sizeof(TPilha));
   TPilha_Inicia(pilha);

   tam = strlen(palavra);
   for(i=0;i<tam/2;i++){
      item.Chave = palavra[i];
      TPilha_Empilha(pilha,item);
   }
   if(tam%2 != 0)
      i++;
   for(j=i;j<tam;j++){
      TPilha_Desempilha(pilha,&item);
      if(item.Chave!=palavra[j]){
         while(!TPilha_EhVazia(pilha))
            TPilha_Desempilha(pilha,&item);
         free(pilha);
         return 0;
      }
   }
   free(pilha);
   return 1;
}
