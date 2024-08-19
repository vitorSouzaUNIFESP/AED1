#include <stdio.h>
#include <stdlib.h>

#define verdadeiro 1
#define falso 0

typedef struct {
	int origem, destino, peso;
} aresta;

aresta grafo[250];
int pais[70];

// Função para comparar duas arestas (para ordenação)
int comparar(aresta *, aresta *);

// Função para encontrar o componente conectado de um vértice
int encontrar_componente(int);

// Função principal do algoritmo de Kruskal
int kruskal(int);

int main(int argc, char **argv)
{
	int roteadores, arestas, i;

	// Leitura do número de roteadores e arestas
	scanf("%d %d", &roteadores, &arestas);

	// Leitura das arestas
	for (i = 0; i < arestas; ++i)
		scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);

	// Ordena as arestas pelo peso
	qsort(grafo, arestas, sizeof(aresta), comparar);

	// Inicializa o vetor de pais
	for (i = 1; i <= roteadores; ++i)
		pais[i] = i;

	// Executa o algoritmo de Kruskal e imprime o custo total da MST
	printf("%d\n", kruskal(arestas));

	return 0;
}

// Função de comparação para a função qsort
int comparar(aresta *a, aresta *b)
{
	return a->peso - b->peso;
}

// Função para encontrar o componente conectado de um vértice
int encontrar_componente(int i)
{
	if (i == pais[i])
		return i;
	return encontrar_componente(pais[i]);
}

// Função principal do algoritmo de Kruskal
int kruskal(int arestas)
{
	int i, custo_total, v, u;

	custo_total = 0;

	for (i = 0; i < arestas; ++i)
	{
		v = encontrar_componente(grafo[i].origem);
		u = encontrar_componente(grafo[i].destino);

		if (v != u)
		{
			pais[v] = pais[u];
			custo_total += grafo[i].peso;
		}
	}

	return custo_total;
}
