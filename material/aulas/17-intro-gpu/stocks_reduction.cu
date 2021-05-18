//  g++ -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -I../../../thrust/ -fopenmp -x c++ stocks_reduction.cu -o stocks_reduction-cpu && ./stocks_reduction-cpu < stocks.txt
// https://thrust.github.io/doc/group__reductions.html
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <thrust/reduce.h>
#include <chrono>

int main()
{
    int N = 0;
    thrust::host_vector<double> vec_cpu;

    while (std::cin.fail() == false)
    {
        N += 1;

        double price;
        std::cin >> price;
        vec_cpu.push_back(price);
    }

    // std::cout << N << "\n";

    thrust::device_vector<double>
        vec_gpu(vec_cpu);

    // porque eu vou querer transferir do host vector para o device vector para fazer as coisas de reduce?

    // O preço médio das ações nos últimos 10 anos.
    double mean = thrust::reduce(vec_gpu.begin(), vec_gpu.end(), 0, thrust::plus<double>()) / N;
    std::cout << "preço médio no último 10 anos: " << mean << "\n";

    //O preço médio das ações no último ano (365 dias atrás).
    double mean_year = thrust::reduce(vec_gpu.begin() + N - 365, vec_gpu.end(), 0, thrust::plus<double>()) / N;
    std::cout << "maior valor do último ano: " << mean_year << "\n";

    // maior valor da sequência inteira
    double max = thrust::reduce(vec_gpu.begin(), vec_gpu.end(), 0, thrust::maximum<double>());
    std::cout << "maior valor da sequência inteira: " << max << "\n";

    // menor valor da sequência inteira
    double min = thrust::reduce(vec_gpu.begin(), vec_gpu.end(), max, thrust::minimum<double>());
    std::cout << "menor valor da sequência inteira: " << min << "\n";

    // maior valor do último ano
    double max_year = thrust::reduce(vec_gpu.begin() + N - 365, vec_gpu.end(), 0, thrust::maximum<double>());
    std::cout << "maior valor do último ano: " << max_year << "\n";

    // menor valor do último ano
    double min_year = thrust::reduce(vec_gpu.begin() + N - 365, vec_gpu.end(), max_year, thrust::minimum<double>());
    std::cout << "menor valor do último ano: " << min_year << "\n";
}