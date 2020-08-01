#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct{
    TChave Chave;
} TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula{
    TItem Item;
    TApontador Prox,Ant;
} TCelula;

typedef struct{
    TApontador Primeiro, Ultimo;
    int Tamanho;
} TLista;

int TLista_Retira(TLista *lista,TApontador p,TItem *item){
   TApontador pAnt, pProx;

   if(p==NULL)
      return 0;
   pAnt = p->Ant;
   pProx = p->Prox;
   pAnt->Prox = p->Prox;
   if(p==lista->Ultimo){
      lista->Ultimo = pAnt;
   }
   else{
      pProx->Ant = p->Ant;
   }
   *item = p->Item;
   free(p);
   return 1;
}

int TLista_InserePrimeiro(TLista *lista,TItem item){
   TApontador pNovo,pAnt,pProx;

   pNovo = (TApontador) malloc(sizeof(SCelula));
   pNovo->Item = item;

   pAnt = lista->Primeiro;
   pProx = lista->Primeiro->Prox;
   lista->Primeiro->Prox = pNovo;
   pNovo->Prox = pProx;
   pNovo->Ant = pAnt;
   if(TLista_EhVazia(lista))
      lista->Ultimo = pNovo;
   lista->Tamanho++;
   return 1;
}
