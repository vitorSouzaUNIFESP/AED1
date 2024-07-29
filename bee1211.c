#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição de uma estrutura chamada 'string' que contém um array de caracteres.
typedef struct {
    char s1[250];
} string;

// Array global de 'string' com capacidade para 100050 elementos.
string sstring[100050];

// Função de comparação personalizada para a função qsort.
int compare(const void *, const void *);

int main(int argc, char **argv) {
    unsigned t, i, j;
    
    // Lê a quantidade de strings a serem processadas até o fim do arquivo (EOF).
    while (scanf("%d", &t) != EOF) {
        i = 0;
        unsigned aux = t;

        // Lê as strings e armazena no array 'sstring'.
        while (t--)
            scanf("%s", sstring[i++].s1);

        unsigned ans = 0;

        // Ordena o array de strings usando a função de comparação personalizada.
        qsort(sstring, i, sizeof(string), compare);

        // Conta os prefixos comuns entre strings consecutivas.
        for (i = 1; i < aux; ++i)
            for (j = 0; sstring[i].s1[j]; ++j)
                if (sstring[i].s1[j] == sstring[i - 1].s1[j])
                    ++ans;
                else
                    break;

        // Imprime o número total de prefixos comuns.
        printf("%u\n", ans);
    }

    return 0;
}

// Função de comparação para a qsort.
int compare(const void *a, const void *b) {
    // Converte os ponteiros para o tipo 'string'.
    const string *strA = (const string *)a;
    const string *strB = (const string *)b;

    // Compara as duas strings.
    int aux = strcmp(strA->s1, strB->s1);

    // Retorna valores de acordo com a comparação.
    // Invertido para ordenar em ordem decrescente.
    if (aux == 0)
        return 0;
    else if (aux < 0)
        return 1;
    else
        return -1;
}
