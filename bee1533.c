#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura "Individuo"
typedef struct Individuo {
    unsigned short identificador; // Suspeito
    unsigned short indice;        // Posição original
} Individuo;

// Função de comparação para a ordenação
int compara(const void *a, const void *b);

int main() {
    unsigned short i;
    unsigned short numeroDeIndividuos;

    // Loop infinito até que o número de indivíduos seja 0
    while (true) {
        scanf("%hu", &numeroDeIndividuos);

        // Se o número de indivíduos for 0, termina o loop
        if (numeroDeIndividuos == 0)
            break;

        // Criação do array de indivíduos
        Individuo individuos[numeroDeIndividuos];

        // Leitura dos identificadores dos indivíduos e atribuição de suas posições originais
        for (i = 0; i < numeroDeIndividuos; i++) {
            scanf("%hu", &individuos[i].identificador);
            individuos[i].indice = i;
        }

        // Ordenação dos indivíduos utilizando a função de comparação
        qsort(individuos, numeroDeIndividuos, sizeof(Individuo), compara);

        // Impressão da posição original do segundo maior identificador (posicionado na segunda posição após a ordenação)
        printf("%hu\n", individuos[1].indice + 1);
    }

    return 0;
}

// Função de comparação utilizada pelo qsort
int compara(const void *a, const void *b) {
    if ((*(struct Individuo *)a).identificador == (*(struct Individuo *)b).identificador)
        return 0;
    else if ((*(struct Individuo *)a).identificador > (*(struct Individuo *)b).identificador)
        return -1;
    else
        return 1;
}
