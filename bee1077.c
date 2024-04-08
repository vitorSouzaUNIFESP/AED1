#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a estrutura de nó para a pilha
struct No {
    char dado;
    struct No* proximo;
};

// Função para criar um novo nó
struct No* novoNo(char dado) {
    struct No* no = (struct No*)malloc(sizeof(struct No));
    no->dado = dado;
    no->proximo = NULL;
    return no;
}

// Função para verificar se a pilha está vazia
int estaVazia(struct No* topo) {
    return (topo == NULL);
}

// Função para empilhar um novo elemento
void empilhar(struct No** topo, char dado) {
    struct No* no = novoNo(dado);
    no->proximo = *topo;
    *topo = no;
}

// Função para desempilhar um elemento
char desempilhar(struct No** topo) {
    if (estaVazia(*topo))
        return '\0';
    struct No* temp = *topo;
    *topo = (*topo)->proximo;
    char desempilhado = temp->dado;
    free(temp);
    return desempilhado;
}

// Função para retornar o topo da pilha sem remover
char topo(struct No* topo) {
    if (estaVazia(topo))
        return '\0';
    return topo->dado;
}

// Função para verificar se o caractere é um operador
int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Função para obter a precedência do operador
int precedencia(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Função para converter expressão infixa para posfixa
void infixaParaPosfixa(char* expressao) {
    struct No* pilha = NULL;
    int i, k;
    for (i = 0, k = -1; expressao[i]; ++i) {
        // Se o caractere atual é alfanumérico, adiciona ao resultado
        if ((expressao[i] >= 'a' && expressao[i] <= 'z') ||
            (expressao[i] >= 'A' && expressao[i] <= 'Z') ||
            (expressao[i] >= '0' && expressao[i] <= '9')) {
            expressao[++k] = expressao[i];
        }
        // Se o caractere atual é '(', empilha
        else if (expressao[i] == '(') {
            empilhar(&pilha, expressao[i]);
        }
        // Se o caractere atual é ')', desempilha e adiciona ao resultado até encontrar '('
        else if (expressao[i] == ')') {
            while (!estaVazia(pilha) && topo(pilha) != '(') {
                expressao[++k] = desempilhar(&pilha);
            }
            desempilhar(&pilha); // Remove '(' da pilha
        }
        // Se o caractere atual é um operador
        else if (ehOperador(expressao[i])) {
            // Desempilha operadores de maior ou igual precedência e adiciona ao resultado
            while (!estaVazia(pilha) && precedencia(topo(pilha)) >= precedencia(expressao[i])) {
                expressao[++k] = desempilhar(&pilha);
            }
            // Empilha o operador atual
            empilhar(&pilha, expressao[i]);
        }
    }
    // Desempilha todos os operadores restantes e adiciona ao resultado
    while (!estaVazia(pilha)) {
        expressao[++k] = desempilhar(&pilha);
    }
    expressao[++k] = '\0'; // Adiciona terminador de string
    printf("%s\n", expressao);
}

// Função principal
int main() {
    int n;
    scanf("%d", &n); // Número de casos de teste
    getchar(); // Limpa o buffer de entrada
    while (n--) {
        char expressao[305]; // Expressão infixa com até 300 caracteres
        fgets(expressao, sizeof(expressao), stdin);
        expressao[strcspn(expressao, "\n")] = '\0'; // Remove o caractere de nova linha
        infixaParaPosfixa(expressao); // Converte para posfixa e imprime
    }
    return 0;
}
