
#include <stdio.h>

// Função recursiva para mover a Torre para cima
void moverTorreCima(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

// Função recursiva para mover a Torre para a direita
void moverTorreDireita(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorreDireita(casas - 1);
}

// Função recursiva para mover o Bispo na diagonal superior direita
void moverBispoDiagonal(int casasVerticais, int casasHorizontais) {
    if (casasVerticais == 0 || casasHorizontais == 0) return;
    printf("Cima e Direita\n");
    moverBispoDiagonal(casasVerticais - 1, casasHorizontais - 1);
}

// Função da Rainha combinando movimentos de Torre e Bispo
void moverRainha(int casasVerticais, int casasHorizontais) {
    moverTorreCima(casasVerticais);
    moverTorreDireita(casasHorizontais);
    printf("Mudando para diagonal...\n");
    moverBispoDiagonal(casasVerticais, casasHorizontais);
}

// Movimento do Cavalo usando loops aninhados com múltiplas variáveis
void moverCavalo(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < 2; j++) {  // Apenas duas casas para cima
            if (j == 1) {
                printf("Cima\n");
                for (int k = 0; k < 1; k++) { // Uma casa para a direita
                    printf("Direita\n");
                }
                break;
            }
            continue;
        }
    }
}

// Bispo com loops aninhados (vertical por fora, horizontal por dentro)
void bispoComLoops(int vertical, int horizontal) {
    for (int i = 0; i < vertical && i < horizontal; i++) {
        for (int j = 0; j < 1; j++) {
            printf("Cima e Direita\n");
        }
    }
}

int main() {
    int casasTorre = 3;
    int casasBispoVertical = 2;
    int casasBispoHorizontal = 2;
    int casasRainhaVertical = 2;
    int casasRainhaHorizontal = 2;
    int movimentosCavalo = 2;

    printf("Movimento da Torre (Recursivo):\n");
    moverTorreCima(casasTorre);
    moverTorreDireita(casasTorre);

    printf("\nMovimento do Bispo (Recursivo):\n");
    moverBispoDiagonal(casasBispoVertical, casasBispoHorizontal);

    printf("\nMovimento da Rainha (Recursivo):\n");
    moverRainha(casasRainhaVertical, casasRainhaHorizontal);

    printf("\nMovimento do Cavalo (Loops Aninhados):\n");
    moverCavalo(movimentosCavalo);

    printf("\nMovimento do Bispo com Loops Aninhados:\n");
    bispoComLoops(casasBispoVertical, casasBispoHorizontal);

    return 0;
}
