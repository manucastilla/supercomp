// g++ -Wall -O3 tarefa1.cpp -o tarefa1
//./tarefa1 < in1.txt
// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <random>

// 25% vc pega outro produto
typedef struct
{
    double valor;
    double peso;
    int idx;
    bool used;
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

void heuristica(int randomSeed, int n, int W, std::vector<item> itens)
{
    vector<double> resposta(n, 0);
    int T = 0; //objSel
    int peso_atual = 0;
    int valor_atual = 0;

    std::default_random_engine generator;
    generator.seed(randomSeed);

    std::uniform_real_distribution<double> distribution01(0.0, 1.0);

    for (int i = 0; i < n; i++)
    {
        if (distribution01(generator) <= 0.25 && itens[i].used == false)
        {
            if (peso_atual + itens[i].peso <= W)
            {
                resposta[T] = (itens[i].idx);
                peso_atual += itens[i].peso;
                valor_atual += itens[i].valor;
                itens[i].used = true;
                T++;
            }
        }
    }

    cout << "peso: " << peso_atual << " "
         << "valor: " << valor_atual << '\n';

    for (int i = 0; i < T; i++)
    {
        std::cout << resposta[i] << " ";
    }
    cout << "\n";
}

int main()
{

    int n;
    std::cin >> n;
    int W;
    std::cin >> W;

    vector<item> itens;

    for (int i = 0; i < n; i++)
    {
        item objAtual;
        cin >> objAtual.peso;
        cin >> objAtual.valor;
        objAtual.idx = i;
        //objAtual.used = false;

        itens.push_back(objAtual);
        // cout << "Saídax: " << weights[i] << '\n';
        // cout << "Saíday: " << values[i] << '\n';
    }

    // for (int i = 0; i < vec_itens.size(); i++)
    // {
    //     cout << vec_itens[i].used << '\n';
    // }

    mais_caro(itens);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 1000);

    int exec = 10;

    for (int i = 0; i < exec; i++)
    {
        int seed = distribution(generator);
        heuristica(seed, n, W, itens);
    }
    return 0;
}