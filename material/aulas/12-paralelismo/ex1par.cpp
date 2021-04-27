// g++ -O3 ex1par.cpp -o ex1par -fopenmp && ./ex1par
// g++ -O3 ex1par.cpp -o ex1par -fopenmp && OMP_NUM_THREADS=2 ./ex1par
#include <iostream>
#include <omp.h>
#include <unistd.h>

double funcao1()
{
    sleep(5);
    return 3.5;
}

double funcao2()
{
    return 700;
}

int main()
{
    double rf1, rf2;

#pragma omp parallel
    {
#pragma omp master
        {
#pragma omp task
            {
                rf1 = funcao1();
            }
#pragma omp task
            {
                rf2 = funcao2();
            }
        }
    }

    std::cout << rf1 << " " << rf2 << "\n";
}
