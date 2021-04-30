// g++ -O3 exemplo1.cpp -o exemplo1 -fopenmp && ./exemplo1
// g++ -O3 pi-numeric-integration.cpp -o pi-numeric-integration -fopenmp && time ./pi-numeric-integration
#include <omp.h>
#include <iostream>

int main()
{
#pragma omp parallel for
    for (int i = 0; i < 16; i++)
    {
        std::cout << i << " Eu rodei na thread: " << omp_get_thread_num() << "\n";
    }
    return 0;
}