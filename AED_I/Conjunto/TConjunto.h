#include <stdio.h>
#include<stdlib.h>
#define MAXTAM 20
#define MAXTAM2 40

typedef struct{
int tam;
int vet[MAXTAM2];
} TUni;

typedef struct{
int tam;
int vet[MAXTAM];
} TVet;


void TConjunto_Inicia(TVet *pVet);
void TConjunto_Leconjunto(TVet *pVet);
void TConjunto_Uniao(TVet *pVet, TVet *pVet2);
void TConjunto_Interseccao(TVet *pVet, TVet *pVet2);
void TConjunto_Teste(TVet *pVet, TVet *pVet2);
void TConjunto_ImprimeConjunto(TVet *pVet);

