#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar as informações de um dragão
typedef struct {
    int dias;
    int multa;
    double prioridade;
} Dragao;

// Função para calcular a prioridade de um dragão
void calcular_prioridade(Dragao *d) {
    d->prioridade = (double)d->multa / d->dias;
}

// Função para ordenar os dragões com base na prioridade
int comparar_dragao(const void *a, const void *b) {
    Dragao *d1 = (Dragao *)a;
    Dragao *d2 = (Dragao *)b;

    // Ordena em ordem decrescente de prioridade
    if (d1->prioridade < d2->prioridade) return 1;
    if (d1->prioridade > d2->prioridade) return -1;
    return 0;
}

// Função para processar a fila de dragões
void processar_dragao(int n, Dragao *fila) {
    double multadia = 0.0; // Multa paga por dia por todos os dragões
    double multatotal = 0.0; // Resposta
    int treinando = 0;
    int diasrestantes = 0;

    // Processa a fila de dragões
    for (int i = 0; i < n; i++) {
        multadia += fila[i].multa;
        
        if (!treinando || !diasrestantes) {
            multadia -= fila[i].multa;
            diasrestantes = fila[i].dias;
            treinando = 1;
        }
        multatotal += multadia;
        diasrestantes--;
    }

    if (treinando) {
        multatotal += diasrestantes * multadia;
    }

    // Conclui o processamento restante da fila
    for (int i = 0; i < n; i++) {
        multadia -= fila[i].multa;
        multatotal += multadia * fila[i].dias;
    }

    printf("%.lf\n", multatotal);
}

int main(void) {
    int tempo, multa;
    int capacidade = 1000; // Capacidade inicial do array de dragões
    int tamanho = 0; // Número atual de dragões na fila
    Dragao *fila = malloc(capacidade * sizeof(Dragao));

    if (fila == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    while (scanf("%d %d", &tempo, &multa) == 2) {
        // Realloc para ajustar o tamanho do array se necessário
        if (tamanho >= capacidade) {
            capacidade *= 2;
            fila = realloc(fila, capacidade * sizeof(Dragao));
            if (fila == NULL) {
                fprintf(stderr, "Erro ao realocar memória.\n");
                return 1;
            }
        }

        fila[tamanho].dias = tempo;
        fila[tamanho].multa = multa;
        calcular_prioridade(&fila[tamanho]);
        tamanho++;

        // Ordena o array de dragões com base na prioridade
        qsort(fila, tamanho, sizeof(Dragao), comparar_dragao);

        // Processa a fila atual de dragões
        processar_dragao(tamanho, fila);
    }

    // Libera a memória alocada
    free(fila);

    return 0;
}
