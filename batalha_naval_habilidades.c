
#include <stdio.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // Habilidade
        }
        printf("\n");
    }
    printf("\n");
}

// Função para inicializar o tabuleiro com água e alguns navios
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Exemplo de navios
    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][6] = 3;
}

// Função para sobrepor a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origem_linha - TAM_HABILIDADE / 2 + i;
            int coluna = origem_coluna - TAM_HABILIDADE / 2 + j;

            if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

// Função para construir uma matriz de habilidade em forma de cone (apontando para baixo)
void construirCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para construir uma matriz de habilidade em forma de cruz
void construirCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para construir uma matriz de habilidade em forma de octaedro (losango)
void construirOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Habilidade Cone
    construirCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);
    printf("Tabuleiro com habilidade Cone:\n");
    exibirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro); // resetar
    construirCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    printf("Tabuleiro com habilidade Cruz:\n");
    exibirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro); // resetar
    construirOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 6, 6);
    printf("Tabuleiro com habilidade Octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
