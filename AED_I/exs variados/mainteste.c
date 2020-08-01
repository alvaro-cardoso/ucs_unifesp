#include <stdio.h>
#include <stdlib.h>
#include "TArvBin.c"

TArvBin Le_ArvBin();
void PreOrdem(TArvBin);
void EmOrdem(TArvBin);
void PosOrdem(TArvBin);

int main()
{
    TArvBin raiz;
    int n;
    raiz = Le_ArvBin();

    printf("\nPre-Ordem:\n");
    PreOrdem(raiz);
    printf("\nEm-Ordem:\n");
    EmOrdem(raiz);
    printf("\nPos-Ordem:\n");
    PosOrdem(raiz);

    n=Conta_No(raiz);
    printf("\nNum de nos eh %d", n);

    n=Soma_No(raiz);
    printf("\nSoma eh %d", n);

    if(!EH_Bin(raiz)){
        printf("\nn eh bin");
    }
    else printf("\n eh bin");

    TArvBin_Libera(raiz);

    return 0;
}

TArvBin Le_ArvBin(){
    TItem item;
    TArvBin esq, dir;
    char resp = 'n';
    int chave;
    printf("Digite o item do no: ");
    scanf("%d",&chave);
    item.Chave = chave;
    printf("O no %d possui sub-arvore esquerda? (s/n)", chave);
    scanf(" %c",&resp);
    if(resp == 'n')
       esq = NULL;
    else
       esq = Le_ArvBin();

    printf("O no %d possui sub-arvore direita? (s/n)", chave);
    scanf(" %c",&resp);
    if(resp == 'n')
       dir = NULL;
    else
       dir = Le_ArvBin();


    return TArvBin_CriaNo(item,esq,dir);
}


void PreOrdem(TArvBin No){
    if (No != NULL) {
        printf("%d ",No->Item.Chave);
        PreOrdem(No->Esq);
        PreOrdem(No->Dir);
    }
}

void EmOrdem(TArvBin No){
    if (No != NULL) {
        EmOrdem(No->Esq);
        printf("%d ",No->Item.Chave);
        EmOrdem(No->Dir);
    }
}

void PosOrdem(TArvBin No){
    if (No != NULL) {
        PosOrdem(No->Esq);
        PosOrdem(No->Dir);
        printf("%d ",No->Item.Chave);
    }
}
