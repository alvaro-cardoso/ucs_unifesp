#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, i, n;

    n = 3;
    p = (int *) malloc(n*4);

    for(i=0;i<n;i++){
       p[i] = i+1;
    }
    for(i=0;i<n;i++){
       printf("\n&p[%d] = %u",i,&p[i]);
       printf("\np[%d] = %d",i,p[i]);
    }
    printf("\n");
    for(i=0;i<n;i++){
       printf("\n(p+%d) = %u",i,(p+i));
       printf("\n*(p+%d) = %d",i,*(p+i));
    }

    free(p);
    return 0;
}
