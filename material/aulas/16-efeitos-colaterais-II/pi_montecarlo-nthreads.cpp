
// g++ -O3 pi_montecarlo-nthreads.cpp -o pi_montecarlo-nthreads -fopenmp && time ./pi_montecarlo-nthreads
// time : 0m0.011s
#include <iostream>
#include <cstdlib>
using namespace std;
#include <algorithm>
#include <random>
#include <math.h>
#include <omp.h>
// time
// valor

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

    int Nthread = omp_get_max_threads();
    vector<default_random_engine> gThread(Nthread);

    for (int i = 0; i < Nthread; i++)
    {
        default_random_engine generator(i * 100);
        gThread[i] = generator;
    }

    // std::generator(seed);
    // operacao que gera efeito colateral (sequencial)
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < N; i++)
    {

        x = distribution(gThread[omp_get_thread_num()]);
        y = distribution(gThread[omp_get_thread_num()]);

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

    cout << omp_get_num_threads() << "\n";

    return 0;
}