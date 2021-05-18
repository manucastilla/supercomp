
// g++ -O3 pi_montecarlo-par.cpp -o pi_montecarlo-par -fopenmp &&&& time ./pi_montecarlo-par
// time : 0m0.011s
#include <iostream>
#include <cstdlib>
using namespace std;
#include <algorithm>
#include <random>
#include <math.h>
// time 0m0.032s

int main()
{
    double sum = 0;
    int N = 100000;

    std::default_random_engine generator;
    // operacao que gera efeito colateral (sequencial)

    std::uniform_real_distribution<double> distribution(0.0, 1.0);

#pragma omp parallel for reduction(+ \
                                   : sum)

    for (int i = 0; i < N; i++)
    {
        double x, y;

#pragma omp critical
        {
            x = distribution(generator);
            y = distribution(generator);
        }
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