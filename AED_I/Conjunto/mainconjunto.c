#include <stdio.h>
#include<stdlib.h>
#include"TConjunto.c"

void main () {

    TVet ConjuntoA, ConjuntoB;

    TConjunto_Inicia(&ConjuntoA);

    TConjunto_Leconjunto(&ConjuntoA);

    TConjunto_Leconjunto(&ConjuntoB);

    TConjunto_Uniao(&ConjuntoA, &ConjuntoB);

    TConjunto_Interseccao(&ConjuntoA, &ConjuntoB);

    TConjunto_Teste(&ConjuntoA, &ConjuntoB);

    TConjunto_ImprimeConjunto(&ConjuntoA);

    TConjunto_ImprimeConjunto(&ConjuntoB);

    return 0;
}
