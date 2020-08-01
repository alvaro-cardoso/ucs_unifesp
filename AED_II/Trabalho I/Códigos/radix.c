#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void counting_sortrdx(int *vet, int maior, int tam,int dig){
    int i,j, C[10],B[tam];

    for (i=0;i<10;i++){
        C[i]=0;
    }

    for (i=0;i<tam;i++){
        C[(vet[i]/dig)%10]++;
    }

    for (i=1;i<10;i++){
        C[i]=C[i]+C[i-1];
    }


    for (i=tam-1;i>=0;i--){
        B[C[(vet[i]/dig)%10]-1]=vet[i];
        C[(vet[i]/dig)%10]--;
    }

    for (i=0;i<tam;i++)
        vet[i]=B[i];
}

void radix_sort(int *vet, int tam){
    int dig, i,maior,menor;

    menor=vet[0];

    for(i=0;i<tam;i++){
        if(menor>vet[i])
        menor=vet[i];
    }

    if(menor<0){
    for (i=0;i<tam;i++)
        vet[i]-=menor;
    }

    maior=vet[0];

    for(i=0;i<tam;i++){
        if(maior<vet[i])
        maior=vet[i];}

    for (dig = 1; maior/dig > 0; dig=dig*10){
        counting_sortrdx(vet, maior, tam, dig);
    }

    if(menor<0){
    for (i=0;i<tam;i++)
        vet[i]+=menor;
    }
}
