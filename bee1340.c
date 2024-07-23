#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    // Variáveis booleanas para verificar se é possível ser uma pilha, fila ou fila de prioridade
    bool ehPilha, ehFila, ehFilaPrioridade;
    
    // Estruturas de dados para armazenar os elementos
    queue<int> fila;
    stack<int> pilha;
    priority_queue<int> filaPrioridade;

    int numOperacoes, tipoOperacao, valor;

    while (cin >> numOperacoes)
    {
        // Limpa as estruturas de dados
        while (!pilha.empty())
            pilha.pop();
        while (!fila.empty())
            fila.pop();
        while (!filaPrioridade.empty())
            filaPrioridade.pop();

        // Inicializa as variáveis booleanas
        ehPilha = true, ehFila = true, ehFilaPrioridade = true;

        for (int i = 0; i < numOperacoes; ++i)
        {
            cin >> tipoOperacao >> valor;

            if (tipoOperacao == 1) // Operação de inserção
            {
                if (ehPilha)
                    pilha.push(valor);
                if (ehFila)
                    fila.push(valor);
                if (ehFilaPrioridade)
                    filaPrioridade.push(valor);
            }
            else // Operação de remoção
            {
                if (ehPilha)
                {
                    if (pilha.empty() || pilha.top() != valor)
                        ehPilha = false;
                    else
                        pilha.pop();
                }

                if (ehFila)
                {
                    if (fila.empty() || fila.front() != valor)
                        ehFila = false;
                    else
                        fila.pop();
                }

                if (ehFilaPrioridade)
                {
                    if (filaPrioridade.empty() || filaPrioridade.top() != valor)
                        ehFilaPrioridade = false;
                    else
                        filaPrioridade.pop();
                }
            }
        }

        // Determina qual estrutura de dados é possível
        if (ehPilha && !ehFila && !ehFilaPrioridade)
            cout << "stack" << endl;
        else if (!ehPilha && ehFila && !ehFilaPrioridade)
            cout << "queue" << endl;
        else if (!ehPilha && !ehFila && ehFilaPrioridade)
            cout << "priority queue" << endl;
        else if (!ehPilha && !ehFila && !ehFilaPrioridade)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;
    }

    return 0;
}
