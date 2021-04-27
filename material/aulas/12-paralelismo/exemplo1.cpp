// g++ -O3 exemplo1.cpp -o exemplo1 -fopenmp && ./exemplo1
// g++ -O3 exemplo1.cpp -o exemplo1 -fopenmp && OMP_NUM_THREADS=2 ./exemplo1
#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
        std::cout << "ID:" << omp_get_thread_num() << "/" << omp_get_num_threads() << "\n";
    }
    std::cout << "Join implicito no fim do bloco!"
              << "\n";
    return 0;
}
