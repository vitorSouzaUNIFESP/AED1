#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Estrutura para armazenar palavras
typedef struct {
    char texto[201];
} Palavra;

bool buscaString(char *, Palavra *, unsigned);
void quickSortPalavras(Palavra *dicionario, int tamanho);
void quickSortInterno(Palavra *dicionario, int inicio, int fim);

int main() {
    unsigned indiceEntrada, indiceSaida, contadorPalavras = 0;
    char entradaTemporaria[201], saidaTemporaria[201];
    Palavra dicionario[5050];

    // Inicializa o dicionário com zeros
    memset(dicionario, 0, sizeof(dicionario));

    // Lê entradas até o final do arquivo (EOF)
    while (scanf(" %[^\n]", entradaTemporaria) != EOF) {
        indiceEntrada = indiceSaida = 0;

        // Processa cada caractere da string de entrada
        while (entradaTemporaria[indiceEntrada]) {
            // Converte letras para minúsculas e armazena na string de saída temporária
            while (isalpha(entradaTemporaria[indiceEntrada]))
                saidaTemporaria[indiceSaida++] = tolower(entradaTemporaria[indiceEntrada++]);

            // Se a string chegou ao fim, verifica se a palavra é nova e a insere no dicionário
            if (entradaTemporaria[indiceEntrada] == '\0') {
                saidaTemporaria[indiceSaida] = '\0';

                if (!buscaString(saidaTemporaria, dicionario, contadorPalavras))
                    strcpy(dicionario[contadorPalavras++].texto, saidaTemporaria);

                indiceSaida = 0;
                memset(saidaTemporaria, 0, sizeof(saidaTemporaria));
                break;
            }

            saidaTemporaria[indiceSaida] = '\0';

            // Ignora caracteres que não são letras
            while (!isalpha(entradaTemporaria[indiceEntrada])) {
                indiceEntrada++;
                if (entradaTemporaria[indiceEntrada] == '\0')
                    break;
            }

            // Verifica se a palavra é nova e a insere no dicionário
            if (!buscaString(saidaTemporaria, dicionario, contadorPalavras))
                strcpy(dicionario[contadorPalavras++].texto, saidaTemporaria);

            indiceSaida = 0;
            memset(saidaTemporaria, 0, sizeof(saidaTemporaria));
        }

        memset(entradaTemporaria, 0, sizeof(entradaTemporaria));
    }

    // Ordena o dicionário em ordem alfabética
    quickSortPalavras(dicionario, contadorPalavras);

    // Verifica se há uma string nula na primeira posição do dicionário
    indiceSaida = 0;
    if (strcmp(dicionario[0].texto, "\0") == 0)
        indiceSaida = 1;

    // Imprime as palavras do dicionário
    for (; indiceSaida < contadorPalavras; indiceSaida++)
        printf("%s\n", dicionario[indiceSaida].texto);
}

// Função para buscar uma string no dicionário
bool buscaString(char *str, Palavra *dicionario, unsigned tamanho) {
    for (unsigned i = 0; i < tamanho; i++) {
        if (strcmp(dicionario[i].texto, str) == 0)
            return true;
    }
    return false;
}

// Função de ordenação QuickSort
void quickSortInterno(Palavra *dicionario, int inicio, int fim) {
    Palavra pivo, temp;
    int i, j;

    if (fim - inicio > 0) {
        if (inicio < fim) {
            i = inicio;
            j = fim;
            pivo = dicionario[(i + j) / 2];

            do {
                while (strcmp(dicionario[i].texto, pivo.texto) < 0)
                    i++;
                while (strcmp(dicionario[j].texto, pivo.texto) > 0)
                    j--;

                if (i <= j) {
                    temp = dicionario[i];
                    dicionario[i] = dicionario[j];
                    dicionario[j] = temp;
                    i++;
                    j--;
                }
            } while (i <= j);

            quickSortInterno(dicionario, inicio, j);
            quickSortInterno(dicionario, i, fim);
        }
    }
}

// Função que inicia a ordenação QuickSort
void quickSortPalavras(Palavra *dicionario, int tamanho) {
    quickSortInterno(dicionario, 0, tamanho - 1);
}
