// g++ -Wall -O3 tarefa2.cpp -o tarefa2 && ./tarefa2 < in1a.txt
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;

typedef struct
{
    int idx;
    // int value;
    int mms;
    vector<int> value;
    vector<int> doces_recebidos;
    vector<int> doces_idx;
} Kid;

typedef struct
{
    int idx;
    bool used;
} item;

void mais_caro(vector<Kid> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const Kid &a, const Kid &b) {
        return a.value > b.value;
    });
}

void mais_doces(vector<Kid> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const Kid &a, const Kid &b) {
        return a.doces_recebidos > b.doces_recebidos;
    });
}

void mais_caro_item(vector<item> &vec_itens)
{
    sort(vec_itens.begin(), vec_itens.end(), [](const item &a, const item &b) {
        return a.idx > b.idx;
    });
}

void menor_indice(vector<Kid> &vec_Kid)
{
    sort(vec_Kid.begin(), vec_Kid.end(), [](const Kid &a, const Kid &b) {
        return a.idx < b.idx;
    });
}

int main()
{
    int M;
    int N;

    cin >> M >> N;

    vector<Kid> vec_kids;

    for (int i = 0; i < N; i++)
    {
        Kid obj;
        obj.value = vector<int>();
        obj.doces_recebidos = vector<int>();
        obj.mms = 0;
        obj.idx = i + 1;

        vec_kids.push_back(obj);
    }

    vector<double> a;
    //D.push_back(a);
    vector<item> vec_itens;

    for (int i = 0; i < M; i++)
    {
        item obj_itens;
        obj_itens.idx = i;
        obj_itens.used = false;
        vec_itens.push_back(obj_itens);
    }

    int values;
    for (int i = 0; i < N; i++)
    {
        vector<int> a;
        for (int j = 0; j < M; j++)
        {
            cin >> values;
            a.push_back(values);
            // cout << vec_kids[i].value[j] << " ";
        }

        vec_kids[i].value = a;
    }

    int temp = 0;

    // cout << vec_kids[vec_kids.size() - 1].mms << '\n';
    for (int i = 0; i < M; i++)
    {
        mais_caro_item(vec_itens);
        if (vec_itens[i].used == false)
        {
            vec_kids[temp].doces_recebidos.push_back(vec_kids[temp].value[i]);
            vec_kids[temp].doces_idx.push_back(i);
            vec_kids[temp].mms += vec_kids[temp].value[i];
            temp++;
        }
        if (temp == N)
        {
            temp = 0;
        }
    }

    mais_caro(vec_kids);
    cout << vec_kids[vec_kids.size() - 1].mms << "\n";
    menor_indice(vec_kids);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (int)vec_kids[i].doces_recebidos.size(); j++)
        {
            sort(vec_kids[i].doces_recebidos.begin(), vec_kids[i].doces_recebidos.begin() + vec_kids[i].doces_recebidos.size());
            cout << vec_kids[i].doces_recebidos[j] << " ";
        }

        cout << "\n";
    }

    // for (int i = 0; i < N; i++)
    // {
    //     sort(vec_kids[i].idx.begin(), vec_kids[i].idx.end());
    //     for (int j = 0; j < (int)vec_kids[i].idx.size(); j++)
    //     {
    //         cout << vec_kids[i].idx[j] << " ";
    //     }

    //     cout << '\n';
    // }
}
