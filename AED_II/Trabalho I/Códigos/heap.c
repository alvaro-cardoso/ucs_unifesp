#include <stdio.h>
#include <stdlib.h>

void trocanum (int *vet, int y, int z){
    int aux;

    aux=vet[y];
    vet[y]=vet[z];
    vet[z]=aux;
}

void maxheapify(int *vet, int i, int tam){

    int e,d,maior;

    d=2*i+1;
    e=2*i;
    maior=i;

    if (e<=tam && vet[e]>vet[i]){
        maior=e;
    }

    if (d<=tam && vet[d]>vet[maior]){
        maior=d;
    }
    if (maior!=i){
        trocanum(vet,i,maior);
        maxheapify(vet,maior,tam);
    }
}

void buildmaxheap(int *vet, int tam){
    int i;

    for(i=(tam/2);i>=0;i--){
        maxheapify(vet,i,tam);
    }
}



void heap(int *vet, int tam){
    int i;

    buildmaxheap(vet,tam);
    for(i=tam;i>=1;i--){
        trocanum(vet,0,i);
        tam--;
        maxheapify(vet,0,tam);
    }
}
