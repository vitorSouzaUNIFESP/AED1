#include <stdio.h>
#include <string.h>

#define MAX_FRUTAS 100
#define TAMANHO_NOME_FRUTA 50

int main()
{
    int N, M, P, quantidade;
    char fruta[TAMANHO_NOME_FRUTA];
    char frutas[MAX_FRUTAS][TAMANHO_NOME_FRUTA];
    double resposta, precos[MAX_FRUTAS];

    // Lê o número de casos de teste
    scanf("%d", &N);

    // Processa cada caso de teste
    for (int k = 0; k < N; ++k)
    {
        // Lê o número de frutas
        scanf("%d", &M);

        // Lê o nome e o preço de cada fruta
        for (int i = 0; i < M; ++i)
        {
            scanf("%s %lf", frutas[i], &precos[i]);
        }

        // Lê o número de frutas a serem compradas
        scanf("%d", &P);

        resposta = 0.0;
        // Processa cada fruta a ser comprada
        for (int i = 0; i < P; ++i)
        {
            scanf("%s %d", fruta, &quantidade);

            // Procura o preço da fruta e calcula o custo total
            for (int j = 0; j < M; ++j)
            {
                if (strcmp(fruta, frutas[j]) == 0)
                {
                    resposta += quantidade * precos[j];
                    break;
                }
            }
        }

        // Exibe o resultado formatado
        printf("R$ %.2lf\n", resposta);
    }

    return 0;
}
