#include <stdio.h>
#include <string.h>

// Função para determinar a duração da nota musical
double obterDuracaoNota(char nota) {
    switch (nota) {
        case 'W': return 1.0;      // Duração de uma nota inteira
        case 'H': return 0.5;      // Duração de uma metade de nota
        case 'Q': return 0.25;     // Duração de um quarto de nota
        case 'E': return 0.125;    // Duração de um oitavo de nota
        case 'S': return 0.0625;   // Duração de um dezesseis avos de nota
        case 'T': return 0.03125;  // Duração de um trinta e dois avos de nota
        case 'X': return 0.015625; // Duração de um sessenta e quatro avos de nota
        default: return 0.0;       // Nota desconhecida, retorna 0.0
    }
}

int main() {
    int quantidadeFrasesCompletas;
    double duracaoNotaAtual;
    char composicao[1000];

    // Loop para processar várias composições
    while (scanf("%[^\n]\n", composicao) != EOF) {
        if (strcmp(composicao, "*") == 0)
            break;

        quantidadeFrasesCompletas = 0;
        duracaoNotaAtual = 0.0;

        // Percorre cada caractere da composição
        for (int i = 0; i < strlen(composicao); ++i) {
            if (composicao[i] == '/') {
                // Se a duração acumulada for igual a 1.0, considera como uma frase completa
                if (duracaoNotaAtual == 1.0)
                    ++quantidadeFrasesCompletas;
                duracaoNotaAtual = 0.0; // Reseta a duração para a próxima frase
            } else {
                // Acumula a duração da nota atual
                duracaoNotaAtual += obterDuracaoNota(composicao[i]);
            }
        }

        // Imprime a quantidade de frases completas
        printf("%d\n", quantidadeFrasesCompletas);
    }

    return 0;
}
