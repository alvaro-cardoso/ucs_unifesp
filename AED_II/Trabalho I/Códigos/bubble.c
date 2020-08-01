#include <stdio.h>
#include <stdlib.h>
#define max 1000000

void troca(int *vet, int a, int b){
    int aux;

    aux=vet[a];
    vet[a]=vet[b];
    vet[b]=aux;
}

void bubble_sort(int *vet, int tam){

    int i,j;
    for (i=tam-1;i>0;i--){
        for (j=0;j<i;j++){
            if(vet[j]>vet[j+1]){
                troca (vet,j,j+1);
            }
        }
    }
}
