#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

int roll_dice() {
    int dado1, dado2, dado3, soma;

    // Gera valores aleatórios entre 1 e 6 para cada dado
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
    dado3 = (rand() % 6) + 1;

    // Calcula a soma dos três dados
    soma = dado1 + dado2 + dado3;

    return soma;
}

int eh_par(int numero) {
    return numero % 2 == 0;
}
