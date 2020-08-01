#include <stdio.h>
#include <stdlib.h>
#include "TFila.h"

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

    remove_v(fila);

    while(!TFila_EhVazia(fila)){

    }

    free(fila);

    return 0;
}

void remove_v(TFila *fila){
   TFila *filaAux;
   TItem item;
   filaAux = (TFila *) malloc(sizeof(TFila));
   TFila_Inicia(filaAux);

   while(!TFila_EhVazia(fila)){
      TFila_Desenfileira(fila,&item);
      if(item.Chave!='v')
         TFila_Enfileira(filaAux,item);
   }
   while(!TFila_EhVazia(filaAux)){
      TFila_Desenfileira(filaAux,&item);
      TFila_Enfileira(fila,item);
   }
}
