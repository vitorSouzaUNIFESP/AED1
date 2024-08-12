#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1040
#define TAMANHO_FILA (MAX * MAX)

// Matriz para armazenar o grid
char grade[MAX][MAX];

// Estrutura para representar um ponto (coordenada)
typedef struct {
    int x, y;
} Ponto;

// Fila para a busca em largura (BFS)
Ponto fila[TAMANHO_FILA];
int frente = 0, traseira = 0;

// Função para adicionar um ponto à fila
void enfileirar(int x, int y) {
    if (traseira < TAMANHO_FILA) {
        fila[traseira++] = (Ponto){x, y};
    }
}

// Função para remover um ponto da fila
Ponto desenfileirar() {
    return fila[frente++];
}

// Função para verificar se a fila está vazia
bool estaVazia() {
    return frente == traseira;
}

// Função para realizar a busca em largura (BFS)
void bfs(int inicioX, int inicioY) {
    // Adiciona o ponto inicial à fila e marca como visitado
    enfileirar(inicioX, inicioY);
    grade[inicioX][inicioY] = 'o';

    // Direções possíveis para mover (cima, baixo, direita, esquerda)
    int direcoes[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Executa a busca em largura
    while (!estaVazia()) {
        Ponto atual = desenfileirar();
        int x = atual.x;
        int y = atual.y;

        // Verifica todas as direções possíveis
        for (int i = 0; i < 4; i++) {
            int novoX = x + direcoes[i][0];
            int novoY = y + direcoes[i][1];

            // Verifica se o novo ponto está dentro dos limites e não foi visitado
            if (novoX >= 1 && novoX < MAX && novoY >= 1 && novoY < MAX && grade[novoX][novoY] == '.') {
                grade[novoX][novoY] = 'o';  // Marca o ponto como visitado
                enfileirar(novoX, novoY);   // Adiciona o novo ponto à fila
            }
        }
    }
}

int main() {
    int n, m, contagem = 0;

    // Lê o número de linhas e colunas do grid
    scanf("%d %d", &n, &m);

    // Inicializa a matriz com '0'
    memset(grade, '0', sizeof grade);

    // Lê o grid
    for (int i = 1; i <= n; i++) {
        scanf("%s", &grade[i][1]);
    }

    // Percorre toda a matriz para encontrar e contar componentes conectados
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grade[i][j] == '.') {
                bfs(i, j);  // Inicia a BFS a partir do ponto encontrado
                contagem++; // Incrementa o contador de componentes conectados
            }
        }
    }

    // Imprime o número total de componentes conectados encontrados
    printf("%d\n", contagem);
    return 0;
}
