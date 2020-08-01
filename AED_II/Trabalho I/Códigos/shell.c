#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *vet, int n)

{

  int i , j , x, h=1;

 do {
  h = 3*h+1;
 } while(h<n);



 do {

  h /= 3;
  for(i = h; i<n; i++) {
    j = i-h;
    x = vet[i];

    while (j >= 0 && vet[j]>x) {
    	vet[j+h] = vet[j];
        j -= h;
   }

   vet[j+h] = x;
  }

 }while(h!=1);

}
