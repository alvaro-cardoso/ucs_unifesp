#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Tpilha.c"

int main () {
    int i;
    char frase[50], tamanho;
    TItem item;
    TPilha *pilha,*pilhaaux;

    pilha = (TPilha *) malloc(sizeof(TPilha));
    pilhaaux = (TPilha *) malloc(sizeof(TPilha));
    TPilha_Inicia(pilha);
    TPilha_Inicia(pilhaaux);

    fgets(frase,sizeof(frase),stdin);
    tamanho=strlen(frase);

    for (i=0;i<=tamanho;i++){
        item.Chave = frase[i];
        TPilha_Empilha(pilha,item);}

    while((! TPilha_EhVazia(pilha))&&(item.Chave!='v')){
            TPilha_Desempilha(pilha,&item);
            if(item.Chave!='v')
            TPilha_Empilha(pilhaaux,item);}

    while(! TPilha_EhVazia(pilhaaux)){
      TPilha_Desempilha(pilhaaux,&item);
      TPilha_Empilha(pilha,item);
      }

    while(! TPilha_EhVazia(pilha)){
            TPilha_Desempilha(pilha,&item);
            printf("%c",item.Chave);
            }
free(pilha);
free(pilhaaux);
return 0;

}
