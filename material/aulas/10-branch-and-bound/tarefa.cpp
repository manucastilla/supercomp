// g++ -Wall -O3 tarefa.cpp -o tarefa &&./tarefa < in150.txt
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

int M(int N, vector<int> &P, vector<int> &V, int C, int i, vector<int> &used, vector<int> &best, int &num_leaf, int &num_copy)
{
    vector<int> aux;
    int valorUsed = 0;
    int valorBest = 0;
    int valorAux = 0;
    aux = used;

    if (i == N)
    {
        num_leaf++;
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
            num_copy++;
        }
        return 0;
    }

    for (int j = i; j < N; j++)
    {
        aux[j] = 1;
        valorAux += 1;
    }

    if (valorAux <= valorBest)
    {
        return 0;
    }

    used[i] = 0;
    int semItem, comItem;

    semItem = M(N, P, V, C, i + 1, used, best, num_leaf, num_copy);
    comItem = semItem;

    if (C - P[i] > 0)
    {
        comItem = M(N, P, V, C - P[i], i + 1, used, best, num_leaf, num_copy) + V[i];
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

    vector<int> peso(n);
    vector<int> valor(n);
    vector<int> used(n);
    vector<int> best(n);
    int num_leaf = 0;

    int num_copy = 0;

    for (int i = 0; i < n; i++)
    {

        cin >> peso[i];
        cin >> valor[i];
    }

    cout << M(n, peso, valor, C, 0, used, best, num_leaf, num_copy) << '\n';
    //cout << num_leaf << " " << num_copy << '\n';

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