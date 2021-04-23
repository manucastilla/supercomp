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
} Person;

// não deu tempo de fazer esta questão, porém o racicionio seria
// fazer a mms e depois comparar com os que vieram do input (in.txt)
// se o mms calculado for melhor que o mms do input, retornar um não,
// caso o contrario retornar um sim

int main()
{

    int M;
    int N;

    cin >> M >> N;

    vector<Person> vec_people;

    for (int i = 0; i < N; i++)
    {
        Person obj;
        obj.value = vector<int>();
        obj.doces_recebidos = vector<int>();
        obj.mms = 0;
        obj.idx = i + 1;

        vec_people.push_back(obj);
    }

    return 0;
}