#include <stdio.h>
#include <stdlib.h>
#include "TArvore.h"

int main()
{
    TArvore arvore, arvAux, arvFilho;
    TLista *filhos;
    TDados dado;

    int n_filhos, i;

    //Cria Raiz
    arvore = (TArvore) malloc(sizeof(TNo));
    printf("Raiz: ");
    scanf(" %c",&dado.Chave);
    TArvore_Inicia(arvore,dado);

    printf("No. filhos: ");
    scanf("%d",&n_filhos);

    for(i=0;i<n_filhos;i++){
       arvAux = (TArvore) malloc(sizeof(TNo));
       printf("Filho %d: ",i+1);
       scanf(" %c",&dado.Chave);
       TArvore_Inicia(arvAux,dado);
       TArvore_Insere(arvore,arvAux);
    }

    filhos = TArvore_ListaDescendentes(arvore);
    while(!TLista_EhVazia(filhos)){
       TLista_RetiraPrimeiro(filhos,&arvFilho);
       printf("Qtos filhos tem o noh %c: ",arvFilho->Dados.Chave);
       scanf("%d",&n_filhos);
       for(i=0;i<n_filhos;i++){
          arvAux = (TArvore) malloc(sizeof(TNo));
          printf("Filho %d: ",i+1);
          scanf(" %c",&dado.Chave);
          TArvore_Inicia(arvAux,dado);
          TArvore_Insere(arvFilho,arvAux);
        }
    }

    TArvore_Imprime(arvore,0);

    return 0;
}
