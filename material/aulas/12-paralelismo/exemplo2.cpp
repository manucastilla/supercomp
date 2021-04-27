// g++ -O3 exemplo2.cpp -o exemplo2 -fopenmp && ./exemplo2
// g++ -O3 exemplo2.cpp -o exemplo2 -fopenmp && OMP_NUM_THREADS=2 ./exemplo2
#include <iostream>
#include <omp.h>

int main()
{
    int res = 1;
#pragma omp parallel
    {
        for (int i = 0; i < 1000; i++)
        {
            res += 1;
        }
    }
    std::cout << res << "\n";
    return 0;
}