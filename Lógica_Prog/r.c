#include <stdio.h>

int mult(int a, int b)
{
    int soma = 0;
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            soma += b;
        }
        return soma;
    }
}
int main()
{
    int num1, num2;

    printf("digite os numeros a serem multiplicados: \n");
    scanf("%d %d", &num1, &num2);

    printf("%d", mult(num1, num2));

    return 0;
}