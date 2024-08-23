#include <string.h>
#include <stdio.h>

int main() {
    char display[101];
    int quantidade, totalLeds;
    int consumoLeds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    scanf("%d\n", &quantidade);

    for (int contador = 0; contador < quantidade; ++contador) {
        scanf("%s", display);

        totalLeds = 0;
        for (int k = 0; k < strlen(display); ++k) {
            totalLeds += consumoLeds[display[k] - '0'];
        }

        printf("%d leds\n", totalLeds);
    }

    return 0;
}
