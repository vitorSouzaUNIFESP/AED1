#include <stdio.h>

// Definindo um mapa global de 101x101
int mapa[101][101];

// Função para verificar se uma área de 2x2 é segura
int segura(int x, int y) {
    // Soma os valores das posições (x, y), (x+1, y), (x, y+1) e (x+1, y+1) no mapa
    // Se a soma for maior ou igual a 2, retorna 1 (verdadeiro), indicando que a área é segura
    return mapa[x][y] + mapa[x + 1][y] + mapa[x][y + 1] + mapa[x + 1][y + 1] >= 2;
}

int main() {
    int N; // Variável para armazenar o tamanho do mapa

    // Lê o valor de N (tamanho do mapa)
    scanf("%d", &N);
    
    // Lê os valores do mapa de entrada
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            scanf("%d", &mapa[i][j]);
        }
    }

    // Itera sobre o mapa para verificar se as áreas são seguras
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Imprime 'S' se a área for segura, caso contrário imprime 'U'
            printf("%c", segura(i, j) ? 'S' : 'U');
        }
        // Imprime uma nova linha após cada linha do mapa
        printf("\n");
    }

    return 0;
}
