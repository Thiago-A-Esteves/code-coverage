#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

int main() {
    srand(time(NULL));

    int soma = roll_dice();
    printf("A soma dos três dados foi: %d\n", soma);
    
    if (eh_par(soma)) {
        printf("Resultado: PAR\n");
    } else {
        printf("Resultado: ÍMPAR\n");
    }

    return 0;
}