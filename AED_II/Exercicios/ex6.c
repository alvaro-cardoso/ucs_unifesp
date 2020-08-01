#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80

typedef struct
{
    int i, j;
} TipoVertice;

typedef struct
{
    int **adj, V, E;
} TipoGrafo;

typedef struct SCelula *TipoApontador;

typedef struct SCelula
{
    int Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct
{
    int Tam;
    TipoApontador Inicio, Fim;
} TipoFila;

int **AdjInit(int linha, int coluna)
{
    int i, j, **t;

    t = malloc(linha * sizeof(int *));
    for (i = 0; i < linha; i++)
        t[i] = malloc(coluna * sizeof(int));
    for (i = 0; i < linha; i++)
        for (j = 0; j < coluna; j++)
            t[i][j] = 0;

    return t;
}

TipoGrafo *GrafoInit(TipoGrafo *Grafo, int n)
{

    Grafo->V = n;
    Grafo->E = 0;
    Grafo->adj = AdjInit(n, n);

    return Grafo;
}

void GrafoInsere(TipoGrafo *Grafo, TipoVertice Vertice)
{
    int i, j;

    i = Vertice.i;
    j = Vertice.j;

    if (Grafo->adj[i][j] == 0)
        Grafo->E++;
    Grafo->adj[i][j] = 1;
    Grafo->adj[j][i] = 1;
}

void FilaInit(TipoFila *Fila)
{
    Fila->Inicio = NULL;
    Fila->Fim = NULL;
    Fila->Tam = 0;
}

int FilaVazia(TipoFila *Fila)
{
    return (Fila->Inicio == NULL);
}

void Enfileirar(TipoFila *Fila, int v)
{
    TipoApontador pNovo;

    pNovo = (TipoApontador)malloc(sizeof(TipoCelula));
    pNovo->Item = v;
    pNovo->Prox = NULL;

    if (FilaVazia(Fila))
        Fila->Inicio = pNovo;
    else
        Fila->Fim->Prox = pNovo;

    Fila->Fim = pNovo;
    Fila->Tam++;
}

int Desenfileirar(TipoFila *Fila)
{
    TipoApontador pNovo;
    int u;

    if (FilaVazia(Fila))
        return -1;

    pNovo = Fila->Inicio;
    Fila->Inicio = pNovo->Prox;
    u = pNovo->Item;
    free(pNovo);
    Fila->Tam--;

    return u;
}

int DFS(TipoGrafo *Grafo, int v, int w, int Vertices)
{
    TipoFila *Fila;
    int Nivel[Vertices], Visitado[Vertices], u, i;

    Fila = malloc(sizeof(TipoFila));
    FilaInit(Fila);

    Visitado[v] = 1;
    Enfileirar(Fila, v);

    for (i = 0; i < Vertices; i++)
        Nivel[i] = -1;

    Nivel[v] = 0;

    while (!FilaVazia(Fila))
    {
        u = Desenfileirar(Fila);
        printf("%d ", u);
        for (i = 0; i < Vertices; i++)
        {
            if (Grafo->adj[u][i] == 1 && Visitado[i] == 0)
            {
                Visitado[i] = 1;
                Enfileirar(Fila, i);
                Nivel[i] = Nivel[u] + 1;
            }
        }
    }

    for (i = 0; i < Vertices; i++)
        printf("%d ", Nivel[i]);
    printf("\n");

    free(Fila);
    return Nivel[w];
}

int main()
{
    TipoGrafo *Grafo;
    TipoVertice Vertice;
    char Carac, Mapa[30][MAX];
    int l, i, j = 0, k = 0, m = 0, n = 0, r = 0, CaracEspecial[3]; // 0 = $, 1 = *, 2 = +;

    scanf("%d ", &l);

    Grafo = malloc(sizeof(Grafo));
    GrafoInit(Grafo, l * MAX);

    for (i = 0; i < l; i++)
    {
        fgets(Mapa[i], MAX, stdin);
        Mapa[i][strlen(Mapa[i])] = '\0';
    }

    for (i = 0; i < l; i++)
    { // Liga as Vertices horizontalmente
        while (j < strlen(Mapa[i]))
        {
            if ((Mapa[i][j] == ' ' || Mapa[i][j] == '+' || Mapa[i][j] == '*' || Mapa[i][j] == '$') && (Mapa[i][j + 1] == ' ' || Mapa[i][j + 1] == '+' || Mapa[i][j + 1] == '*' || Mapa[i][j + 1] == '$'))
            {
                Vertice.i = k;
                Vertice.j = k + 1;
                GrafoInsere(Grafo, Vertice);
                if (Mapa[i][j] == '$')
                    CaracEspecial[0] = k;
                else if (Mapa[i][j] == '*')
                    CaracEspecial[1] = k;
                else if (Mapa[i][j] == '+')
                    CaracEspecial[2] = k;
                k++; // Quantidade de Vertices do Grafo
            }
            else if (Mapa[i][j] == ' ' || Mapa[i][j] == '+' || Mapa[i][j] == '*' || Mapa[i][j] == '$')
            {
                if (Mapa[i][j] == '$')
                    CaracEspecial[0] = k;
                else if (Mapa[i][j] == '*')
                    CaracEspecial[1] = k;
                else if (Mapa[i][j] == '+')
                    CaracEspecial[2] = k;
                k++;
            }
            j++;
        }
        j = 0;
    }

    k = 0;
    for (i = 0; i < l; i++)
    { // Liga as vertices verticalmente
        while (j < strlen(Mapa[i]))
        {
            if ((Mapa[i][j] == ' ' || Mapa[i][j] == '+' || Mapa[i][j] == '*' || Mapa[i][j] == '$') && (Mapa[i + 1][j] == ' ' || Mapa[i + 1][j] == '+' || Mapa[i + 1][j] == '*' || Mapa[i + 1][j] == '$'))
            {
                Vertice.i = k;
                m = j + 1;
                for (n = i; n <= i + 1; n++)
                {
                    while (m < strlen(Mapa[n]) && m != j)
                    { // Verifica quantas vertices existem ate a posição abaixo
                        if (Mapa[n][m] == ' ' || Mapa[n][m] == '+' || Mapa[n][m] == '*' || Mapa[n][m] == '$')
                            r++;
                        m++;
                    }
                    m = 0;
                }
                r++; // Quantidade de vertices ate a posição abaixo, incluindo a mesma
                Vertice.j = k + r;
                GrafoInsere(Grafo, Vertice);
                k++;
                r = 0;
            }
            else if (Mapa[i][j] == ' ' || Mapa[i][j] == '+' || Mapa[i][j] == '*' || Mapa[i][j] == '$')
                k++;
            j++;
        }
        j = 0;
    }

    int Asterisco = DFS(Grafo, CaracEspecial[0], CaracEspecial[1], k);
    int Mais = DFS(Grafo, CaracEspecial[0], CaracEspecial[2], k);

    if (Asterisco < Mais)
        printf("1");
    else if (Mais < Asterisco)
        printf("2");
    else if (Mais == Asterisco)
        printf("0");
    else if (Mais == -1 && Asterisco == -1)
        printf("-1");

    printf("\n");

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
            printf("%d ", Grafo->adj[i][j]);
        printf("\n");
    }

    free(Grafo);
    return 0;
}