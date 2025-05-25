
#include <stdio.h>

#define MAX_NOME_CIDADE 100
#define MAX_CODIGO_CARTA 5

// Estrutura para armazenar as informações de uma carta
typedef struct {
    char estado;
    char codigoCarta[MAX_CODIGO_CARTA];
    char nomeCidade[MAX_NOME_CIDADE];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

int main() {
    // Definindo duas cartas
    Carta carta1, carta2;
    
    // Entrada de dados para a primeira carta
    printf("Digite as informacoes para a Carta 1:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta1.estado); // O espaço antes de %c é para ignorar o '\n' que pode ficar no buffer
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", carta1.codigoCarta);
    printf("Nome da Cidade: ");
    scanf(" %[^
]", carta1.nomeCidade); // Lê até a nova linha
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Entrada de dados para a segunda carta
    printf("\nDigite as informacoes para a Carta 2:\n");
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da Carta (ex: B02): ");
    scanf("%s", carta2.codigoCarta);
    printf("Nome da Cidade: ");
    scanf(" %[^
]", carta2.nomeCidade);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Exibindo as informações das cartas
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Codigo: %s\n", carta1.codigoCarta);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("Populacao: %d\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta1.pontosTuristicos);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Codigo: %s\n", carta2.codigoCarta);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("Populacao: %d\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta2.pontosTuristicos);

    return 0;
}
