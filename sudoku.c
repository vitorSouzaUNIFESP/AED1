#include <stdio.h>
#include <stdbool.h>

// Função para verificar se uma matriz é uma solução válida do Sudoku
bool verificarSudoku(int matriz[9][9]) {
    int linhas[9][9] = {0};
    int colunas[9][9] = {0};
    int regioes[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = matriz[i][j] - 1;

            if (linhas[i][num] || colunas[j][num] || regioes[(i / 3) * 3 + (j / 3)][num]) {
                return false;
            }

            linhas[i][num] = colunas[j][num] = regioes[(i / 3) * 3 + (j / 3)][num] = 1;
        }
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int matriz[9][9];

        // Lendo a matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        // Verificando se é uma solução do Sudoku
        printf("Instancia %d\n", instancia);
        if (verificarSudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
