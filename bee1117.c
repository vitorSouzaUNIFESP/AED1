#include <stdio.h>

int main() {
    double nota, media, soma = 0;
    int contagem = 0;

    while(1) {
        if(contagem == 2)
            break;
        
        scanf("%lf", &nota);
        
        if(nota >= 0 && nota <= 10) {
            contagem++;
            soma += nota;
        } else {
            printf("nota invalida\n");
        }
    }

    media = soma / 2.0;
    printf("media = %.2lf\n", media);
    
    return 0;
}
