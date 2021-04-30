// g++ -O3 pi_recursivo-task.cpp -o pi_recursivo-task -fopenmp && time ./pi_recursivo-task
// 3.81436294689775 secs
#include <omp.h>
#include <iostream>
#include <iomanip>
static long num_steps = 1024l * 1024 * 1024 * 2;

#define MIN_BLK 1024 * 1024 * 256

double sum = 0;
double sum_1 = 0;

void pi_r(long Nstart, long Nfinish, double step)
{
    long i, j, iblk;
    if (Nfinish - Nstart < MIN_BLK)
    {
#pragma omp parallel
        {
#pragma omp master
            {
#pragma omp task
                for (i = Nstart; i < Nfinish; i++)
                {
                    double x = (i + 0.5) * step;
                    sum += 4.0 / (1.0 + x * x);
                }

#pragma omp task
                for (j = Nstart; j < Nfinish; j++)
                {
                    double y = (j + 0.5) * step;
                    sum_1 += 4.0 / (1.0 + y * y);
                }
#pragma omp taskwait
            }
        }
    }
    else
    {
        iblk = Nfinish - Nstart;
        pi_r(Nstart, Nfinish - iblk / 2, step);
        pi_r(Nfinish - iblk / 2, Nfinish, step);
    }

    sum = sum + sum_1;
}

int main()
{
    long i, j;
    double step, pi;
    double init_time, final_time;
    step = 1.0 / (double)num_steps;
    init_time = omp_get_wtime();
    pi_r(0, num_steps, step);
    pi = step * sum;
    final_time = omp_get_wtime() - init_time;

    std::cout << "for " << num_steps << " steps pi = " << std::setprecision(15) << pi << " in " << final_time << " secs\n";
}
