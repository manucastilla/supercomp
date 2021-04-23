#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;

double calcdist(vector<double> a, vector<double> b)
{
    int dim = a.size();
    double sum = 0;
    for (int k = 0; k < dim; k++)
    {
        cout << a[k] << " " << b[k] << "\n";
        sum += (a[k] - b[k]) * (a[k] - b[k]);
    }

    return sqrt(sum);
}

vector<vector<double>> com_puta(int n, vector<vector<double>> inputs)
{
    vector<vector<double>> dists(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dists[i][j] = calcdist(inputs[i], inputs[j]);
        }
    }
    return dists;
}

int main()
{

    int n, m;
    string line;
    cin >> n >> m;
    vector<vector<double>> in_matr(n, vector<double>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double a;
            cin >> a;
            in_matr[i][j] = a;
        }
    }
    auto start_time = chrono::high_resolution_clock::now();
    auto M = com_puta(n, in_matr);
    auto end_time = chrono::high_resolution_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cerr << runtime.count();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << M[i][j] << ' ';
        }
        cout << '\n';
    }
}