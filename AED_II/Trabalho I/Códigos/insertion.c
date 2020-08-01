#include <stdio.h>
#include <stdlib.h>
#define max 1000000

void insertion_sort(int *vet, int tam){

    int i,j,aux;
    for (i=1;i<tam;i++){
        j=i-1;
        aux=vet[i];
        while (j>=0 && vet[j]>aux){
            vet[j+1]=vet[j];
            j--;
        }
        vet[j+1]=aux;
    }
}
