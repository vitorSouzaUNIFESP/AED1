#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Estrutura para armazenar os dados do aluno
typedef struct {
    char nome[30];
    char assinaturaOriginal[30];
} Aluno;

// Função para validar a assinatura do aluno
bool validarAssinatura(Aluno *turma, char *assinaturaAtual, unsigned short posicao, unsigned short totalAlunos);

// Função para encontrar a posição do aluno na lista
unsigned short encontrarAluno(Aluno *turma, char *nome, unsigned short totalAlunos);

int main() {
    unsigned short totalAlunos, totalPresentes;
    unsigned short i, totalAssinaturasFalsas;
    char nomeAluno[30], assinaturaAtual[30];

    while (true) {
        // Leitura do número total de alunos
        scanf("%hu", &totalAlunos);

        // Condição de parada
        if (totalAlunos == 0)
            break;

        // Criação do array de alunos
        Aluno turma[totalAlunos];

        // Leitura dos dados dos alunos
        for (i = 0; i < totalAlunos; i++) {
            scanf(" %s %s", turma[i].nome, turma[i].assinaturaOriginal);
        }

        // Leitura do número de alunos presentes
        scanf("%hu", &totalPresentes);

        // Inicialização do contador de assinaturas falsas
        totalAssinaturasFalsas = 0;
        for (i = 0; i < totalPresentes; i++) {
            scanf("%s %s", nomeAluno, assinaturaAtual);

            // Valida a assinatura atual do aluno
            if (!validarAssinatura(turma, assinaturaAtual, encontrarAluno(turma, nomeAluno, totalAlunos), totalAlunos)) {
                totalAssinaturasFalsas++;
            }
        }

        // Impressão do número de assinaturas falsas
        printf("%hu\n", totalAssinaturasFalsas);
    }

    return 0;
}

// Função que valida a assinatura do aluno na posição dada
bool validarAssinatura(Aluno *turma, char *assinaturaAtual, unsigned short posicao, unsigned short totalAlunos) {
    unsigned short i;
    unsigned short diferencas;

    i = 0;
    diferencas = 0;

    // Contagem das diferenças entre a assinatura original e a atual
    while (turma[posicao].assinaturaOriginal[i]) {
        if (turma[posicao].assinaturaOriginal[i] != assinaturaAtual[i]) {
            diferencas++;
        }
        i++;
    }

    // Considera a assinatura como válida se houver no máximo uma diferença
    return diferencas <= 1;
}

// Função que retorna a posição do aluno na lista
unsigned short encontrarAluno(Aluno *turma, char *nome, unsigned short totalAlunos) {
    unsigned short i;

    for (i = 0; i < totalAlunos; i++) {
        if (strcmp(turma[i].nome, nome) == 0) {
            return i;
        }
    }

    // Retorna um valor inválido caso o aluno não seja encontrado (não deveria chegar aqui com entrada válida)
    return totalAlunos;
}
