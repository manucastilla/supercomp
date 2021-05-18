// g++ -O3 pi_montecarlo.cpp -o pi_montecarlo -fopenmp && time ./pi_montecarlo
#include <iostream>
#include <cstdlib>
using namespace std;
#include <algorithm>
#include <random>
#include <math.h>

// time 0m0.011s // 0.005s
// valor 3.14032
int main()
{
    double sum = 0;
    int N = 100000;

    std::default_random_engine generator;
    // operacao que gera efeito colateral (sequencial)
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < N; i++)
    {
        double x = distribution(generator);
        double y = distribution(generator);
        double power = pow(x, 2) + pow(y, 2);
        if (power <= 1)
        {
            sum++;
        }
    }

    cout
        << "soma: " << sum << "\n";

    cout
        << "saída: " << 4 * sum / N << "\n";

    return 0;
}