#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision
#include <math.h>   // std::setprecision
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<double> vec;

    double a = 0;
    for (int j = 0; j < n; j++)
    {
        std::cin >> a;
        vec.push_back(a);
    }

    double media = 0;
    double sigma = 0;

    for (int i = 0; i < n; i++)
    {
        media += double(1 / n) * vec[i];
    }

    for (int i = 0; i < n; i++)
    {
        sigma += double(1 / n) * std::pow((vec[i] - media), 2);
    }

    std::cout << "Saída: " << std::setprecision(15) << media << std::setprecision(15) << sigma << '\n';
}