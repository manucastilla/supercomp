// g++ -Wall -O3 tarefa2.cpp -o tarefa2 &&./tarefa2 < in-aula.txt
// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <random>

// N - num de objs
// P - peso
// v dos objetos
// C capacidade

/*  Pseudocódigo retornando o valor da mochila ótima
func(P, V, N, C, i) 
    se i=N
        return 0

    semItem = func(P, V, N, C, i+1)
    if (C - P[i] >= 0)
        comItem = mochila(P, V, N, C - P[i], i + 1) + V[i];
        return max(comItem, semItem) 
    
    return semItem
*/

typedef struct
{
    double frac;
    double valor;
    double peso;
    int idx;
} item;

void maior_fracao(vector<item> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const item &a, const item &b) {
        return a.frac > b.frac;
    });
}

double Mfrac(int N, vector<item> &vec_itens, int C, int i)
{
    int peso_atual = 0;
    double valor_atual = 0;
    for (int j = i; j < N; j++)
    {
        if (peso_atual + vec_itens[j].peso <= C)
        {

            peso_atual += vec_itens[j].peso;
            valor_atual += vec_itens[j].valor;
        }
        else
        {
            double resta = C - peso_atual;
            peso_atual += resta;
            valor_atual += resta / vec_itens[j].peso * vec_itens[j].valor;
        }
    }

    return valor_atual;
}

int M(int N, vector<item> &vec_itens, int C,
      int i, vector<bool> &used, vector<bool> &best, vector<bool> &aux)
{
    int valorUsed = 0;
    int valorBest = 0;

    if (i == N)
    {

        for (int i = 0; i < N; i++)
        {
            if (used[i])
            {
                valorUsed += vec_itens[i].valor;
            }
            if (best[i])
            {
                valorBest += vec_itens[i].valor;
            }
        }

        if (valorUsed > valorBest)
        {

            best = used;
        }
        return 0;
    }

    aux = used;
    for (int j = i; j < N; j++)
    {
        aux[j] = true;
    }

    int valorAux = 0;
    for (int i = 0; i < N; i++)
    {
        if (aux[i])
        {
            valorAux += vec_itens[i].valor;
        }
        if (best[i])
        {
            valorBest += vec_itens[i].valor;
        }
    }

    double bound = Mfrac(N, vec_itens, C, i);

    if (bound <= valorBest)
    {
        return 0;
    }

    used[i] = false;
    int semItem, comItem;

    semItem = M(N, vec_itens, C, i + 1, used, best, aux);

    if (C - vec_itens[i].peso >= 0)
    {

        used[i] = true;
        comItem = M(N, vec_itens, C - vec_itens[i].peso, i + 1, used, best, aux) + vec_itens[i].valor;
        return max(semItem, comItem);
    }

    return semItem;
}

int main()
{
    int N;
    std::cin >> N;
    int C;
    std::cin >> C;

    // vector<int> P(N);
    // vector<int> v(N);
    vector<bool> used(N, false);
    vector<bool> best(N, false);
    vector<bool> aux(N, false);
    vector<int> bound(N, 0);
    vector<int> valoresBounds(N, 0);

    vector<item> vec_itens;

    int wi, vi;
    for (int i = 0; i < N; i++)
    {
        item objAtual;
        cin >> objAtual.peso;
        cin >> objAtual.valor;
        objAtual.frac = objAtual.valor / objAtual.peso;
        objAtual.idx = i;

        vec_itens.push_back(objAtual);
    }

    int num_leaf = 0;
    int num_copy = 0;

    int Value = M(N, vec_itens, C, 0, used, best, aux);

    int wTotal = 0;
    for (int i = 0; i < N; i++)
    {
        if (best[i])
        {
            wTotal += vec_itens[i].peso;
        }
    }
    cout << wTotal << " " << Value << " " << '1' << "\n";
    for (int i = 0; i < N; i++)
    {
        if (best[i])
        {
            cout << i << " ";
        }
    }

    cout << "\n";
    return 0;
}