// $> g++ -Wall -O3 exercicio1.cpp -o exercicio1 &&./exercicio1 < entrada
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector
using namespace std;
#include <math.h>
#include <iomanip>

void calc_dist(int N, int M, vector<double> &x, vector<double> &y, vector<vector<double>> &D)
{
    double somatoria = 0.0;

    for (int i = 0; i < N; i++)
    {
        vector<double> a;
        D.push_back(a);
        for (int j = 0; j < N; j++)
        {
            somatoria += (x[j] - y[j]) * (x[j] - y[j]);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<double> x;
    vector<double> y;
    vector<vector<double>> D;

    double inputX, inputY;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> inputX >> inputY;
            x.push_back(inputX);
            y.push_back(inputY);
        }
    }

    calc_dist(N, M, x, y, D);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << fixed;
            cout << setprecision(10) << D[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << D[i][j] << " ";
    //     }

    //     cout << "\n";
    // }
}