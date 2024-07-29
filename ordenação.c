#include <stdlib.h>
#include <stdio.h>

// Função de comparação usada pelo qsort para ordenar os números em ordem decrescente
int comparar(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int numTestes, numElementos, resultado;
    int vetorOriginal[1000], vetorOrdenado[1000];

    // Leitura do número de testes
    scanf("%d", &numTestes);

    // Loop para cada teste
    for (int k = 0; k < numTestes; ++k)
    {
        // Leitura do número de elementos no teste atual
        scanf("%d", &numElementos);

        // Leitura dos elementos e cópia para outro vetor
        for (int i = 0; i < numElementos; ++i)
        {
            scanf("%d", &vetorOriginal[i]);
            vetorOrdenado[i] = vetorOriginal[i];
        }

        // Ordenação do vetor usando qsort e a função de comparação
        qsort(vetorOrdenado, numElementos, sizeof(int), comparar);

        // Contagem de elementos que permanecem na mesma posição após a ordenação
        resultado = 0;
        for (int i = 0; i < numElementos; ++i)
        {
            if (vetorOriginal[i] == vetorOrdenado[i])
                ++resultado;
        }

        // Impressão do resultado
        printf("%d\n", resultado);
    }

    return 0;
}
