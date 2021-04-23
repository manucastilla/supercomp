// g++ -Wall -O3 tarefa1.cpp -o tarefa1 &&./tarefa1 < in1.txt

// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;

typedef struct
{
    int valor;
    int peso;
    int idx;

} item;

void mais_caro(vector<item> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const item &a, const item &b) {
        return a.valor > b.valor;
    });
}

void mais_leve(vector<item> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const item &a, const item &b) {
        return a.peso < b.peso;
    });
}

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> objsSel(N, 0);
    vector<item> vec_itens;

    for (int i = 0; i < N; i++)
    {
        item obj;
        cin >> obj.peso;
        cin >> obj.valor;
        obj.idx = i;

        vec_itens.push_back(obj);
    }

    int T = 0;
    int valor, peso;
    peso = 0;
    valor = 0;

    // mais_caro(vec_itens);
    mais_leve(vec_itens);

    for (int i = 0; i < N; i++)
    {
        if (vec_itens[i].peso + peso <= W)
        {
            peso += vec_itens[i].peso;
            T += 1;
            objsSel[T] = vec_itens[i].idx;
            valor += vec_itens[i].valor;
        }
    }
    cout << peso << " " << valor << " " << 0 << "\n";

    for (int i = 0; i < T; i++)
    {
        cout << objsSel[i] << " ";
    }

    cout << "\n";
    return 0;
}