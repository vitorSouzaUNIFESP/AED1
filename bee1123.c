#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
#define MAX_CIDADES 1010

int num_cidades, num_estradas, inicio_rota, destino_final;
int matriz_grafo[MAX_CIDADES][MAX_CIDADES];
int vetor_custo[MAX_CIDADES];
bool visitado[MAX_CIDADES];

void inicializar() {
    for (int i = 0; i <= num_cidades; i++) {
        vetor_custo[i] = INF; // Define o custo inicial como infinito
        visitado[i] = false; // Marca todos os vértices como não visitados
        for (int j = 0; j <= num_cidades; j++) {
            matriz_grafo[i][j] = INF; // Define o custo das arestas como infinito
        }
    }
}

int dijkstra(int origem, int destino) {
    vetor_custo[origem] = 0; // O custo da origem para ela mesma é 0

    for (int i = 0; i < num_cidades; i++) {
        int menor = INF;
        int u = -1;

        // Encontra o vértice com o menor custo
        for (int j = 0; j < num_cidades; j++) {
            if (!visitado[j] && vetor_custo[j] < menor) {
                menor = vetor_custo[j];
                u = j;
            }
        }

        if (u == -1) {
            break; // Todos os vértices foram visitados ou restam apenas vértices inacessíveis
        }

        visitado[u] = true;

        // Atualiza os custos dos vizinhos
        for (int v = 0; v < num_cidades; v++) {
            if (matriz_grafo[u][v] != INF && vetor_custo[u] != INF && vetor_custo[u] + matriz_grafo[u][v] < vetor_custo[v]) {
                vetor_custo[v] = vetor_custo[u] + matriz_grafo[u][v];
            }
        }
    }

    return vetor_custo[destino];
}

int main() {
    while (scanf("%d %d %d %d", &num_cidades, &num_estradas, &inicio_rota, &destino_final) == 4 && (num_cidades || num_estradas || inicio_rota || destino_final)) {
        inicializar(); // Inicializa o grafo e o vetor de custo

        for (int i = 1; i <= num_estradas; i++) { // Para cada estrada
            int cidade1, cidade2, custo_estrada;
            scanf("%d %d %d", &cidade1, &cidade2, &custo_estrada);

            if (cidade1 >= inicio_rota && cidade2 >= inicio_rota) { // Se ambas as cidades estiverem fora da rota
                matriz_grafo[cidade1][cidade2] = custo_estrada; // Adiciona a estrada
                matriz_grafo[cidade2][cidade1] = custo_estrada; // Adiciona a estrada na direção oposta
            }
            if (cidade1 >= inicio_rota && cidade2 < inicio_rota) {
                matriz_grafo[cidade1][cidade2] = custo_estrada; // Adiciona a estrada que chega em cidade2
            }
            if (cidade1 < inicio_rota && cidade2 >= inicio_rota) {
                matriz_grafo[cidade2][cidade1] = custo_estrada; // Adiciona a estrada que chega em cidade1
            }
            if (cidade1 < inicio_rota && cidade2 < inicio_rota && abs(cidade1 - cidade2) == 1) { // Se ambas as cidades estiverem na rota e forem consecutivas
                matriz_grafo[cidade1][cidade2] = custo_estrada; // Adiciona a estrada
                matriz_grafo[cidade2][cidade1] = custo_estrada; // Adiciona a estrada na direção oposta
            }
        }

        // Calcula o menor caminho usando o algoritmo de Dijkstra e imprime o resultado
        int resultado = dijkstra(destino_final, inicio_rota - 1);
        printf("%d\n", resultado == INF ? -1 : resultado);
    }
    return 0;
}
