// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;

typedef struct
{
    double valor;
    double peso;
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

        vec_itens.push_back(objAtual);
        // cout << "Saídax: " << weights[i] << '\n';
        // cout << "Saíday: " << values[i] << '\n';
    }

    mais_leve(vec_itens);
    //mais_caro(vec_itens);

    // for (int i = 0; i < vec_itens.size(); i++)
    // {
    //     cout << vec_itens[i].peso << '\n';
    // }

    vector<double> resposta(nObj, 0);
    int T = 0; //objSel
    int peso_atual = 0;
    int valor_atual = 0;

    for (int i = 0; i < nObj; i++)
    {
        if (peso_atual + vec_itens[i].peso <= Wkilos)
        {
            resposta[T] = vec_itens[i].idx;
            peso_atual += vec_itens[i].peso;
            valor_atual += vec_itens[i].valor;
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