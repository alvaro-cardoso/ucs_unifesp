#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *vet, int maior, int menor, int tam){
    int i,j, C[(maior-menor)+1],B[tam];

    for (i=0;i<=(maior-menor);i++){
        C[i]=0;
    }

    for (i=0;i<tam;i++){
        C[vet[i]-menor]++;
    }

    for (i=1;i<=maior-menor;i++){
        C[i]=C[i]+C[i-1];
    }


    for (i=tam-1;i>=0;i--){
        B[C[vet[i]-menor]-1]=vet[i];
        C[vet[i]-menor]--;
    }

    for (i=0;i<tam;i++){
        vet[i]=B[i];
    }

}
