#include <stdio.h>
#include <stdlib.h>
#include "TList.h"

int TList_Start (TList *pList){

    pList->First=(TPointer) malloc(sizeof(TCell));
    pList->Last=pList->First;
    pList->First->Nxt=NULL;
    pList->First->B4=NULL;
    pList->len=0;

}

int TList_Test (TList *pList){

    if (TList_Len (pList)==0)
        return 1;
    else return 0;
    }


int TList_Clearspc (TList *pList, TPointer pPointer, TItem *x){

TPointer aux;

    if(TList_Test(pList))
        return 0;

    else{
        aux = pPointer;
        pPointer->B4->Nxt = aux->Nxt;
        pPointer->Nxt->B4=aux->B4;
        if(pList->Last==pPointer)
        pList->Last=pPointer->B4;
        *x=aux->item;
        free(aux);
        pList->len--;
        return 1;
            }
}


int TList_InsertF (TList *pList, TItem x){
TPointer nv;

    nv= (TPointer) malloc (sizeof(TCell));
    nv->item=x;
    nv->B4=NULL;

    if(TList_Test(pList)){
        pList->First=nv;
        pList->len++;
        return 1;
        }
    else{
        nv->Nxt=pList->First;
        pList->First->B4=nv;
        pList->First=nv;
         pList->len++;
         printf("\n\n ");
         printf("%d",pList->First->item);
    return 1;
    }
}


int TList_Print (TList *pList){

    TPointer aux;
    if(TList_Test(pList))
        return 0;

    aux=pList->First;
    while(aux!=NULL){
    printf("%d",aux->item.Key);
    aux=aux->Nxt;}
    return 1;

}
int TList_Len (TList *pList){
return (pList->len);
}


TPointer TLista_Return(TList *pList, int p){
    TPointer pA;
    int Pos;

    Pos = 0;
    pA = pList->First;
    while((pA!=NULL) && (Pos!=p)){
        pA = pA->Nxt;
        Pos++;
    }
    return pA;
}
