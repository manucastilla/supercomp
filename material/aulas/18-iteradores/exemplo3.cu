// g++ -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -I../../../thrust/ -fopenmp -x c++ exemplo3.cu -o exemplo3 && ./exemplo3 < ../17-intro-gpu/stocks.txt
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <thrust/count.h>

struct is_positivo
{
    __host__ __device__ bool operator()(const double &x)
    {
        return x > 0;
    }
};

struct is_negative
{
    __host__ __device__ bool operator()(const double &x)
    {
        return x < 0;
    }
};

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
        stocks(vec_cpu);

    thrust::device_vector<double> ganho_diario(N - 1);

    thrust::transform(stocks.begin() + 1, stocks.end(), stocks.begin(), ganho_diario.begin(), thrust::minus<double>());

    // quantas vezes o valor subiu?
    int result = thrust::count_if(ganho_diario.begin(), ganho_diario.end(), is_positivo());
    std::cout << result << "\n";

    // qual é o aumento médio, considerando só as vezes em que o valor aumentou de fato?
    thrust::replace_if(ganho_diario.begin(), ganho_diario.end(), ganho_diario.begin(), is_negative(), 0);

    double positiveSoma = thrust::reduce(ganho_diario.begin(), ganho_diario.end(), 0.0, thrust::plus<double>());

    double aumento_medio = positiveSoma / result;
    std::cout << aumento_medio << "\n";

    // for (auto i = stocks.begin(); i != stocks.end(); i++)
    // {
    //     std::cout << *i << " "; // este acesso é rápido -- CPU
    // }
    // printf("\n");

    // for (auto i = ganho_diario.begin(); i != ganho_diario.end(); i++)
    // {
    //     std::cout << *i << " "; // este acesso é rápido -- CPU
    // }
    // printf("\n");
}