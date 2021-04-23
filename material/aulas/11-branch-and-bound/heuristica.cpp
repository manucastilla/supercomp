// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;

typedef struct
{
    double frac;
    double valor;
    double peso;
    int idx;
} item;

void maior_fracao(vector<item> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const item &a, const item &b) {
        return a.frac > b.frac;
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
        objAtual.frac = objAtual.valor / objAtual.peso;
        objAtual.idx = i;

        vec_itens.push_back(objAtual);
        // cout << "Saídax: " << weights[i] << '\n';
        // cout << "Saíday: " << values[i] << '\n';
    }

    maior_fracao(vec_itens);
    //mais_caro(vec_itens);

    // for (int i = 0; i < vec_itens.size(); i++)
    // {
    //     cout << vec_itens[i].peso << '\n';
    // }

    // vector<double> resposta(nObj, 0);
    // int T = 0; //objSel
    int peso_atual = 0;
    double valor_atual = 0;

    for (int i = 0; i < nObj; i++)
    {
        if (peso_atual + vec_itens[i].peso <= Wkilos)
        {

            peso_atual += vec_itens[i].peso;
            valor_atual += vec_itens[i].valor;
        }
        else
        {
            double resta = Wkilos - peso_atual;
            peso_atual += resta;
            valor_atual += resta / vec_itens[i].peso * vec_itens[i].valor;
        }
    }

    cout << "peso: " << peso_atual << " "
         << "valor: " << valor_atual << '\n';

    return 0;
}