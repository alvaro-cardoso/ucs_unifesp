#include <stdio.h>
#include <time.h>
#include "bubble.c"
#include "insertion.c"
#include "shell.c"
#include "heap.c"
#include "counting.c"
#include "radix.c"
#define MAX 1000000

int main(){
    int i, tam, entrada, alg, vet[MAX], maior=-2000000000, menor=2000000000;
    clock_t tempo;
    float tempofinal;
    FILE *file;

    printf("TAMANHO DA ENTRADA:\n1 - 1000\n2 - 10000\n3 - 100000\n4 - 1000000\nESCOLHA O TAMANHO (DIGITE 0 PARA SAIR): ");
    scanf("%d", &tam);
    while(tam > 0){
        printf("\nTIPO DE ENTRADA:\n1 - CRESCENTE\n2 - DECRESCENTE\n3 - ALEATORIA\nESCOLHA A ENTRADA: ");
        scanf("%d", &entrada);
        printf("\nALGORITMO:\n1 - BUBBLE\n2 - INSERTION\n3 - SHELL\n4 - HEAP\n5 - COUNTING\n6 - RADIX\nESCOLHA O ALGORTIMO: ");
        scanf("%d", &alg);
        printf("\n");

        switch(tam){
            case 1:{
                switch(entrada){
                    case 1:{
                        if(alg >= 5)
                            file = fopen("counting1000_cres.txt", "r");
                        else
                            file = fopen("teste1000_crescente.txt", "r");
                    break;
                    }
                    case 2:{
                        if(alg>=5)
                            file = fopen("counting1000_decres.txt", "r");
                        else
                            file = fopen("teste1000_decrescente.txt", "r");
                    break;
                    }
                    case 3:{
                        if(alg>=5)
                            file = fopen("counting1000_aleatorio.txt", "r");
                        else
                            file = fopen("teste1000_aleatorio.txt", "r");
                        break;
                    }
                }
                tam = 1000;
            }
            break;

            case 2:{
                switch(entrada){
                    case 1:{
                        if(alg >= 5)
                            file = fopen("counting10000_cres.txt", "r");
                        else
                            file = fopen("teste10000_crescente.txt", "r");
                    break;
                    }
                    case 2:{
                        if(alg>=5)
                            file = fopen("counting10000_decre.txt", "r");
                        else
                            file = fopen("teste10000_decrescente.txt", "r");
                    break;
                    }
                    case 3:{
                        if(alg>=5)
                            file = fopen("counting10000_aleatorio.txt", "r");
                        else
                            file = fopen("teste10000_aleatorio.txt", "r");
                        break;
                    }
                }
                tam = 10000;
            break;
            }

            case 3:{
                switch(entrada){
                    case 1:{
                        if(alg >= 5)
                            file = fopen("counting100000_cres.txt", "r");
                        else
                            file = fopen("teste100000_crescente.txt", "r");
                    break;
                    }
                    case 2:{
                        if(alg >= 5)
                            file = fopen("counting100000_decres.txt", "r");
                        else
                            file = fopen("teste100000_decrescente.txt", "r");
                    break;
                    }
                    case 3:{
                        if(alg >= 5)
                            file = fopen("counting100000_aleatorio.txt", "r");
                        else
                            file = fopen("teste100000_aleatorio.txt", "r");
                        break;
                    }
                }
                tam = 100000;
            break;
            }

            case 4:{
                switch(entrada){
                    case 1:{
                        if(alg >= 5)
                            file = fopen("counting1000000_cres.txt", "r");
                        else
                            file = fopen("teste1000000_crescente.txt", "r");
                    break;
                    }
                    case 2:{
                        if(alg>=5)
                            file = fopen("counting1000000_decres.txt", "r");
                        else
                            file = fopen("teste1000000_decrescente.txt", "r");
                    break;
                    }
                    case 3:{
                        if(alg>=5)
                            file = fopen("counting1000000_aleatorio.txt", "r");
                        else
                            file = fopen("teste1000000_aleatorio.txt", "r");
                        break;
                    }
                }
                tam=1000000;
            break;
            }
        }

        switch(alg){
            case 1:{
                for(i=0;i<tam;i++)
                    fscanf(file, "%d ", &vet[i]);

                tempo = clock();
                bubble_sort(vet,tam);
                tempofinal = clock()-tempo;

                printf("TEMPO GASTO: %f s", tempofinal/1000);
                fclose(file);

                break;
            }
            case 2:{
                for(i=0;i<tam;i++)
                    fscanf(file, "%d ", &vet[i]);

                tempo = clock();
                insertion_sort(vet,tam);
                tempofinal = clock()-tempo;

                printf("TEMPO GASTO: %f s", tempofinal/1000);
                fclose(file);

                break;
            }

            case 3:{
                for(i=0;i<tam;i++)
                    fscanf(file, "%d ", &vet[i]);

                tempo = clock();
                shell_sort(vet,tam);
                tempofinal = clock()-tempo;

                printf("TEMPO GASTO: %f s", tempofinal/1000);
                fclose(file);

                break;
            }

            case 4:{
                for(i=0;i<tam;i++)
                    fscanf(file, "%d ", &vet[i]);

                tempo = clock();
                heap(vet,tam);
                tempofinal = clock()-tempo;

                printf("TEMPO GASTO: %f s", tempofinal/1000);
                fclose(file);

                break;
            }

            case 5:{
                if(entrada < 3 && tam == 1000000){
                    printf("ENTRADA INEXISTENTE");
                    break;
                }

                for(i=0;i<tam;i++){
                    fscanf(file, "%d ", &vet[i]);
                    if(vet[i]>maior)
                        maior = vet[i];
                    if(vet[i]<menor)
                        menor = vet[i];
                }

                tempo = clock();
                counting_sort(vet,maior,menor,tam);
                tempofinal = clock()-tempo;

                printf("TEMPO GASTO: %f s", tempofinal/1000);
                fclose(file);

                maior = -2000000000;
                menor = 2000000000;

                break;
            }

            case 6:{
                if(entrada < 3 && tam == 1000000){
                    printf("ENTRADA INEXISTENTE");
                    break;
                }

                for(i=0;i<tam;i++)
                    fscanf(file, "%d ", &vet[i]);

                tempo = clock();
                radix_sort(vet,tam);
                tempofinal = clock()-tempo;

                printf("\n\nTEMPO GASTO: %f s", tempofinal/1000);
                fclose(file);

                break;
            }
        }

        printf("\n\nTAMANHO DA ENTRADA:\n1 - 1000\n2 - 10000\n3 - 100000\n4 - 1000000\nESCOLHA O TAMANHO (DIGITE 0 PARA SAIR): ");
        scanf("%d", &tam);
    }

    printf("\n");

    return 0;
}
