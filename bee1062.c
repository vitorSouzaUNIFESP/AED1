#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

// Estrutura da pilha
typedef struct{
    int vetor[MAX];
    int topo;
} Pilha;

// Função para empilhar um elemento
void empilhar(Pilha *p, int valor){
    p->vetor[++p->topo] = valor;
}

// Função para desempilhar um elemento
void desempilhar(Pilha *p){
    p->topo--;
}

int main(){    
    int fora, numVagoes, i, erro, entrando, zero; 
    Pilha pilha;
    
    // Leitura do número de vagões e processamento até encontrar um valor zero
    while(scanf("%d", &numVagoes) && numVagoes){
        while(1){            
            pilha.topo = -1; // Inicializa o topo da pilha
            for(i = 0, entrando = 1, erro = 0, zero = 0; i < numVagoes && !erro && !zero; i++){
                scanf("%d", &fora);
                if(!fora){
                    zero = 1;
                    break;
                }
                while(1){
                    if(fora == entrando){
                        entrando++;
                        break;
                    } else if(fora > entrando){
                        empilhar(&pilha, entrando);
                        entrando++;
                    } else {
                        if(pilha.vetor[pilha.topo] == fora)
                            desempilhar(&pilha);
                        else{
                            erro = 1;
                            for(; i < numVagoes - 1; i++)
                                scanf("%d", &fora);
                        }                                
                        break;
                    }
                }                
            }
            if(!zero)
                if(!erro)
                    printf("Sim\n");
                else
                    printf("Não\n");
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
