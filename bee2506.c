#include <stdio.h>

#define INICIO_ATENDIMENTO 420 // 7h da manhã em minutos (7 * 60)

// Função para converter horas e minutos para minutos desde as 7:00
int converterParaMinutos(int horas, int minutos) {
    return (horas * 60) + minutos;
}

int main() {
    int N; // Número de pacientes que chegam na triagem

    while (scanf("%d", &N) != EOF) {
        int horas, minutos, critico;
        int proximoAtendimento = INICIO_ATENDIMENTO; // Próximo horário de atendimento em minutos
        int pacientesCriticos = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &horas, &minutos, &critico);
            int chegada = converterParaMinutos(horas, minutos);
            int tempoLimite = chegada + critico;

            // Se a fila de atendimento está vazia ou o paciente chega quando já está na hora de atendimento, atualize o próximo atendimento
            if (chegada > proximoAtendimento) {
                proximoAtendimento = chegada;
            }

            // Verifica se o paciente será atendido antes de atingir a condição crítica
            if (proximoAtendimento > tempoLimite) {
                pacientesCriticos++;
            }

            // Próximo atendimento ocorre 30 minutos depois do atual
            proximoAtendimento += 30;
        }

        // Imprime o número de pacientes que atingiram a condição crítica
        printf("%d\n", pacientesCriticos);
    }

    return 0;
}
