// g++ -Wall -O3 tarefa2.cpp -o tarefa2 &&./tarefa2 < in-aula.txt
// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <random>

// N - num de objs
// P - peso
// valor dos objetos
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

int M(int N, vector<int> &P, vector<int> &V, int C, int i, vector<int> &used, vector<int> &best)
{
    int valorUsed = 0;
    int valorBest = 0;
    if (i == N)
    {
        if (used[i])
        {
            valorUsed += V[i];
        }
        if (best[i])
        {
            valorBest += V[i];
        }

        if (valorUsed > valorBest)
        {
            valorBest = valorUsed;
        }
        return 0;
    }
    used[i] = 0;
    int semItem, comItem;

    semItem = M(N, P, V, C, i + 1, used, best);
    comItem = semItem;

    if (C - P[i] > 0)
    {
        comItem = M(N, P, V, C - P[i], i + 1, used, best) + V[i];
    }

    return max(semItem, comItem);
}

int main()
{
    int n;
    std::cin >> n;
    int C;
    std::cin >> C;

    vector<int> peso(n);
    vector<int> valor(n);
    vector<int> used(n);
    vector<int> best(n);

    for (int i = 0; i < n; i++)
    {

        cin >> peso[i];
        cin >> valor[i];
    }

    cout << M(n, peso, valor, C, 0, used, best) << '\n';

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