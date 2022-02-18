        #include <stdio.h>
        #include <stdlib.h>
        #define MAX (1000001)
     
        typedef struct { //struct com a pos e valor
            int Indice;
            int Valor;
        } Cel;
        
        void trocanum (Cel *vet, int i1, int i2){ //funcao de troca para heap
            Cel aux;
            aux=vet[i1];
            vet[i1]=vet[i2];
            vet[i2]=aux;
        }
        
        void minheapfy(Cel *vet, int i, int tam) { //  inverso da heap normal(maxheapfy)
     
            int esq = (i*2), dir = (i*2)+1, maior;
     
            if(esq < tam && vet[esq].Valor <= vet[i].Valor)
                maior = esq;
            else
                maior = i;
            if (dir < tam && vet[dir].Valor <= vet[maior].Valor)
                maior = dir;
     
            if(maior != i) {
                trocanum(vet, maior, i);
                minheapfy(vet, maior, tam);
            }
        }
     
        void buildminheap (Cel *vet, int tam) { //construi heap inverso (buildmaxheap)
            for(int i = tam/2; i >= 0; i--)
                minheapfy(vet, i, tam);
        }
     
     
        int main() {
     
     
            Cel **mat, *aux;
            int k, i, x, z,*tam;
     
            scanf("%d %d", &k, &i);
     
            mat = (Cel**)malloc(k*sizeof(Cel*));
            tam = (int*)malloc(k*sizeof(int));
            aux = (Cel*)malloc(k*sizeof(Cel));
     
            for(x = 0; x < k; x++) { //entradas
                scanf("%d", &tam[x]);
                mat[x] = (Cel*) malloc(tam[x]*sizeof(Cel));
     
            for(z = 0; z < tam[x]; z++)
                scanf("%d", &mat[x][z].Valor);
            }
     
            for(x = 0; x < k; x++) { //atrib no aux
                aux[x].Indice = x;
                if(tam[x] == 0)
                    aux[x].Valor = MAX;
                else
                    aux[x].Valor = mat[x][0].Valor;
            }
     
            buildminheap(aux, k);
            
            for(x = 0; x < i; x++) { //remove elementos, att tam e desloca pos
                
                tam[aux[0].Indice] --;
                if(tam[aux[0].Indice] == 0)
                    mat[aux[0].Indice][0].Valor = MAX;
     
                for(z = 0; z < (tam[aux[0].Indice]); z++)
                    mat[aux[0].Indice][z] = mat[aux[0].Indice][z+1];
     
                if(x+1 < i){
                    aux[0].Valor = mat[aux[0].Indice][0].Valor;
                    minheapfy(aux, 0, k);
                    }
     
            }
     
            long long int soma = 0; // long int pra passar no ultimo teste
            for(x = 0; x < k; x++) {
                if(aux[x].Valor != MAX)
                soma+=aux[x].Valor;
            }
                printf("%lld",soma);
     
            return(0);
        }