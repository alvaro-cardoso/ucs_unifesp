#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"TFila.c"

int main (){

    char TFrase[50];
    TFila *pFila,*pFilaaux;
    TItem item;
    int tam,i;

    pFila = (TFila *) malloc(sizeof(TFila));
    TFila_Inicia(pFila);

    pFilaaux = (TFila *) malloc(sizeof(TFila));
    TFila_Inicia(pFilaaux);

    fgets(TFrase,sizeof(TFrase),stdin);
    tam=strlen(TFrase);
    TFrase[tam-1] = '\0';


    for (i=0;i<tam;i++){
        item.Chave = TFrase[i];
    TFila_Enfileira(pFila,item);}


   while((! TFila_EhVazia(pFila))&&(item.Chave!='v')){
        TFila_Desenfileira(pFila,&item);
        if(item.Chave!='v')
        TFila_Enfileira(pFilaaux,item);}


   while(! TFila_EhVazia(pFilaaux)){
            TFila_Desenfileira(pFilaaux,&item);
            printf("%c",item.Chave);
            }


      while(! TFila_EhVazia(pFila)){
            TFila_Desenfileira(pFila,&item);
            printf("%c",item.Chave);
            }

            free (pFila);
            free (pFilaaux);
            return 0;
}
