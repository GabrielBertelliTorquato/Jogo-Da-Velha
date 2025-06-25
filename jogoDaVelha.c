#include <stdio.h>
#define TAM 3

// Funções
void inicializarTabuleiro(char tabuleiro[TAM][TAM]);
void exibirTabuleiro(char tabuleiro[TAM][TAM]);
int validarJogada(char tabuleiro[TAM][TAM], int linha, int coluna);
int verificarGanhador(char tabuleiro[TAM][TAM]);
int verificarEmpate(char tabuleiro[TAM][TAM]);
void jogarJogoDaVelha();

// Função principal
int main() {
    jogarJogoDaVelha();
    return 0;
}

// Função que inicializa o tabuleiro com espaços vazios
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função que exibe o tabuleiro na tela 
void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n  1   2   3\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf(" ---+---+---\n");
    }
    printf("\n");
}

// Função que valida se a jogada é possível
int validarJogada(char tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM)
        return 0; // posição inválida
    if (tabuleiro[linha][coluna] != ' ')
        return 0; // já ocupada
    return 1;
}

// Função que verifica se houve ganhador
int verificarGanhador(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2] &&
            tabuleiro[i][0] != ' ')
            return 1;

        if (tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i] &&
            tabuleiro[0][i] != ' ')
            return 1;
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2] &&
        tabuleiro[0][0] != ' ')
        return 1;

    if (tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0] &&
        tabuleiro[0][2] != ' ')
        return 1;

    return 0;
}

// Função que verifica empate
int verificarEmpate(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Função principal de controle do jogo
void jogarJogoDaVelha() {
    char tabuleiro[TAM][TAM];
    char jogador = 'X';
    int linha, coluna;

    inicializarTabuleiro(tabuleiro);

    printf("===== Jogo da Velha =====\n");
    printf("Para sair a qualquer momento digite linha 0 e coluna 0.\n");

    while (1) {
        exibirTabuleiro(tabuleiro);
        printf("Vez do jogador %c.\n", jogador);
        printf("Informe a linha e a coluna (1 a 3): ");
        scanf("%d %d", &linha, &coluna);

        if (linha == 0 && coluna == 0) {
            printf("Jogo encerrado pelo jogador.\n");
            break;
        }

        linha--; coluna--;

        if (!validarJogada(tabuleiro, linha, coluna)) {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador;

        if (verificarGanhador(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Parabéns! Jogador %c venceu!\n", jogador);
            break;
        }

        if (verificarEmpate(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate! Ninguém venceu.\n");
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }
}
