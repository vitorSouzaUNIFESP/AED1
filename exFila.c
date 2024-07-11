//Faça uma função que receba uma fila como argumento e retorne o valor armazenado em seu inicio. A função deve também remover esse elemento


#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* proximo;
} Nodo;

typedef struct Fila {
    Nodo* inicio;
    Nodo* fim;
} Fila;

// Função para inicializar a fila
Fila* inicializarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

// Função para adicionar um elemento à fila
void enfileirar(Fila* fila, int valor) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    novoNodo->valor = valor;
    novoNodo->proximo = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novoNodo;
    } else {
        fila->fim->proximo = novoNodo;
    }
    fila->fim = novoNodo;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

// Função para remover e retornar o valor do início da fila
int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: a fila está vazia.\n");
        exit(1);
    }
    Nodo* temp = fila->inicio;
    int valor = temp->valor;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
    return valor;
}

// Função para liberar a memória da fila
void liberarFila(Fila* fila) {
    while (!filaVazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

// Função principal para testar a fila
int main() {
    Fila* minhaFila = inicializarFila();
    enfileirar(minhaFila, 10);
    enfileirar(minhaFila, 20);
    enfileirar(minhaFila, 30);

    printf("Valor desenfileirado: %d\n", desenfileirar(minhaFila)); // Deve imprimir 10
    printf("Valor desenfileirado: %d\n", desenfileirar(minhaFila)); // Deve imprimir 20

    liberarFila(minhaFila);
    return 0;
}
