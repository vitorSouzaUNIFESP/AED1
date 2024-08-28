#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tipoDado {
    char nome[100];
    unsigned qtsUnidades;
} tipoDado;

// Definição da estrutura de árvore binária
typedef struct noArvore {
    tipoDado dado;
    struct noArvore *direita;
    struct noArvore *esquerda;
} noArvore;

noArvore* inserir(noArvore *arvore, tipoDado dado);
void exibir(noArvore *arvore);
void apagar(noArvore *arvore);
unsigned qtsNos;

int main(void) {
    char lixo;
    unsigned qtsCasos;
    char string[100] = {0};

    // Leitura da quantidade de casos
    scanf("%u", &qtsCasos);
    scanf("%c%[^\n]", &lixo, string);

    while (qtsCasos--) {
        qtsNos = 0;
        noArvore *arvore = NULL;

        while (true) {
            tipoDado dado = {0};
            
            // Leitura da string
            scanf("%c%[^\n]", &lixo, string);

            // Se a string for vazia, inicia um novo caso
            if (!strlen(string)) {
                break;
            }

            // Copia a string para a struct
            strcpy(dado.nome, string);
            dado.qtsUnidades = 1;  // Inicializa a quantidade de unidades

            // Insere a struct na árvore
            arvore = inserir(arvore, dado);
            qtsNos++;

            // Reseta o conteúdo da string para a próxima iteração
            memset(string, 0, sizeof(string));
        }

        exibir(arvore);
        apagar(arvore);

        if (qtsCasos) {
            printf("\n");
        }
    }

    return 0;
}

// Função para inserir elementos na árvore
noArvore* inserir(noArvore *arvore, tipoDado dado) {
    if (!arvore) {
        arvore = (noArvore *) malloc(sizeof(noArvore));
        arvore->dado = dado;
        arvore->dado.qtsUnidades = 1;
        arvore->direita = arvore->esquerda = NULL;
    } else if (strcmp(arvore->dado.nome, dado.nome) > 0) {
        arvore->esquerda = inserir(arvore->esquerda, dado);
    } else if (strcmp(arvore->dado.nome, dado.nome) < 0) {
        arvore->direita = inserir(arvore->direita, dado);
    } else {
        arvore->dado.qtsUnidades++;
    }

    return arvore;
}

// Função para exibir os elementos da árvore
void exibir(noArvore *arvore) {
    if (arvore) {
        exibir(arvore->esquerda);
        printf("%s %.4lf\n", arvore->dado.nome, (arvore->dado.qtsUnidades * 100.0f) / qtsNos);
        exibir(arvore->direita);
    }
}

// Função para apagar a árvore
void apagar(noArvore *arvore) {
    if (!arvore) return;

    apagar(arvore->esquerda);
    apagar(arvore->direita);
    free(arvore);
}
