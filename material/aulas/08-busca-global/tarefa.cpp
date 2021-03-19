// g++ -Wall -O3 tarefa.cpp -o tarefa &&./tarefa < in-aula.txt
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

int M(int N, vector<int> &P, vector<int> &V, int C, int i)
{
    if (i == N)
    {
        return 0;
    }
    int semItem, comItem;

    semItem = M(N, P, V, C, i + 1);
    comItem = semItem;

    if (C - P[i] > 0)
    {
        comItem = M(N, P, V, C - P[i], i + 1) + V[i];
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

    for (int i = 0; i < n; i++)
    {

        cin >> peso[i];
        cin >> valor[i];
    }

    cout << M(n, peso, valor, C, 0) << '\n';

    return 0;
}