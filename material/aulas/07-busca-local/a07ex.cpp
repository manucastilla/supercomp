// g++ -Wall -O3 a07ex.cpp -o a07ex && ./a07ex < in1.txt

#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <random>

typedef struct
{
    int valor;
    int peso;
    int idx;
    bool used;

} item;

void mais_caro(vector<item> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const item &a, const item &b) {
        return a.valor > b.valor;
    });
}

void heuristica(vector<item> &vec_itens, vector<int> &objsSel, int N, int W, int randomSeed)
{
    int T = 0;
    int valor, peso;

    default_random_engine generator;
    generator.seed(randomSeed);
    uniform_real_distribution<double> distribution(0.0, 1.0);
    // gera número

    int valor_melhor = 0, peso_melhor = 0;
    vector<bool> usados_melhor(N, false);

    for (int k = 0; k < 10; k++)
    {
        vector<bool> usados(N, false);
        peso = 0;
        valor = 0;

        for (auto &obj : vec_itens)
        {
            if (peso + obj.peso <= W && distribution(randomSeed))
            {
                peso += obj.peso;
                valor += obj.valor;
                usados[obj.idx] = true;
            }
        }

        if (valor > valor_melhor)
        {
            valor_melhor = valor;
            peso_melhor = peso;
            usados_melhor = usados;
        }
    }

    cout << peso_melhor << " " << valor_melhor << " " << 0 << "\n";
    sort(objsSel.begin(), objsSel.begin() + T);

    // for (int i = 0; i < T; i++)
    // {
    //     cout << objsSel[i] << " ";
    // }

    for (int i = 0; i < N; i++)
    {
        if (usados_melhor[i])
        {
            cout << i << " ";
        }
    }

    cout << "\n";
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
        obj.used = false;

        vec_itens.push_back(obj);
    }
    mais_caro(vec_itens);

    default_random_engine generator;
    uniform_int_distribution<int> randomSeed(0, 1000000);

    int vezes = 10; // vezes q o programa irá executar

    // for (int i = 0; i < vezes; i++)
    // {
    //     int newSeed = randomSeed(generator);
    //     heuristica(vec_itens, objsSel, N, W, newSeed);

    //     cout << "\n";
    // }
    int newSeed = randomSeed(generator);
    heuristica(vec_itens, objsSel, N, W, newSeed);

    return 0;
}