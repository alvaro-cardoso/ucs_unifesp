#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
int Numerador ;
int Denominador ;
} TNumeroRacional ;


void TRacional_Atribui(TNumeroRacional *pracional1,TNumeroRacional *pracional2);
void TRacional_Soma (TNumeroRacional *pracional1,TNumeroRacional *pracional2);
void TRacional_Subtracao (TNumeroRacional *pracional1,TNumeroRacional *pracional2);
void TRacional_Multiplica (TNumeroRacional *pracional1,TNumeroRacional *pracional2);
void TRacional_Divide (TNumeroRacional *pracional1,TNumeroRacional *pracional2);
void TRacional_Testa (TNumeroRacional *pracional1,TNumeroRacional *pracional2);
