/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Tradutor do Papai Noel;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Lista de países e suas respectivas saudações de Natal
char *lista_paises[24] = { "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
			"inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile",
			"mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria",
			"marrocos", "japao" };
char *lista_saudacoes[24] = { "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
				"Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!",
				"Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!",
				"Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
				"Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!" };

// Estrutura para armazenar país e sua saudação correspondente
typedef struct {
	char nome_pais[50];
	char saudacao[100];
} Traducao;

// Array de traduções para armazenar as saudações de Natal
Traducao traducao_paises[24];
unsigned short indice_pais;

// Funções auxiliares
void inicializaTraducao();
bool buscaPais(const char *pais);

int main()
{
	// Inicializa o array de traduções com os dados fornecidos
	inicializaTraducao();

	// Variável para ler o nome do país
	char nome_pais[100];

	// Processa as entradas até o final do arquivo
	while (scanf(" %s", nome_pais) != EOF)
	{
		// Verifica se o país está na lista e imprime a saudação correspondente
		if (buscaPais(nome_pais))
			printf("%s\n", traducao_paises[indice_pais].saudacao);
		else
			printf("--- NOT FOUND ---\n");
	}

	return 0;
}

// Preenche o array de traduções com os dados iniciais
void inicializaTraducao()
{
	unsigned short i;
	for (i = 0; i < 24; i++)
	{
		strcpy(traducao_paises[i].nome_pais, lista_paises[i]);
		strcpy(traducao_paises[i].saudacao, lista_saudacoes[i]);
	}
}

// Busca o país na lista de traduções e define o índice correspondente
bool buscaPais(const char *pais)
{
	unsigned short i;
	for (i = 0; i < 24; i++)
	{
		if (strcmp(traducao_paises[i].nome_pais, pais) == 0)
		{
			indice_pais = i;
			return true;
		}
	}
	return false;
}
