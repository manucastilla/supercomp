#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision
#include <math.h>   // std::setprecision
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<double> vec;

    // std::cout << n;
    double a;
    for (int j = 0; j < n; j++)
    {
        std::cin >> a;
        vec.push_back(a);
    }

    double media = 0.0;
    double sigma = 0.0;

    for (int i = 0; i < n; i++)
    {
        media += vec[i] / n;
    }

    for (int i = 0; i < n; i++)
    {
        sigma += std::pow((vec[i] - media), 2) / n;
    }

    std::cout << std::fixed;
    std::cout << "Saída: " << std::setprecision(15) << media << " " << std::setprecision(15) << sigma << '\n';
}