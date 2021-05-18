
// g++ -O3 pi_montecarlo-par-seed.cpp -o pi_montecarlo-par-seed -fopenmp &&&& time ./pi_montecarlo-par-seed
// time : 0m0.011s
#include <iostream>
#include <cstdlib>
using namespace std;
#include <algorithm>
#include <random>
#include <math.h>
// time 0m0.005s
// valor 3.14104

int main()
{
    double sum = 0;
    int N = 100000;
    double x, y;
    int seed = 1000;

    if (getenv("SEED"))
    {
        seed = atoi(getenv("SEED"));
    }

#pragma omp parallel for reduction(+ \
                                   : sum)

    for (int i = 0; i < N; i++)
    {
        seed = i * 100;
        std::default_random_engine generator(seed);
        // operacao que gera efeito colateral (sequencial)
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        x = distribution(generator);
        y = distribution(generator);

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