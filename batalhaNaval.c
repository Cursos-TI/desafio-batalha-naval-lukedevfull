#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Declaração da função
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

// Definição da função
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro a partir da posição (%d, %d).\n", linha, coluna);
        return 0; // Retorna 0 para indicar falha
    }

    // Verifica se as posições estão livres (não sobrepõe outro navio)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("Erro: Navio horizontal sobrepõe outro navio na posição (%d, %d).\n", linha, coluna + i);
            return 0; // Retorna 0 para indicar falha
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    return 1; // Retorna 1 para indicar sucesso
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro a partir da posição (%d, %d).\n", linha, coluna);
        return 0; // Retorna 0 para indicar falha
    }

    // Verifica se as posições estão livres (não sobrepõe outro navio)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("Erro: Navio vertical sobrepõe outro navio na posição (%d, %d).\n", linha + i, coluna);
            return 0; // Retorna 0 para indicar falha
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1; // Retorna 1 para indicar sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0s (água)
    inicializarTabuleiro(tabuleiro);

    // Posiciona o navio horizontalmente
    int linha_horizontal = 2, coluna_horizontal = 3; // Coordenadas iniciais
    if (!posicionarNavioHorizontal(tabuleiro, linha_horizontal, coluna_horizontal)) {
        return 1; // Encerra o programa se não for possível posicionar o navio
    }

    // Posiciona o navio verticalmente
    int linha_vertical = 5, coluna_vertical = 7; // Coordenadas iniciais
    if (!posicionarNavioVertical(tabuleiro, linha_vertical, coluna_vertical)) {
        return 1; // Encerra o programa se não for possível posicionar o navio
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}