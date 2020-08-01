#include <stdio.h>
#include <stdlib.h>
#include "TLista-ponteiro.h"

void TLista_Inicia(TLista *pLista){
    pLista->Primeiro = NULL;
    pLista->Ultimo = NULL;
    pLista->Tamanho = 0;
}

int TLista_EhVazia(TLista *pLista){
    return (pLista->Primeiro == NULL);
}

int TLista_Tamanho(TLista *pLista){
    return pLista->Tamanho;
}

int TLista_InserePrimeiro(TLista *pLista, TItem x){
    TApontador novo;

    novo = (TApontador) malloc(sizeof(TCelula));
    novo->Item = x;
    novo->Prox = pLista->Primeiro;
    pLista->Primeiro = novo;
    if(TLista_EhVazia(pLista))
       pLista->Ultimo = novo;
    pLista->Tamanho++;
    return 1;
}

int TLista_InsereUltimo(TLista *pLista, TItem x){
    TApontador novo;

    novo = (TApontador) malloc(sizeof(TCelula));
    novo->Item = x;
    novo->Prox = NULL;
    if(TLista_EhVazia(pLista))
       pLista->Primeiro = novo;
    //-------
    else
       pLista->Ultimo->Prox = novo;
    //--------

    pLista->Ultimo = novo;
    pLista->Tamanho++;
    return 1;
}

int TLista_Insere(TLista *pLista, TApontador p, TItem x){
    TApontador anterior, novo;

    if(p==NULL)
       return TLista_InsereUltimo(pLista,x);

    //----
    if(p==pLista->Primeiro)
       return TLista_InserePrimeiro(pLista,x);
    //----

    anterior = pLista->Primeiro;
    //Fizemos while(anterior->Prox!=p)
    while(anterior!=pLista->Ultimo && anterior->Prox!=p)
       anterior = anterior->Prox;

    //-------
    if (anterior == pLista->Ultimo)
      return 0;
    //-------

    novo = (TApontador) malloc(sizeof(TCelula));
    novo->Item = x;
    novo->Prox = anterior->Prox;
    anterior->Prox = novo;
    pLista->Tamanho++;
    return 1;
}

int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX){
   TApontador aux;

   if(TLista_EhVazia(pLista))
      return 0;

   aux = pLista->Primeiro;
   pLista->Primeiro = aux->Prox;
   *pX = aux->Item;
   free(aux);
   pLista->Tamanho--;
   if(pLista->Tamanho==0)
      pLista->Ultimo = NULL;
   return 1;
}

int TLista_RetiraUltimo(TLista *pLista, TItem *pX){
   TApontador aux,anterior;

   if(TLista_EhVazia(pLista))
      return 0;

   if(pLista->Primeiro==pLista->Ultimo){
      return TLista_RetiraPrimeiro(pLista,pX);
   }
   else{
      anterior = pLista->Primeiro;
      while(anterior->Prox!=pLista->Ultimo)
         anterior = anterior->Prox;
      aux = pLista->Ultimo;
      anterior->Prox = NULL;
      pLista->Ultimo = anterior;
      *pX = aux->Item;
      free(aux);
      pLista->Tamanho--;
      return 1;
   }
}

int TLista_Retira(TLista *pLista, TApontador p, TItem *pX){
    TApontador anterior, aux;

    if(TLista_EhVazia(pLista) || p==NULL)
      return 0;

    if(p==pLista->Ultimo)
       return TLista_RetiraUltimo(pLista,pX);

    if(p==pLista->Primeiro)
       return TLista_RetiraPrimeiro(pLista,pX);

    anterior = pLista->Primeiro;

    //Fizemos while(anterior->Prox!=p)
    while(anterior != pLista->Ultimo && anterior->Prox!=p)
       anterior = anterior->Prox;

    //------
    if (anterior == pLista->Ultimo)
      return 0;
    //------

    //------
    aux = anterior->Prox;
    //------

    anterior->Prox = aux->Prox;
    *pX = aux->Item;
    free(aux);
    pLista->Tamanho--;
    return 1;
}

TApontador TLista_Retorna(TLista *pLista, int p)
{
  TApontador pApontador;
  int Posicao;

  Posicao = 0;
  pApontador = pLista->Primeiro;
  while ((pApontador != NULL) && (Posicao != p)) {
    pApontador = pApontador->Prox;
    Posicao++;
  }

  return pApontador;
}

void TLista_Imprime(TLista *pLista){
    TApontador aux;

    if(TLista_EhVazia(pLista))
        printf("Lista vazia!");
    else{
        aux = pLista->Primeiro;
        while(aux!=NULL){
           printf("%d ",aux->Item.Chave);
           aux = aux->Prox;
        }
    }
}
