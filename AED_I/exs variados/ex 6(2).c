#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Tpilha.c"

int main (){
    char TFrase[50],Aux[50];
    int tam,i;
    TItem item;
    TPilha *pilha1;

    pilha1 = (TPilha *) malloc(sizeof(TPilha));
    TPilha_Inicia(pilha1);

    fgets(TFrase,sizeof(TFrase),stdin);
    tam = strlen(TFrase);
    TFrase[tam-1] = '\0';

    for (i=0;i<=tam+1;i++){

        item.Chave = TFrase[i];
        if ((item.Chave!=' ')&&(item.Chave!= '\0')){
            TPilha_Empilha(pilha1,item);}

        else {while(! TPilha_EhVazia(pilha1)){
            TPilha_Desempilha(pilha1,&item);
            printf("%c",item.Chave);
            }printf(" ");}
   }
   free(pilha1);
return 0;
}





