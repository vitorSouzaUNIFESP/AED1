#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Camiseta
{
    char nome[100];
    char cor[10];
    char tamanho[10];
};

// Função de comparação para qsort
int comparar(const void *a, const void *b)
{
    struct Camiseta *camisetaA = (struct Camiseta *)a;
    struct Camiseta *camisetaB = (struct Camiseta *)b;

    // Primeiro compara a cor
    int cmpCor = strcmp(camisetaA->cor, camisetaB->cor);
    if (cmpCor == 0)
    {
        // Se a cor for igual, compara o tamanho
        int cmpTamanho = strcmp(camisetaA->tamanho, camisetaB->tamanho);
        if (cmpTamanho == 0)
        {
            // Se o tamanho também for igual, compara o nome
            return strcmp(camisetaA->nome, camisetaB->nome);
        }
        return cmpTamanho;
    }
    return cmpCor;
}

int main()
{
    int N;
    int primeiroCaso = 1;
    struct Camiseta camisetas[60];

    while (scanf("%d", &N) == 1)
    {
        if (N == 0)
            break;

        if (!primeiroCaso)
            printf("\n");

        primeiroCaso = 0;

        // Leitura dos dados das camisetas
        for (int i = 0; i < N; ++i)
        {
            scanf(" %[^\n]", camisetas[i].nome);  // Leitura do nome (incluindo espaços)
            scanf("%s %s", camisetas[i].cor, camisetas[i].tamanho);  // Leitura da cor e tamanho
        }

        // Ordena as camisetas
        qsort(camisetas, N, sizeof(struct Camiseta), comparar);

        // Impressão dos resultados
        for (int i = 0; i < N; ++i)
        {
            printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }

    return 0;
}
