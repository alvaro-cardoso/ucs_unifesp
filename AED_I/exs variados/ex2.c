#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3] = {1,2,3};
    int *p;

    printf("&A[0] = %u\n",&A[0]);
    printf("&A[1] = %u\n",&A[1]);
    printf("&A[1] = %u\n",&A[2]);

    printf("\nA = %u\n",A);

    p = A;
    printf("\np = %u",p);
    printf("\n*p = %d",*p);
    p = p+2;

    printf("\np = %u",p);
    printf("\n*p = %d",*p);

    return 0;
}
