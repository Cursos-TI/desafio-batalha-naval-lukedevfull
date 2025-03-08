#include <stdio.h>
#include <stdlib.h> // Incluído para usar a função abs

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Tamanho das matrizes de habilidade
#define TAMANHO_HABILIDADE 5

// Valores para representar elementos no tabuleiro
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
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

// Função para criar a matriz de habilidade em forma de Cone
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= i && j < TAMANHO_HABILIDADE - i) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de Cruz
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de Octaedro
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz de habilidade
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tabuleiro = linha + (i - centro);
            int coluna_tabuleiro = coluna + (j - centro);

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = AREA_AFETADA;
                }
            }
        }
    }
}

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0s (água)
    inicializarTabuleiro(tabuleiro);

    // Posiciona um navio horizontalmente
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;

    // Posiciona um navio verticalmente
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    // Cria as matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 1, 1);      // Cone na posição (1, 1)
    aplicarHabilidade(tabuleiro, cruz, 4, 4);      // Cruz na posição (4, 4)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro na posição (7, 7)

    // Exibe o tabuleiro com os navios e as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}