#include <string.h>
#include <stdio.h>

int main() {
    int totalCasos, quantidadeIdiomas, todosIguais;
    char primeiroIdioma[21], idiomaAtual[21];

    // Lê o número total de casos de teste
    scanf("%d", &totalCasos);

    // Loop que percorre cada caso de teste
    for(int caso = 0; caso < totalCasos; ++caso) {
        // Lê a quantidade de idiomas a serem comparados para este caso
        scanf("%d\n", &quantidadeIdiomas);

        // Inicializa a variável para verificar se todos os idiomas são iguais
        todosIguais = 1;

        // Lê o primeiro idioma que servirá de referência para as comparações
        scanf("%s\n", &primeiroIdioma);
        
        // Compara os idiomas subsequentes com o primeiro
        for(int contador = 1; contador < quantidadeIdiomas; ++contador) {
            // Lê o próximo idioma
            scanf("%s\n", &idiomaAtual);

            // Se o idioma atual for diferente do primeiro, define 'todosIguais' como 0 (falso)
            if(strcmp(primeiroIdioma, idiomaAtual) != 0) {
                todosIguais = 0;
            }
        }

        // Se todos os idiomas forem iguais, imprime o primeiro idioma, caso contrário, imprime "ingles"
        if(todosIguais) {
            printf("%s\n", primeiroIdioma);
        } else {
            printf("ingles\n");
        }
    }

    return 0;
}
