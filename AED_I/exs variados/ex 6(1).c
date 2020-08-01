#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TFilaPilha.c"

int main (){

    char TFrase[50];
    TFila *pFila;
    TPilha *pilhaaux;
    TItem item;
    int tam,i;

    pFila = (TFila *) malloc(sizeof(TFila));
    TFila_Inicia(pFila);

    pilhaaux = (TPilha *) malloc(sizeof(TPilha));
    TFila_Inicia(pPilha);

    fgets(TFrase,sizeof(TFrase),stdin);
    tam=strlen(TFrase);
    TFrase[tam-1] = '\0';

    for (i=0;i<tam;i++){
        item.Chave = TFrase[i];
    TFila_Enfileira(pFila,item);}

    while(! TFila_EhVazia(pFila)){
        TFila_Desenfileira(pFila,&item);
        TPilha_Empilha(pilhaaux,item);}

    while(! TPilha_EhVazia(pilhaaux)){
      TPilha_Desempilha(pilhaaux,&item);
      TFila_Enfileira(pFilaaux,item);}

      while(! TFila_EhVazia(pFila)){
            TFila_Desenfileira(pFila,&item);
            printf("%c",item.Chave);
            }

            free (pFila);
            free (pilhaaux);
            return 0;
}

