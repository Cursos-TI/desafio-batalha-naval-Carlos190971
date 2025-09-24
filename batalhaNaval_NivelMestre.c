#include <stdio.h>

#define tamanho 10   

// Função para imprimir uma matriz quadrada N x N
void imprimirMatriz(int matriz[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Preenche matriz com 0
void inicializarMatriz(int matriz[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Habilidade em CONE (origem no topo, expandindo para baixo)
void habilidadeCone(int matriz[tamanho][tamanho], int inicioLinha, int inicioColuna, int altura) {
    for (int i = 0; i < altura; i++) {
        int largura = 2 * i + 1;  
        int inicio = inicioColuna - i;  
        for (int j = 0; j < largura; j++) {
            if (inicioLinha + i < tamanho && inicio + j >= 0 && inicio + j < tamanho) {
                matriz[inicioLinha + i][inicio + j] = 1;
            }
        }
    }
}

// Habilidade em CRUZ
void habilidadeCruz(int matriz[tamanho][tamanho], int linha, int coluna, int alcance) {
    matriz[linha][coluna] = 1; // centro
    for (int i = 1; i <= alcance; i++) {
        if (linha - i >= 0) matriz[linha - i][coluna] = 1; // cima
        if (linha + i < tamanho) matriz[linha + i][coluna] = 1; // baixo
        if (coluna - i >= 0) matriz[linha][coluna - i] = 1; // esquerda
        if (coluna + i < tamanho) matriz[linha][coluna + i] = 1; // direita
    }
}

// Habilidade em OCTAEDRO (em forma de losango)
void habilidadeOctaedro(int matriz[tamanho][tamanho], int linha, int coluna, int raio) {
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (linha + i >= 0 && linha + i < tamanho &&
                coluna + j >= 0 && coluna + j < tamanho) {
                if (abs(i) + abs(j) <= raio) {  
                    matriz[linha + i][coluna + j] = 1;
                }
            }
        }
    }
}

int main() {
    int cone[tamanho][tamanho];
    int cruz[tamanho][tamanho];
    int octaedro[tamanho][tamanho];

    // Cone
    inicializarMatriz(cone);
    habilidadeCone(cone, 0, tamanho/2, 4); // origem no topo centro
    printf("=== Habilidade CONE ===\n");
    imprimirMatriz(cone);

    // Cruz
    inicializarMatriz(cruz);
    habilidadeCruz(cruz, tamanho/2, tamanho/2, 4); // centro do tabuleiro
    printf("=== Habilidade CRUZ ===\n");
    imprimirMatriz(cruz);

    // Octaedro
    inicializarMatriz(octaedro);
    habilidadeOctaedro(octaedro, tamanho/2, tamanho/2, 3); // centro, raio 3
    printf("=== Habilidade OCTAEDRO ===\n");
    imprimirMatriz(octaedro);

    return 0;
}
