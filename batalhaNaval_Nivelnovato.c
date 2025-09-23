#include <stdio.h>

#define tamanho 10   // tamanho do tabuleiro
#define navio 3  // valor que representa navio

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro[tamanho][tamanho];
    int i, j;

// Nível Novato - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
                      
    for (i = 0; i < tamanho; i++) {
      for (j = 0; j < tamanho; j++) {
      tabuleiro[i][j] = 0;
    }
}

int tamanhoNavio = 3;

// Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
                                                                     
                                                                         
int linhaH = 2, colunaH = 1;  
int linhaV = 5, colunaV = 7;  

// Coloca navio horizontal
    for (j = 0; j < tamanhoNavio; j++) {
        tabuleiro[linhaH][colunaH + j] = navio;
     }

// Coloca navio vertical
    for (i = 0; i < tamanhoNavio; i++) {
         tabuleiro[linhaV + i][colunaV] = navio;
}
// Exibe o tabuleiro
        printf("=== TABULEIRO BATALHA NAVAL ===\n\n   ");
// Cabeçalho com letras A-J
    for (j = 0; j < tamanho; j++) {
         printf(" %c ", 'A' + j);
}
    printf("\n");
// Exibe cada linha (numerada de 1 a 10)
    for (i = 0; i < tamanho; i++) {
        printf("%2d ", i + 1);  // número da linha (1–10)
    for (j = 0; j < tamanho; j++) {
        printf("%2d ", tabuleiro[i][j]);
}
    printf("\n");
}
// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
 // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1
                                                                                                                                                                                                                                                                         
// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0

return 0;
}
