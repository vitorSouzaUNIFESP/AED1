#include <stdio.h>
#include <string.h>

typedef struct {
    char item[21];
} Item;

void insere(Item *array, unsigned short size);

int main() {
    unsigned short cases, i, j;
    Item shoppingList[1010];
    char itemsInput[20010], *eachItem;

    // Ler o número de casos
    scanf("%hu", &cases);

    while (cases--) {
        // Ler a linha de itens
        scanf(" %[^\n]", itemsInput);

        i = 0;
        // Quebrar a linha em substrings
        eachItem = strtok(itemsInput, " ");
        // Salvar cada substring na struct
        strcpy(shoppingList[i++].item, eachItem);

        // Continuar o processo para o restante da linha
        do {
            eachItem = strtok(NULL, " ");
            if (eachItem == NULL)
                break;

            strcpy(shoppingList[i].item, eachItem);
            i++;

        } while (eachItem);

        // Ordenar a lista de itens
        insere(shoppingList, i);

        // Imprimir os itens únicos
        for (j = 0; j < i; j++) {
            if (strcmp(shoppingList[j].item, shoppingList[j - 1].item) != 0) {
                if (j != 0 && j != i)
                    printf(" ");
                printf("%s", shoppingList[j].item);
            }
        }
        printf("\n");

        // Limpar as estruturas de dados para o próximo caso
        memset(shoppingList, 0, sizeof(shoppingList));
        memset(itemsInput, 0, sizeof(itemsInput));
    }

    return 0;
}

// Função para ordenar a lista de itens
void insere(Item *array, unsigned short size) {
    short i = 1, j;
    Item pivot;

    while (i < size) {
        j = i - 1;
        pivot = array[i];

        while (j >= 0 && strcmp(array[j].item, pivot.item) > 0) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = pivot;
        i++;
    }
}
