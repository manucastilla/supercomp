// $> g++ -Wall -O3 tarefa1.cpp -o tarefa1 &&./tarefa1 < in1.txt
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <math.h>
#include <iomanip>

typedef struct
{
    double frac;
    double price;
    int idx;
} fornecedor;

void mais_caro(vector<fornecedor> &vec_for)
{
    sort(vec_for.begin(), vec_for.end(), [](const fornecedor &a, const fornecedor &b) {
        return a.price > b.price;
    });
}

void menor_indice(vector<fornecedor> &vec_for)
{
    sort(vec_for.begin(), vec_for.end(), [](const fornecedor &a, const fornecedor &b) {
        return a.frac < b.frac;
    });
}

void recursiva(int N, vector<fornecedor> &f, int i, double &dif, vector<fornecedor> &bestFornecedor, vector<double> &dist, int j, double &valorTotal)
{

    mais_caro(f);

    if (i == N)
    {

        if (f[0].frac - f[N - 1].frac < dif)
        {
            dif = f[0].frac - f[N - 1].frac;
            bestFornecedor = f;
            for (int k = 0; k < N; k++)
            {
                valorTotal += f[k].frac;
            }
        }
        return;
    }

    // esse for não faz mais sentindo, pois é um fornecedor, uma entrega
    // for (int j = 0; j < N; j++)
    // {
    f[i].frac = (f[i].price / dist[j]);

    recursiva(N, f, i + 1, dif, bestFornecedor, dist, j + 1, valorTotal);

    // f[i].frac = 0;
    //
    return;
}

int main()
{
    int N;
    cin >> N;

    vector<double> dist;
    double inputDist;
    for (int i = 0; i < N; i++)
    {
        cin >> inputDist;
        dist.push_back(inputDist);
    }

    vector<fornecedor> vec_for;

    for (int i = 0; i < N; i++)
    {
        fornecedor obj;
        cin >> obj.price;
        obj.idx = i + 1;

        vec_for.push_back(obj);
    }

    double dif = 10000;
    // for (int j = 0; j < N; j++)
    // {
    //
    // }
    double valorTotal = 0;
    recursiva(N, vec_for, 0, dif, vec_for, dist, 0, valorTotal);

    mais_caro(vec_for);
    cout << fixed;
    cout << setprecision(2) << valorTotal << "\n";
    menor_indice(vec_for);
    for (int i = 0; i < N; i++)
    {

        cout << vec_for[i].idx << "\n";
    }
    // for (int i = 0; i < N; i++)
    // {
    //     cout << vec_for[i].idx << " " << vec_for[i].price << "\n";
    // }
    return 0;
}