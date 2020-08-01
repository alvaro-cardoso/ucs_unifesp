#include <stdio.h>

#include <stdlib.h>

#define max 1000000

typedef struct
{

    int oferta;

    int senha;

} cel;

void trocanum(cel vet[], int y, int z)
{

    cel aux;

    aux = vet[y];

    vet[y] = vet[z];

    vet[z] = aux;
}

int maxheapify(cel vet[], int i, int tam)
{

    int topo, d, e;

    d = 2 * i + 1;

    e = 2 * i;

    topo = i;

    if (e <= tam)
    {

        if (vet[e].oferta == vet[i].oferta && vet[e].senha < vet[i].senha || vet[e].oferta > vet[topo].oferta)

            topo = e;
    }

    if (d <= tam)
    {

        if (vet[d].oferta == vet[topo].oferta && vet[d].senha < vet[topo].senha)

            topo = d;

        if (vet[d].oferta > vet[topo].oferta)

            topo = d;
    }

    if (topo != i)
    {

        trocanum(vet, i, topo);

        maxheapify(vet, topo, tam);

        return 1;
    }

    return 0;
}

void buildmaxheap(cel vet[], int tam)
{

    int i;

    i = tam / 2;

    while (maxheapify(vet, i, tam) != 0)
    {

        i = (i) / 2;
    }
}

int main()
{

    cel vet[max];

    char a;

    int i = 0, x, j = 0, key = 0;

    scanf("%c", &a);

    while (a != 'f')
    {

        if (a == 'c')
        {

            scanf("%d", &x);

            vet[i].oferta = x;

            vet[i].senha = key + 1;

            i++;

            key++;

            buildmaxheap(vet, i - 1);
        }

        if (a == 'v')
        {

            if (i > 0)
            {

                printf("%d\n", vet[0].senha);

                vet[0] = vet[i - 1];

                i--;

                maxheapify(vet, 0, i - 1);
            }

            else

                printf("0\n");
        }

        scanf("%c", &a);
    }

    return 0;
}
