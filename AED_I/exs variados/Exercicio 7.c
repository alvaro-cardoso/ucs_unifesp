#include <stdio.h>
#include <stdlib.h>
#include "TLista-ponteiro.c"

int TLista_Pertence(TLista *pLista, TItem n){

    int x=0;
    TApontador aux;

    if(TLista_EhVazia(pLista)){
        return 0;}
    else{
        aux = pLista->Primeiro;
        while(aux!=NULL){
        if(n.Chave==aux->Item.Chave){
            x=1;
            break;}
            else if (aux!=NULL)aux = aux->Prox;
        }}
        if(x<1){
            return 0;}
        else return 1;

}


TLista *TLista_Uniao(TLista *pLista1, TLista *pLista2){

    TLista *listaaux;
    TApontador aux_pLista1, aux_pLista2;
    TItem itemaux;


    listaaux = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(listaaux);

    aux_pLista1=pLista1->Primeiro;
    aux_pLista2=pLista2->Primeiro;

    if(!TLista_EhVazia(pLista1)|| !TLista_EhVazia(pLista2)){

    while((aux_pLista1 != NULL)){
        itemaux.Chave = aux_pLista1->Item.Chave;
        if(!TLista_Pertence(listaaux,itemaux))
            TLista_InserePrimeiro(listaaux,itemaux);
        aux_pLista1 = aux_pLista1->Prox;
    }

    while((aux_pLista2 != NULL)){
        itemaux.Chave = aux_pLista2->Item.Chave;
        if(!TLista_Pertence(listaaux,itemaux))
            TLista_InserePrimeiro(listaaux,itemaux);
        aux_pLista2 = aux_pLista2->Prox;
    }
     return (listaaux);
    }
   return (listaaux);

}

TLista *TLista_Intersec(TLista *pLista1, TLista *pLista2){
    TLista *listaaux;
    TApontador aux_pLista1;
    TItem itemaux;


    listaaux = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(listaaux);

    if(TLista_Tamanho(pLista1)<=TLista_Tamanho(pLista2))
    aux_pLista1=pLista2->Primeiro;
    else aux_pLista1=pLista1->Primeiro;

    if(!TLista_EhVazia(pLista1)|| !TLista_EhVazia(pLista2)){

    while(aux_pLista1 != NULL){
    itemaux.Chave = aux_pLista1->Item.Chave;
    if(TLista_Pertence(pLista1,itemaux)&&TLista_Pertence(pLista2,itemaux)){
        if(!TLista_Pertence(listaaux,itemaux))
        TLista_InserePrimeiro(listaaux,itemaux);
        }
        aux_pLista1 = aux_pLista1->Prox;
    }
    return (listaaux);
    }
    return (listaaux);

}

TLista *TLista_Dif(TLista *pLista1, TLista *pLista2){

    int i=0;
    TLista *listauni, *listaint,*listaaux;
    TApontador aux_pLista1, aux_pLista2;
    TItem itemaux;

    listaaux = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(listaaux);


    listauni=TLista_Uniao(pLista1,pLista2);
    listaint=TLista_Intersec(pLista1,pLista2);

    aux_pLista1=listauni->Primeiro;

    if(!TLista_EhVazia(pLista1)|| !TLista_EhVazia(pLista2)){
    while(aux_pLista1 != NULL){
        itemaux.Chave = aux_pLista1->Item.Chave;
        if(!TLista_Pertence(listaint,itemaux)&&!TLista_Pertence(listaaux,itemaux)){
            TLista_InserePrimeiro(listaaux,itemaux);
        }
    aux_pLista1 = aux_pLista1->Prox;
    }
    return listaaux;
    }
    return listaaux;
}

int main(){
    TLista *Conjunto1, *Conjunto2, *imprime1, *imprime2, *imprime3;
    TItem item, itemp;
    int j, n;

    Conjunto1 = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(Conjunto1);

    Conjunto2 = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(Conjunto2);

    printf("Insira o tamanho do Conjunto 1: ");
    scanf("%d", &n);

    printf("Insira os elementos do conjunto 1: \n");
    for(j=0;j<n;j++){
        scanf("%d", &item.Chave);
        TLista_Insere(Conjunto1,TLista_Retorna(Conjunto1,j),item);
    }

    printf("\nDigite o numero a verficar : ");
    scanf("%d", &itemp.Chave);

    if(!TLista_Pertence(Conjunto1,itemp))
        printf("Este numero nao pertence ao conjunto fornecido.");
    else
       printf("Este numero pertence ao conjunto fornecido.");

    printf("\n\n\nInsira o tamanho do Conjunto 2: ");
    scanf("%d", &n);

    printf("\nInsira os elementos do Conjunto 2: \n");
    for(j=0;j<n;j++){
        scanf("%d", &item.Chave);
        TLista_Insere(Conjunto2,TLista_Retorna(Conjunto2,j),item);
    }

    printf("\na uniao eh: ");
    imprime1=TLista_Uniao(Conjunto1,Conjunto2);
    if (!TLista_EhVazia(imprime1))
    TLista_Imprime(imprime1);
    else printf("{ }");
    printf("\na intersecao  eh: ");
    imprime2=TLista_Intersec(Conjunto1,Conjunto2);
    if (!TLista_EhVazia(imprime2))
    TLista_Imprime(imprime2);
    else printf("{ }");
    printf("\nA diferenca eh: ");
    imprime3=TLista_Dif(Conjunto1,Conjunto2);
    if (!TLista_EhVazia(imprime3))
    TLista_Imprime(imprime3);
    if ((TLista_EhVazia(Conjunto2)&&TLista_EhVazia(Conjunto1))||(TLista_EhVazia(imprime3))){
    printf("{ }");}
    printf("\n\nConjunto 1: ");
    TLista_Imprime(Conjunto1);
    printf("\n\nConjunto 2: ");
    TLista_Imprime(Conjunto2);
    free(Conjunto1);
    free(Conjunto2);
    free(imprime1);
    free(imprime2);
    free(imprime3);
    return 0;
}
