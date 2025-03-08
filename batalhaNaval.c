#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se uma posição está livre
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro a partir da posição (%d, %d).\n", linha, coluna);
        return 0; // Retorna 0 para indicar falha
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha, coluna + i)) {
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

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha + i, coluna)) {
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

// Função para posicionar um navio na diagonal (crescente: linha e coluna aumentam)
int posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal crescente não cabe no tabuleiro a partir da posição (%d, %d).\n", linha, coluna);
        return 0; // Retorna 0 para indicar falha
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha + i, coluna + i)) {
            printf("Erro: Navio diagonal crescente sobrepõe outro navio na posição (%d, %d).\n", linha + i, coluna + i);
            return 0; // Retorna 0 para indicar falha
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }

    return 1; // Retorna 1 para indicar sucesso
}

// Função para posicionar um navio na diagonal (decrescente: linha aumenta, coluna diminui)
int posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) {
        printf("Erro: Navio diagonal decrescente não cabe no tabuleiro a partir da posição (%d, %d).\n", linha, coluna);
        return 0; // Retorna 0 para indicar falha
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (!posicaoLivre(tabuleiro, linha + i, coluna - i)) {
            printf("Erro: Navio diagonal decrescente sobrepõe outro navio na posição (%d, %d).\n", linha + i, coluna - i);
            return 0; // Retorna 0 para indicar falha
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
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

    // Posiciona os navios
    // Navio horizontal
    if (!posicionarNavioHorizontal(tabuleiro, 2, 3)) {
        return 1; // Encerra o programa se não for possível posicionar o navio
    }

    // Navio vertical
    if (!posicionarNavioVertical(tabuleiro, 5, 7)) {
        return 1; // Encerra o programa se não for possível posicionar o navio
    }

    // Navio diagonal crescente
    if (!posicionarNavioDiagonalCrescente(tabuleiro, 1, 1)) {
        return 1; // Encerra o programa se não for possível posicionar o navio
    }

    // Navio diagonal decrescente
    if (!posicionarNavioDiagonalDecrescente(tabuleiro, 0, 9)) {
        return 1; // Encerra o programa se não for possível posicionar o navio
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}