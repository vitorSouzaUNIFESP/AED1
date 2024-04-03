#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    
    // Leitura de N e M
    scanf("%d %d", &N, &M);
    
    // Array para armazenar os tempos de processamento dos funcionários
    int vi[N];
    
    // Array para armazenar a quantidade de itens em cada cesta de cliente
    int cj[M];

    // Leitura dos tempos de processamento dos funcionários
    for(int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
    }
    
    // Leitura da quantidade de itens em cada cesta de cliente
    for(int i = 0; i < M; i++) {
        scanf("%d", &cj[i]);
    }

    long long tempo_total = 0;
    int atendimento[N]; // Vetor para armazenar o tempo de atendimento de cada funcionário

    // Inicializa o vetor de atendimento com 0
    for(int i = 0; i < N; i++) {
        atendimento[i] = 0;
    }

    // Percorre a fila de clientes
    for(int i = 0; i < M; i++) {
        int menor_tempo = atendimento[0]; // Menor tempo de atendimento inicialmente é o do primeiro funcionário
        int indice_funcionario = 0; // Índice do funcionário que irá atender o cliente
        // Encontra o funcionário que terminará seu atendimento primeiro
        for(int j = 1; j < N; j++) {
            if(atendimento[j] < menor_tempo) {
                menor_tempo = atendimento[j];
                indice_funcionario = j;
            }
        }
        // Adiciona o tempo de atendimento do funcionário ao tempo total
        tempo_total += atendimento[indice_funcionario];
        // Atualiza o tempo de atendimento do funcionário com o tempo de processamento dos itens do cliente
        atendimento[indice_funcionario] += vi[indice_funcionario] * cj[i];
    }

    // Encontra o maior tempo de atendimento (pois todos os clientes são atendidos quando o último funcionário termina)
    long long maior_tempo = atendimento[0];
    for(int i = 1; i < N; i++) {
        if(atendimento[i] > maior_tempo) {
            maior_tempo = atendimento[i];
        }
    }

    // Imprime o maior tempo de atendimento (tempo total para todos os clientes serem atendidos)
    printf("%lld\n", maior_tempo);

    return 0;
}
