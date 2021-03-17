// g++ -Wall -O3 tarefa2.cpp -o tarefa2
// ./tarefa2 < in1.txt
// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <random>

// 25% vc pega outro produto
typedef struct
{
    int valor;
    int peso;
    int idx;
    bool used;
} item;

typedef struct
{
    int peso;
    int valor;
    vector<int> ids;
} Resp;

Resp heuristica(int random, int n, int W, std::vector<item> itens)
{
    vector<int> resposta(n, 0);
    int T = 0; //objSel
    int peso_atual = 0;
    int valor_atual = 0;

    std::default_random_engine generator;
    generator.seed(random);

    std::uniform_real_distribution<double> distribution01(0.0, 1.0);

    for (int i = 0; i < n; i++)
    {
        if (distribution01(generator) <= 0.50)
        {
            if (peso_atual + itens[i].peso <= W)
            {
                resposta[T] = (itens[i].idx);
                peso_atual += itens[i].peso;
                valor_atual += itens[i].valor;
                T++;
            }
        }
    }

    Resp R;
    R.peso = peso_atual;
    R.valor = valor_atual;
    R.ids.resize(T);
    R.ids = resposta;

    return R;

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

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 100000);
    Resp a;
    Resp temp;
    int seed = distribution(generator);
    a = heuristica(seed, n, W, itens);
    int exec = 10;

    for (int i = 0; i < exec; i++)
    {
        int seed = distribution(generator);
        temp = heuristica(seed, n, W, itens);
        if (a.valor < temp.valor)
        {
            a = temp;
        }
    }

    cout << "peso: " << a.peso << " "
         << "valor: " << a.valor << '\n';

    for (int i = 0; i < a.ids.size(); i++)
    {
        std::cout << a.ids[i] << " ";
    }
    std::cout << '\n';
    return 0;
}