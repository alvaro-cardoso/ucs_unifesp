#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define max 10000000

void shell(int vet[], int n)
{
    int i, j, x, h = 1;

    do
    {
        h = 3 * h + 1;
    } while (h < n);

    do
    {
        h /= 3;
        for (i = h; i < n; i++)
        {
            j = i - h;
            x = vet[i];

            while (j >= 0 && vet[j] > x)
            {
                vet[j + h] = vet[j];
                j -= h;
            }
            vet[j + h] = x;
        }
    } while (h != 1);
}

int main()
{

    int vet[max], n, g, s, n2 = 0, r, i, cont = 0;

    scanf("%d %d", &n, &g);

    for (i = 0; i < n; i++)
    {

        scanf("%d %d", &s, &r);

        if (s > r)
        {

            cont += 3;
        }

        else
        {

            vet[n2] = abs(s - r);

            n2++;
        }
    }

    shell(vet, n2);

    i = 0;

    while (g > 0 && i < n2)
    {

        vet[i]--;

        g--;

        if (vet[i] < 0)
        {

            cont += 3;

            i++;
        }
    }

    for (i = 0; i < n2; i++)
    {

        if (vet[i] == 0)

            cont++;
    }

    printf("%d", cont);

    return 0;
}