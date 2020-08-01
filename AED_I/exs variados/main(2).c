#include <stdio.h>
#include <stdlib.h>
#include "TGrafo_Lista.h"

int main()
{
    TGrafo *grafo;
    int nVertices;
    int v1, v2, aresta=0;
    char opcao = 's';

    printf("Digite o numero de vertices: ");
    scanf("%d",&nVertices);

    grafo = (TGrafo *) malloc(sizeof(TGrafo));
    TGrafo_Inicia(grafo,nVertices);

    while(opcao!='n'){
        printf("\nInsira uma aresta.");
        printf("\nVertice: ");
        scanf("%d",&v1);
        printf("\nVertice: ");
        scanf("%d",&v2);
        TGrafo_InsereAresta(grafo,v1,v2,aresta);
        aresta++;
        printf("\nDeseja continuar? (s/n): ");
        scanf(" %c",&opcao);
    }
    TGrafo_Imprime(grafo);
    free(grafo);

    return 0;
}
