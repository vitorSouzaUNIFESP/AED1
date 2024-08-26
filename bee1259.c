#include <stdlib.h>
#include <stdio.h>

// Função de comparação personalizada para o qsort
int comparar(const void *a, const void *b)
{
    int numeroA = *(int *)a;
    int numeroB = *(int *)b;

    // Verifica se numeroA é par
    int parA = numeroA % 2 == 0;
    // Verifica se numeroB é par
    int parB = numeroB % 2 == 0;

    // Ordena os números pares antes dos ímpares
    if (parA && !parB)
        return -1;
    if (!parA && parB)
        return 1;

    // Se ambos são pares ou ímpares, ordena em ordem crescente
    if (parA && parB)
        return numeroA - numeroB;
    if (!parA && !parB)
        return numeroB - numeroA;

    return 0; // Deveria nunca ser alcançado
}

int main()
{
    int quantidade;
    int numeros[100000];

    // Lê o número de elementos
    scanf("%d", &quantidade);

    // Lê os elementos do array
    for (int i = 0; i < quantidade; ++i)
    {
        scanf("%d", &numeros[i]);
    }

    // Ordena o array com base na função de comparação
    qsort(numeros, quantidade, sizeof(int), comparar);

    // Imprime os elementos ordenados
    for (int i = 0; i < quantidade; ++i)
    {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
