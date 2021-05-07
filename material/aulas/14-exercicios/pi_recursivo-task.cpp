// g++ -O3 pi_recursivo-task.cpp -o pi_recursivo-task -fopenmp && time ./pi_recursivo-task
// 3.81436294689775 secs
#include <omp.h>
#include <iostream>
#include <iomanip>
static long num_steps = 1024l * 1024 * 1024 * 2;

#define MIN_BLK 1024 * 1024 * 256

double pi_r(long Nstart, long Nfinish, double step)
{
    double sum = 0;
    long i, j;
    if (Nfinish - Nstart < MIN_BLK)
    {

        for (j = Nstart; j < Nfinish; j++)
        {
            double y = (j + 0.5) * step;
            sum += 4.0 / (1.0 + y * y);
        }
    }

    else
    {
#pragma omp parallel
        {
#pragma omp master
            {
                long iblk = Nfinish - Nstart;
                double sum1, sum2;
#pragma omp task shared(sum1)
                {
                    sum1 = pi_r(Nstart, Nfinish - iblk / 2, step);
                }
#pragma omp task shared(sum2)
                {
                    sum2 = pi_r(Nfinish - iblk / 2, Nfinish, step);
                }
#pragma omp taskwait;
                sum = sum2 + sum1;
            }
        }
    }

    return sum;
}

int main()
{
    long i, j;
    double step, pi;
    double init_time, final_time;
    step = 1.0 / (double)num_steps;
    init_time = omp_get_wtime();
    double sum = pi_r(0, num_steps, step);
    pi = step * sum;
    final_time = omp_get_wtime() - init_time;

    std::cout << "for " << num_steps << " steps pi = " << std::setprecision(15) << pi << " in " << final_time << " secs\n";
}
