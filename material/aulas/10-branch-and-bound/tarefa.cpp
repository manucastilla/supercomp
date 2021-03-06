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

int M(int N, vector<int> &P, vector<int> &V, int C,
      int i, vector<bool> &used, vector<bool> &best, int &num_leaf, int &num_copy, vector<bool> &aux)
{
    int valorUsed = 0;
    int valorBest = 0;

    if (i == N)
    {
        num_leaf++;

        for (int i = 0; i < N; i++)
        {
            if (used[i])
            {
                valorUsed += V[i];
            }
            if (best[i])
            {
                valorBest += V[i];
            }
        }

        if (valorUsed > valorBest)
        {
            num_copy++;
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
            valorAux += V[i];
        }
        if (best[i])
        {
            valorBest += V[i];
        }
    }

    if (valorAux < valorBest)
    {
        return 0;
    }

    // used[i] = 0;
    used[i] = false;
    int semItem, comItem;

    semItem = M(N, P, V, C, i + 1, used, best, num_leaf, num_copy, aux);

    if (C - P[i] >= 0)
    {
        // used[i] = 1;
        used[i] = true;
        comItem = M(N, P, V, C - P[i], i + 1, used, best, num_leaf, num_copy, aux) + V[i];
        return max(semItem, comItem);
    }

    return semItem;
}

int main()
{
    int n;
    std::cin >> n;
    int C;
    std::cin >> C;

    vector<int> P(n);
    vector<int> v(n);
    vector<bool> used(n, false);
    vector<bool> best(n, false);
    vector<bool> aux(n, false);

    int wi, vi;
    for (int i = 0; i < n; i++)
    {

        cin >> wi >> vi;
        P[i] = wi;
        v[i] = vi;
    }

    int num_leaf = 0;
    int num_copy = 0;
    int Value = M(n, P, v, C, 0, used, best, num_leaf, num_copy, aux);

    int wTotal = 0;
    for (int i = 0; i < n; i++)
    {
        if (best[i])
        {
            wTotal += P[i];
        }
    }
    cout << wTotal << " " << Value << " " << '1' << "\n";
    for (int i = 0; i < n; i++)
    {
        if (best[i])
        {
            cout << i << " ";
        }
    }

    cout << "\n";
    return 0;
}