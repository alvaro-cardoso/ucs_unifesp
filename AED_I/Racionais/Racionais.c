#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Racionais.h"

void TRacional_Atribui(TNumeroRacional *pracional1, TNumeroRacional *pracional2){
    printf("numerador:\n");
    scanf("%d", &pracional1->Numerador);
    printf("denominador: \n");
    scanf("%d", &pracional1->Denominador);
    printf("numerador:\n");
    scanf("%d", &pracional2->Numerador);
    printf("denominador: \n");
    scanf("%d", &pracional2->Denominador);
}

void TRacional_Soma(TNumeroRacional *pracional1,TNumeroRacional *pracional2){

    TNumeroRacional soma;
    int i=2;
    if ((pracional1->Denominador)!=(pracional2->Denominador)){
    soma.Numerador=(pracional1->Numerador)*(pracional2->Denominador)+(pracional2->Numerador)*(pracional1->Denominador);
    soma.Denominador=(pracional1->Denominador)*(pracional2->Denominador);}
    else if((pracional1->Denominador)==(pracional2->Denominador)){
        soma.Numerador=(pracional1->Numerador)+(pracional2->Numerador);
        soma.Denominador=(pracional1->Denominador);}
        while(i<soma.Numerador || i<soma.Denominador){
            if (soma.Numerador%i==0 && soma.Denominador%i==0){
                soma.Numerador=soma.Numerador/i;
                soma.Denominador=soma.Denominador/i;}
                else i++;}
        if(soma.Numerador%soma.Denominador==0)
            printf("a soma eh: %d\n",(soma.Numerador/soma.Denominador));
    else printf("a soma eh: %d/%d\n",soma);
}

void TRacional_Subtracao (TNumeroRacional *pracional1,TNumeroRacional *pracional2){
    int i=2;
    TNumeroRacional sub;
    if((pracional1->Denominador)!=(pracional2->Denominador)){
    sub.Numerador=(pracional1->Numerador)*(pracional2->Denominador)-(pracional2->Numerador)*(pracional1->Denominador);
    sub.Denominador=(pracional1->Denominador)*(pracional2->Denominador);}
    else if((pracional1->Denominador)==(pracional2->Denominador)){
        sub.Numerador=(pracional1->Numerador)-(pracional2->Numerador);
        sub.Denominador=(pracional1->Denominador);}
         while (i<sub.Numerador || i<sub.Denominador){
                if (sub.Numerador%i==0 && sub.Denominador%i==0){
                sub.Numerador=sub.Numerador/i;
                sub.Denominador=sub.Denominador/i;}
                else i++;}
        if (sub.Numerador%sub.Denominador==0)
            printf("a subtracao eh: %d\n",(sub.Numerador/sub.Denominador));
    else printf("a subtracao eh: %d/%d\n",sub);
}

void TRacional_Multiplica (TNumeroRacional *pracional1,TNumeroRacional *pracional2){
    int i=2;
    TNumeroRacional mult;
    mult.Numerador=(pracional1->Numerador)*(pracional2->Numerador);
    mult.Denominador=(pracional1->Denominador)*(pracional2->Denominador);
     while (i<mult.Numerador || i<mult.Denominador){
                if (mult.Numerador%i==0 && mult.Denominador%i==0){
                mult.Numerador=mult.Numerador/i;
                mult.Denominador=mult.Denominador/i;}
    else i++;}
    if (mult.Numerador%mult.Denominador==0)
        printf("o multiplicacao eh: %d\n",(mult.Numerador/mult.Denominador));
    printf("a multiplicacao eh: %d/%d\n",mult);
}

void TRacional_Divide(TNumeroRacional *pracional1,TNumeroRacional *pracional2){
    int i=2;
    TNumeroRacional div;
    div.Numerador=(pracional1->Numerador)*(pracional2->Denominador);
    div.Denominador=(pracional1->Denominador)*(pracional2->Numerador);
    while (i<div.Numerador || i<div.Denominador){
                if (div.Numerador%i==0 && div.Denominador%i==0){
                div.Numerador=div.Numerador/i;
                div.Denominador=div.Denominador/i;}
                else i++;}
    if (div.Numerador%div.Denominador==0)
        printf("a divisao eh: %d\n",(div.Numerador/div.Denominador));
    else printf("a divisao eh: %d/%d\n",div);
}

void TRacional_Testa(TNumeroRacional *pracional1,TNumeroRacional *pracional2){
    int i=2;
    TNumeroRacional num1, num2;

    num1.Numerador=pracional1->Numerador;
    num2.Numerador=pracional2->Numerador;
    num1.Denominador=pracional1->Denominador;
    num2.Denominador=pracional2->Denominador;

     while (i<num1.Numerador || i<num2.Denominador){
                if (num1.Numerador%i==0 && num1.Denominador%i==0){
                num1.Numerador=num1.Numerador/i;
                num1.Denominador=num1.Denominador/i;
                }
                else i++;}

                i=2;

    while (i<num1.Numerador || i<num2.Denominador){
                if (num2.Numerador%i==0 && num2.Denominador%i==0){
                num2.Numerador=num2.Numerador/i;
                num2.Denominador=num2.Denominador/i;
               }
                else i++;}


    if(num1.Denominador==num2.Denominador && num1.Numerador==num2.Numerador)
        printf("os numeros sao iguais\n");
        else printf("os numeros nao sao iguais\n");
}
