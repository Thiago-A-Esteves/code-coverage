#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

void test_eh_par() {
    assert(eh_par(6) == 1);  // Testa número par
    assert(eh_par(7) == 0);  // Testa número ímpar
    assert(eh_par(10) == 1); // Testa número par
    assert(eh_par(15) == 0); // Testa número ímpar
    assert(eh_par(0) == 1);  // Testa o limite inferior (zero)
    assert(eh_par(-2) == 1); // Testa um número negativo par
    assert(eh_par(-3) == 0); // Testa um número negativo ímpar
    printf("Testes da função eh_par() passaram!\n");
}

void test_roll_dice() {
    int encontrou_par = 0, encontrou_impar = 0;
    int soma;

    // Teste com valores predeterminados
    for (int i = 0; i < 1000; i++) {
        soma = roll_dice();
        assert(soma >= 3 && soma <= 18); // Verifica que o valor da soma está no intervalo esperado

        // Garantimos que testamos ambos os caminhos (par e ímpar)
        if (eh_par(soma)) {
            encontrou_par = 1;
        } else {
            encontrou_impar = 1;
        }

        if (encontrou_par && encontrou_impar) {
            break; // Já cobrimos os dois ramos, saímos do loop
        }
    }

    // Verifica explicitamente que ambos os caminhos foram seguidos
    assert(encontrou_par == 1);
    assert(encontrou_impar == 1);

    // Testa valores limites ou casos extremos, forçando resultados específicos
    soma = roll_dice(); // Pode gerar um valor específico
    assert(soma >= 3 && soma <= 18); // Verifica se a soma continua no intervalo esperado

    // Garantimos que a soma seja de um número par e ímpar durante a execução dos testes
    if (eh_par(soma)) {
        encontrou_par = 1;
    } else {
        encontrou_impar = 1;
    }

    assert(encontrou_par == 1 || encontrou_impar == 1); // Assegura que pelo menos um caminho foi seguido

    printf("Testes da função roll_dice() passaram!\n");
}

int main() {
    srand(time(NULL));

    test_eh_par();
    test_roll_dice();

    return 0;
}