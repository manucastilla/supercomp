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
int main()
{

    int nObj;
    std::cin >> nObj;
    int Wkilos;
    std::cin >> Wkilos;

    vector<item> vec_itens;

    for (int i = 0; i < nObj; i++)
    {
        item objAtual;
        cin >> objAtual.peso;
        cin >> objAtual.valor;
        objAtual.idx = i;
        objAtual.used = false;

        vec_itens.push_back(objAtual);
        // cout << "Saídax: " << weights[i] << '\n';
        // cout << "Saíday: " << values[i] << '\n';
    }

    // for (int i = 0; i < vec_itens.size(); i++)
    // {
    //     cout << vec_itens[i].used << '\n';
    // }

    mais_caro(vec_itens);

    std::default_random_engine generator;
    generator.seed(10);

    std::uniform_real_distribution<double> distribution01(0.0, 1.0);

    vector<double> resposta(nObj, 0);
    int T = 0; //objSel
    int peso_atual = 0;
    int valor_atual = 0;
    int escolhido;
    for (int i = 0; i < nObj; i++)
    {

        double val_025 = distribution01(generator);

        if (val_025 <= 0.25)
        {
            std::uniform_int_distribution<int> distribution(i, nObj - 1);
            int valor_int = distribution(generator);

            while (vec_itens[valor_int].used == 1)
            {
                valor_int = distribution(generator);
            }

            vec_itens[valor_int].used == 1;
            escolhido = valor_int;
        }

        else
        {
            escolhido = i;
        }

        if (peso_atual + vec_itens[escolhido].peso <= Wkilos)
        {
            resposta[T] = (vec_itens[escolhido].idx);
            peso_atual += vec_itens[escolhido].peso;
            valor_atual += vec_itens[escolhido].valor;
            T += 1;
        }
    }

    cout << "peso: " << peso_atual << " "
         << "valor: " << valor_atual << '\n';

    for (int i = 0; i < T; i++)
    {
        std::cout << resposta[i] << " ";
    }
    cout << "\n";

    return 0;
}