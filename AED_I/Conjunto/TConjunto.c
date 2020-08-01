#include <stdio.h>
#include<stdlib.h>
#include"TConjunto.h"


    void TConjunto_Inicia(TVet *pVet){
    int i;
    for (i=0;i<20;i++){
    pVet->vet[i]=0;}

    }

    void TConjunto_Leconjunto(TVet *pVet){

    int i,j,temp;

    printf("digite o tamanho do conjunto: ");
    scanf("%d",&pVet->tam);

    for (i=0;i<pVet->tam;i++){
        printf("digite o %d numero\n",(i+1));
        scanf("%d",&pVet->vet[i]);
    }


  for(i=0;i<pVet->tam;i++){
        for(j=(i+1);j<pVet->tam;j++){
            if(pVet->vet[j] < pVet->vet[i]){
                temp = pVet->vet[i];
                pVet->vet[i] = pVet->vet[j];
                pVet->vet[j] = temp;
            }
        }
    }
}

    void TConjunto_Uniao(TVet *pVet, TVet *pVet2){

    TUni Uniao;

    int i, j,cont=0,y=1,x=0,z=pVet->tam;

    Uniao.tam=pVet->tam+pVet2->tam;
    for (i=0;i<z;i++){
        if (i==0){
            Uniao.vet[x]=pVet->vet[i];
            x++;}

       else{ cont=0;
        for (j=0;j<x;j++){
                if (Uniao.vet[j]==pVet->vet[i])
                    cont++;}
                if (cont<1){
                        Uniao.vet[x] = pVet->vet[i];
                        x++;
                        }
                }
        }

        y=x;
        z=pVet2->tam;

        for (i=0;i<z;i++){
                cont=0;
        for (j=0;j<y;j++){
                if (Uniao.vet[j]==pVet2->vet[i])
                    cont++;
                    }
                if (cont<1){
                        Uniao.vet[x] = pVet2->vet[i];
                        x++;
                        y++;}
            }

     Uniao.tam = x;
     printf("\n\na uniao dos conjuntos eh:\n\n");
     for(i=0;i<x;i++){
        printf("%d, ",Uniao.vet[i]);

        }
     }

    void TConjunto_Interseccao(TVet *pVet, TVet *pVet2){

    TVet Inter;
    int i,temp[20],z,j,cont=0,x=0;

    for (i=0;i<pVet->tam;i++){
            for(j=0;j<pVet2->tam;j++){
                if (pVet->vet[i]==pVet2->vet[j]){
                    temp[x]=pVet->vet[i];
                    x++;}
                }
            }

    z=0;
    for (i=0;i<x;i++)
        if (i==0){
            Inter.vet[z]=temp[i];
            z++;}

       else{ cont=0;
        for (j=0;j<z;j++){
                if (Inter.vet[j]==temp[i])
                    cont++;}
                if (cont<1){
                        Inter.vet[z] = temp[i];
                        z++;
                        }
                }


     printf("\n\na interseccao dos conjuntos eh:\n\n");

     for(i=0;i<z;i++){
        printf("%d, ",Inter.vet[i]);}
     }

    void TConjunto_Teste(TVet *pVet, TVet *pVet2){
    int i, j, maior, z=0;

    if(pVet->tam>=pVet2->tam)
        maior=pVet->tam;
    else maior=pVet2->tam;
    for (i=0;i<maior;i++){
        if(pVet->vet[i]!=pVet2->vet[i])
            z=1;
    }
    if (z!=0)
        printf("\n\nos cunjuntos nao sao iguais\n\n");
    else  printf("\n\nos conjuntos sao iguais\n\n");
    }

    void TConjunto_ImprimeConjunto(TVet *pVet){
    int i;

    printf("\n\no conjunto digitado foi: \n\n");
    for (i=0;i<pVet->tam;i++)
        printf("%d, ",pVet->vet[i]);
}
