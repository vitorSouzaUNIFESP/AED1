#include <stdlib.h>
#include <stdio.h>

int comparar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int pesquisaBinaria(int *vetor, int tamanho, int valor)
{
    int inicio = 0, fim = tamanho;

    while (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio;
        }
    }

    return vetor[inicio] == valor ? inicio + 1 : -1;
}

int main()
{
    int *marmores;
    int caso, quantidadeMarmores, consultas, consulta, resultado;

    caso = 0;
    while (scanf("%d %d", &quantidadeMarmores, &consultas))
    {
        if (quantidadeMarmores == 0 && consultas == 0)
            break;

        marmores = (int *)malloc(sizeof(int) * quantidadeMarmores);
        for (int i = 0; i < quantidadeMarmores; ++i)
        {
            scanf("%d", &marmores[i]);
        }

        qsort(marmores, quantidadeMarmores, sizeof(int), comparar);

        printf("CASO # %d:\n", ++caso);
        for (int i = 0; i < consultas; ++i)
        {
            scanf("%d", &consulta);

            resultado = pesquisaBinaria(marmores, quantidadeMarmores, consulta);
            if (resultado == -1)
            {
                printf("%d nao encontrado\n", consulta);
            }
            else
            {
                printf("%d encontrado na posicao %d\n", consulta, resultado);
            }
        }

        free(marmores);
    }

    return 0;
}
