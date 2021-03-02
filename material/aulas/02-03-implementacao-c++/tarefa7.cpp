#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision
#include <math.h>   // std::setprecision
#include <vector>
using namespace std;

void calcula_distancias(vector<vector<double>> &M, vector<double> &x, vector<double> &y) // argumento aqui
{

    int n;
    n = x.size();
    // n pegar pelo size
    double deltaX;
    double deltaY;
    for (int i = 0; i < n; i++)
    {
        std::vector<double> l;
        M.push_back(l);
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                M[i].push_back(M[i][j]);
            }
            else
            {
                deltaX = x[i] - x[j];
                deltaY = y[i] - y[j];
                M[i].push_back(sqrt(deltaX * deltaX + deltaY * deltaY));
            }
        }
    }
}
int main()
{
    int n;
    std::cin >> n;

    vector<double> x;
    vector<double> y;

    double inputX, inputY;

    for (int i = 0; i < n * 2; i++)
    {
        cin >> inputX >> inputY;
        x.push_back(inputX);
        y.push_back(inputY);
    }

    vector<vector<double>> D;
    // vetor intero é uma linha

    calcula_distancias(D, x, y);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(2) << D[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}