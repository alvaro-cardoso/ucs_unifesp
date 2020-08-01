#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Racionais.c"

int main() {

TNumeroRacional Fracao1, Fracao2;

TRacional_Atribui(&Fracao1, &Fracao2);

TRacional_Soma(&Fracao1, &Fracao2);

TRacional_Subtracao (&Fracao1, &Fracao2);

TRacional_Multiplica (&Fracao1, &Fracao2);

TRacional_Divide(&Fracao1, &Fracao2);

TRacional_Testa(&Fracao1, &Fracao2);

return 0;

}


