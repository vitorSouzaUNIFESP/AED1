#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 102
#define TAMANHO_MAPA 1000000 // Tamanho máximo estimado para o mapa (ajustar conforme necessário)

// Vetores para armazenar os dados das pilhas
int pilha[3][MAX];
int n; // Número de elementos

// Função para realizar a busca recursiva
bool verificarCombinacao(int, int, int);

// Função de hash simples para mapear strings para índices
unsigned int funcaoHash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TAMANHO_MAPA;
}

// Array para simular um mapa
int mapa[TAMANHO_MAPA];

// Verifica se uma string está no mapa
bool estaNoMapa(const char *s) {
    unsigned int indice = funcaoHash(s);
    return mapa[indice] != 0;
}

// Adiciona uma string ao mapa com um valor
void adicionarAoMapa(const char *s, int valor) {
    unsigned int indice = funcaoHash(s);
    mapa[indice] = valor;
}

// Função recursiva para verificar as combinações válidas
bool verificarCombinacao(int a, int b, int c) {
    char chave[12]; // Para armazenar a string de até 3 dígitos
    snprintf(chave, sizeof(chave), "%d%d%d", a, b, c);

    // Verifica se a combinação é válida
    if (a == b && b == c && c == n) {
        adicionarAoMapa(chave, 1);
        return true;
    }

    // Verifica se a combinação já foi processada
    if (estaNoMapa(chave)) {
        return (mapa[funcaoHash(chave)] == 1);
    }

    // Verifica todas as combinações possíveis
    if (a < n && pilha[0][a] % 3 == 0 && verificarCombinacao(a + 1, b, c)) {
        adicionarAoMapa(chave, 1);
        return true;
    }
    if (b < n && pilha[1][b] % 3 == 0 && verificarCombinacao(a, b + 1, c)) {
        adicionarAoMapa(chave, 1);
        return true;
    }
    if (c < n && pilha[2][c] % 3 == 0 && verificarCombinacao(a, b, c + 1)) {
        adicionarAoMapa(chave, 1);
        return true;
    }
    if (a < n && b < n && (pilha[0][a] + pilha[1][b]) % 3 == 0 && verificarCombinacao(a + 1, b + 1, c)) {
        adicionarAoMapa(chave, 1);
        return true;
    }
    if (a < n && c < n && (pilha[0][a] + pilha[2][c]) % 3 == 0 && verificarCombinacao(a + 1, b, c + 1)) {
        adicionarAoMapa(chave, 1);
        return true;
    }
    if (b < n && c < n && (pilha[1][b] + pilha[2][c]) % 3 == 0 && verificarCombinacao(a, b + 1, c + 1)) {
        adicionarAoMapa(chave, 1);
        return true;
    }
    if (a < n && b < n && c < n && (pilha[0][a] + pilha[1][b] + pilha[2][c]) % 3 == 0 && verificarCombinacao(a + 1, b + 1, c + 1)) {
        adicionarAoMapa(chave, 1);
        return true;
    }

    // Marca a combinação como não válida
    adicionarAoMapa(chave, 2);
    return false;
}

int main() {
    while (1) {
        // Lê o número de elementos
        scanf("%d", &n);

        // Caso o número de elementos seja 0, encerra o programa
        if (n == 0) {
            return 0;
        }

        // Lê os dados das pilhas
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &pilha[j][i]);
            }
        }

        // Inicializa o mapa
        memset(mapa, 0, sizeof(mapa));

        // Verifica se é possível formar uma combinação válida e imprime o resultado
        if (verificarCombinacao(0, 0, 0)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}
