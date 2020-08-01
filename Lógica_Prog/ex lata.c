#include <stdio.h>
#include <math.h>

void main()
{

    int qtlatas;
    float area, raio, altura, custo;
    printf("\n digite a altura ");
    scanf("%f", &altura);
    printf("\n digite o raio ");
    scanf("%f", &raio);
    area = 3.14 * pow(raio, 2) + 2 * 3.14 * raio * altura;
    custo = ceil((area / 15) * 20);
    qtlatas = (area / 15);
    printf("serao necessarias %d latas", qtlatas);
    printf(" somando um total de %.2f", custo);
}