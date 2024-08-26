#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Variável global para armazenar o valor de M
int M;

// Função de comparação para a ordenação
int comparar(const void *a, const void *b) {
    int valor_a = *(int *)a;
    int valor_b = *(int *)b;
    
    // Verifica o módulo de M
    if (valor_b % M == valor_a % M) {
        // Caso ambos tenham o mesmo módulo
        if (abs(valor_a) % 2 == abs(valor_b) % 2) {
            // Comparar dois pares ou dois ímpares
            if (valor_a % 2 != 0) {
                // Se ambos são ímpares
                return valor_a > valor_b ? -1 : 1;
            } else {
                // Se ambos são pares
                return valor_a < valor_b ? -1 : 1;
            }
        }
        // Coloca ímpares antes dos pares
        return (abs(valor_a) % 2) > (abs(valor_b) % 2) ? -1 : 1;
    }
    // Ordena de acordo com o módulo de M
    return (valor_a % M) - (valor_b % M);
}

int main() {
    int N;

    // Leitura inicial dos valores de N e M
    scanf("%d", &N);
    scanf("%d", &M);

    while (N != 0 && M != 0) {
        int vetor[N];

        printf("%d %d\n", N, M);

        // Leitura dos elementos do vetor
        for (int cont = 0; cont < N; cont++) {
            scanf("%d", &vetor[cont]);
        }

        // Ordena o vetor usando a função de comparação
        qsort(vetor, N, sizeof(int), comparar);

        // Imprime o vetor ordenado
        for (int cont = 0; cont < N; cont++) {
            printf("%d\n", vetor[cont]);
        }

        // Leitura dos próximos valores de N e M
        scanf("%d", &N);
        scanf("%d", &M);
    }

    printf("0 0\n");

    return 0;
}
