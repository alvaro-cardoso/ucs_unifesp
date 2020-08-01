#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **M;
    int i, j, nrows = 3, ncols = 2;

    M = (int **) malloc(nrows * sizeof(int *));

    for(i=0;i<nrows;i++){
       M[i] = (int *) malloc(ncols * sizeof(int));
    }


    for(i=0;i<nrows;i++){
       for(j=0;j<ncols;j++){
          M[i][j] = (i+1)*(j+1);
          printf("M[%d][%d] = %d\t",i,j,M[i][j]);
       }
       printf("\n");
    }

    printf("\n*(*(M+1)+1) = %u",*(*(M+1)+1));

    for(i=0;i<nrows;i++){
       free(M[i]);
    }
    free(M);

    return 0;
}
