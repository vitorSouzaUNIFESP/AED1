#include <bits/stdc++.h>
#define adc push_back
#define tam size()
#define MAXIMO 201
#define limpe clear()
#define bsc find
#define fim end()
#define atr assign
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;
typedef vector<long> vetor_long;
typedef pair <int,int> par_int;
typedef pair<long,par_int> par_long_int;
typedef map<par_long_int,int> mapa_par_long_int;
typedef vector<bool> vetor_bool;

bool grafo[MAXIMO][MAXIMO];
mapa_par_long_int identificador;
int n, m;

bool caminhoMaximo(int u, bool visto[], int matchR[])
{
    for (int v = 0; v < m; v++)
    {
        if (grafo[u][v] && !visto[v])
        {
            visto[v] = true;

            if (matchR[v] < 0 || caminhoMaximo(matchR[v], visto, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxCaminho()
{
    int matchR[m];
    memset(matchR, -1, sizeof(matchR));

    int resultado = 0;
    for (int u = 0; u < n; u++)
    {
        bool visto[m];
        memset(visto, 0, sizeof(visto));

        if (caminhoMaximo(u, visto, matchR))
            resultado++;
    }
    return resultado;
}

void limpar()
{
    REP(i, 0, n)
        REP(j, 0, m)
            grafo[i][j] = 0;
}

int main()
{
    int c = 1, casos, ni, mi, identificacao;
    long auxiliar;
    vetor_long vetor_nn, vetor_nm;
    vetor_bool marcado_nn, marcado_nm;

    scanf("%d", &casos);

    while (c <= casos)
    {
        identificador.limpe;
        vetor_nm.limpe;
        vetor_nn.limpe;

        scanf("%d", &ni);
        while (ni--)
        {
            scanf("%ld", &auxiliar);
            vetor_nn.adc(auxiliar);
        }

        scanf("%d", &mi);
        while (mi--)
        {
            scanf("%ld", &auxiliar);
            vetor_nm.adc(auxiliar);
        }

        identificacao = 0;
        marcado_nn.atr(vetor_nn.tam, 0);
        marcado_nm.atr(vetor_nm.tam, 0);

        REP(i, 0, vetor_nn.tam)
        {
            if (identificador.bsc(par_long_int(vetor_nn[i], par_int(1, i))) == identificador.fim && !marcado_nn[i])
            {
                identificador[par_long_int(vetor_nn[i], par_int(1, i))] = identificacao;
                marcado_nn[i] = true;
                identificacao++;
            }

            REP(j, 0, vetor_nm.tam)
            {
                if (identificador.bsc(par_long_int(vetor_nm[j], par_int(2, j))) == identificador.fim && !marcado_nm[j])
                {
                    identificador[par_long_int(vetor_nm[j], par_int(2, j))] = identificacao;
                    marcado_nm[j] = true;
                    identificacao++;
                }

                if (vetor_nn[i] != 0 && vetor_nm[j] % vetor_nn[i] == 0)
                {
                    grafo[identificador[par_long_int(vetor_nn[i], par_int(1, i))]][identificador[par_long_int(vetor_nm[j], par_int(2, j))]] = 1;
                }
                else if (vetor_nm[j] == vetor_nn[i] && vetor_nn[i] == 0)
                {
                    grafo[identificador[par_long_int(vetor_nn[i], par_int(1, i))]][identificador[par_long_int(vetor_nm[j], par_int(2, j))]] = 1;
                }
            }
        }

        n = m = identificacao;

        printf("Caso %d: %d\n", c, maxCaminho());
        limpar();
        c++;
    }

    return 0;
}
