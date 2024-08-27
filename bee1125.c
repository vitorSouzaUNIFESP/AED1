#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAXIMO 105

typedef unsigned short us;

int main() {

    us numCorridas, numPilotos, corrida, piloto, sistemaPontuacao;
    us resultados[TAMANHO_MAXIMO][TAMANHO_MAXIMO], sistemaPontos[TAMANHO_MAXIMO], pontuacoes[TAMANHO_MAXIMO];

    // Enquanto houver entradas de número de corridas e número de pilotos
    while (scanf("%hu %hu", &numCorridas, &numPilotos), numCorridas) {

        // Lê os resultados das corridas
        for (corrida = 0; corrida < numCorridas; ++corrida) {
            for (piloto = 0; piloto < numPilotos; ++piloto) {
                scanf("%hu", &resultados[corrida][piloto]);
            }
        }

        // Lê o número de sistemas de pontuação a serem avaliados
        us numSistemas;
        scanf("%hu", &numSistemas);

        while (numSistemas--) {

            // Inicializa as pontuações com zero
            memset(pontuacoes, 0, sizeof(pontuacoes));
            memset(sistemaPontos, 0, sizeof(sistemaPontos));

            us numPosicoesPontuadas;
            scanf("%hu", &numPosicoesPontuadas);

            // Lê os pontos atribuídos a cada posição
            for (corrida = 0; corrida < numPosicoesPontuadas; ++corrida) {
                scanf("%hu", &sistemaPontos[corrida]);
            }

            // Calcula a pontuação total de cada piloto
            for (corrida = 0; corrida < numCorridas; ++corrida) {
                for (piloto = 0; piloto < numPilotos; ++piloto) {
                    pontuacoes[piloto] += sistemaPontos[resultados[corrida][piloto] - 1];
                }
            }

            us pontuacaoMaxima = 0;

            // Determina a pontuação máxima entre os pilotos
            for (piloto = 0; piloto < numPilotos; ++piloto) {
                if (pontuacoes[piloto] > pontuacaoMaxima) {
                    pontuacaoMaxima = pontuacoes[piloto];
                }
            }

            _Bool primeiraImpressao = VERDADEIRO;

            // Imprime os pilotos com a pontuação máxima
            for (piloto = 0; piloto < numPilotos; ++piloto) {
                if (pontuacoes[piloto] == pontuacaoMaxima) {
                    if (primeiraImpressao) {
                        printf("%hu", piloto + 1);
                        primeiraImpressao = FALSO;
                    } else {
                        printf(" %hu", piloto + 1);
                    }
                }
            }

            printf("\n");
        }
    }

    return 0;
}
