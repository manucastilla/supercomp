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
    peso = 0;
    valor = 0;

    default_random_engine generator;
    generator.seed(randomSeed);
    uniform_real_distribution<double>
        distribution(0.0, 1.0);
    // gera número

    for (int i = 0; i < N; i++)
    {
        double prob = distribution(generator);

        if ((prob <= 0.25) && (vec_itens[i].used != true))
        {

            uniform_int_distribution<int> distributionN(i, N - 1);
            int itemSel = distributionN(generator);

            item temp;
            for (int j = itemSel; j < i; j--)
            {
                // desloca tudo para direita
                temp = vec_itens[j];
                vec_itens[j] = vec_itens[j - 1];
                vec_itens[j - 1] = temp;
            }
        }

        if (vec_itens[i].peso + peso <= W)
        {
            peso += vec_itens[i].peso;
            T += 1;
            objsSel[T] = vec_itens[i].idx;
            valor += vec_itens[i].valor;
            vec_itens[i].used = true;
        }
    }

    cout << peso << " " << valor << " " << 0 << "\n";
    sort(objsSel.begin(), objsSel.begin() + T);

    for (int i = 0; i < T; i++)
    {
        cout << objsSel[i] << " ";
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

    for (int i = 0; i < vezes; i++)
    {
        int newSeed = randomSeed(generator);
        heuristica(vec_itens, objsSel, N, W, newSeed);

        cout << "\n";
    }

    // heuristica(vec_itens, objsSel, N, W);

    return 0;
}