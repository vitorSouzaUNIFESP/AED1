/*1 Implemente um programa em C que utiliza a estrutura
apresentada para implementar uma lista. O programa
deve mostrar ao usuario duas opc¸ ´ oes. Se o usu ˜ ario ´
escolher 1, a lista deve ser impressa; se escolher 2, ele
deve entrar com o valor do conteudo do novo elemento da ´
lista.*/

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *prox;
}celula;

void insere(int x, celula *lst){
    celula *nova = (celula*)malloc(sizeof(celula));
    nova->valor = x;
    nova->prox = lst->prox;
    lst->prox = nova;
}

void imprime(celula *lst){
    celula *p;
    printf("conteudo da lista;\n");
    for(p = lst->prox; p != NULL; p = p->prox){
        printf("%s\n", p->prox);
    }
    print("\n");
}

int main() {
    int escolha, novoElemento;
    celula lista;
    lista.prox = NULL;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Imprimir lista\n");
        printf("2. Inserir novo elemento\n");
        printf("0. Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                imprime(&lista);
                break;
            case 2:
                printf("Digite o valor do novo elemento: ");
                scanf("%d", &novoElemento);
                insere(novoElemento, &lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
