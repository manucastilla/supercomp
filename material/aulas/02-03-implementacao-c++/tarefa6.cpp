#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision
#include <math.h>   // std::setprecision
#include <vector>
using namespace std;

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

    double deltaX;
    double deltaY;
    for (int i = 0; i < n; i++)
    {
        std::vector<double> l;
        for (int j = 0; j < n; j++)
        {
            deltaX = x[i] - x[j];
            deltaY = y[i] - y[j];
            l.push_back(sqrt(deltaX * deltaX + deltaY * deltaY));
        }

        D.push_back(l);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(2) << D[i][j] << " ";
        }
        std::cout << "\n";
    }
}