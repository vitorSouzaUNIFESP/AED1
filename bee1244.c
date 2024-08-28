#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int num_palavras;
char lista_palavras[100][100];

int comparar(char *x, char *y)
{
    return strlen(y) - strlen(x);
}

void ordenarPorInsercao()
{
    char temporario[100];

    for (int i = 1; i < num_palavras; ++i)
    {
        int j = i, k = j - 1;

        while (k > -1 && comparar(lista_palavras[j], lista_palavras[k]) < 0)
        {
            strcpy(temporario, lista_palavras[j]);
            strcpy(lista_palavras[j], lista_palavras[k]);
            strcpy(lista_palavras[k], temporario);
            --j, --k;
        }
    }
}

int main()
{
    int quantidade;
    char texto[10000], *p;

    scanf("%d\n", &quantidade);

    for (int i = 0; i < quantidade; ++i)
    {
        scanf("%[^\n]\n", texto);

        num_palavras = 0;
        p = strtok(texto, " ");
        while (p != NULL)
        {
            strcpy(lista_palavras[num_palavras++], p);
            p = strtok(NULL, " ");
        }

        ordenarPorInsercao();

        printf("%s", lista_palavras[0]);
        for (int j = 1; j < num_palavras; ++j)
        {
            printf(" %s", lista_palavras[j]);
        }
        printf("\n");
    }

    return 0;
}
