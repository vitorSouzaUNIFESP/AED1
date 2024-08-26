#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort, que compara duas strings
int compara(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int main(void) {
    // Variáveis para o número de alunos, posição desejada e contador
    int posicaoDesejada, totalAlunos, indice;
    char listaAlunos[200][50];
    
    // Lê o número total de alunos e a posição desejada
    scanf("%d %d\n", &totalAlunos, &posicaoDesejada);
    
    // Lê os nomes dos alunos
    for(indice = 0; indice < totalAlunos; ++indice) {
        scanf("%s", &listaAlunos[indice]);
    }
    
    // Ordena a lista de alunos em ordem alfabética
    qsort(listaAlunos, totalAlunos, sizeof(char) * 50, compara);
    
    // Imprime o nome do aluno na posição desejada (K-1 devido ao índice iniciar em 0)
    printf("%s\n", listaAlunos[posicaoDesejada - 1]);
    
    return 0;
}
