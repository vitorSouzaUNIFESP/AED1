#include <stdio.h>
#include <string.h>

int minimosStack[1000000];

int main(){
    char operacao[4];
    int totalOperacoes, valor, minimoAtual, posicao;

    posicao = -1;
    scanf("%d\n", &totalOperacoes);
    for(int i = 0; i < totalOperacoes; ++i){
        scanf("%s", &operacao);

        if(!memcmp(operacao, "PUSH", 4)){
            scanf("%d\n", &valor);

            if(posicao == -1){
                minimoAtual = valor;
            }else{
                minimoAtual = (minimosStack[posicao] < valor ? minimosStack[posicao] : valor);
            }

            minimosStack[++posicao] = minimoAtual;
        }else if(!memcmp(operacao, "POP", 3)){
            if(posicao == -1){
                printf("EMPTY\n");
            }else{
                --posicao;
            }
       
