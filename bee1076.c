#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAX 110

// Vetor para marcar os vértices visitados
int visitado[TAMANHO_MAX];
// Matriz de adjacência para representar o grafo
char grafo[TAMANHO_MAX][TAMANHO_MAX];

// Variáveis globais para armazenar o número de vértices e o resultado
int num_vertices, resultado;

// Função para realizar a busca em profundidade (DFS)
void buscaProfundidade(int);

int main(int argc, char **argv)
{
    int num_casos, num_arestas;
    int vertice_inicio, vertice_fim;
    int aresta_inicio, aresta_fim;
    int i;

    // Lê o número de casos de teste
    scanf("%d", &num_casos);

    while (num_casos--)
    {
        // Lê o número de vértices e arestas
        scanf("%d", &num_vertices);
        scanf("%d %d", &vertice_inicio, &vertice_fim);

        // Inicializa as estruturas
        memset(visitado, FALSO, sizeof(visitado));
        memset(grafo, FALSO, sizeof(grafo));

        // Lê as arestas e preenche a matriz de adjacência
        for (i = 0; i < vertice_fim; ++i)
        {
            scanf("%d %d", &aresta_inicio, &aresta_fim);
            grafo[aresta_inicio][aresta_fim] = grafo[aresta_fim][aresta_inicio] = VERDADEIRO;
        }

        // Inicializa o resultado e inicia a busca em profundidade
        resultado = 0;
        buscaProfundidade(num_vertices);
        printf("%d\n", resultado << 1);
    }

    return 0;
}

// Função para realizar a busca em profundidade
void buscaProfundidade(int vertice_atual)
{
    int i;
    visitado[vertice_atual] = VERDADEIRO;

    for (i = 0; i < num_vertices; ++i)
    {
        if (grafo[vertice_atual][i])
        {
            if (!visitado[i])
            {
                buscaProfundidade(i);
                resultado++;
            }
        }
    }
}
