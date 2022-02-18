    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #define MAX 30
     
    int main (){
        int soma = 0, n, m, d, dia[MAX], dif, cont = 0;
        float avg;
        scanf("%d %d ", &n, &m);
        dif = m-n;
        for(int i = 0; i <30; i ++){
            scanf("%d ", &d);
            soma+=d;
            dia[i]=d;
        }
        while (dif > 0){
        avg = ceil((float)soma/30);
        soma = (int)(soma-dia[cont%30]+avg);
        dia[cont%30]=(int)avg;
        dif -= (int)avg;
        cont++;
        }
        
        printf("%d", cont);
        return 0;
    }