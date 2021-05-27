// g++ -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -I../../../thrust/ -fopenmp -x c++ exemplo2.cu -o exemplo2 && ./exemplo2 < ../17-intro-gpu/stocks2.csv
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <math.h>
#include <thrust/iterator/constant_iterator.h>

int main()
{
    int N = 0;
    thrust::host_vector<double> hostMicrosoft;
    thrust::host_vector<double> hostApple;

    double a, m;
    while (std::cin.fail() == false)
    {
        N += 1;

        std::cin >> a;
        std::cin >> m;
        hostMicrosoft.push_back(m);
        hostApple.push_back(a);
    }

    thrust::device_vector<double> diferenca(N);
    thrust::device_vector<double> MSFT(hostMicrosoft);
    thrust::device_vector<double> AAPL(hostApple);
    thrust::device_vector<double> mean_vector(N);
    thrust::device_vector<double> var(N);
    thrust::device_vector<double> var_double(N);

    // diference
    thrust::transform(MSFT.begin(), MSFT.end(), AAPL.begin(), diferenca.begin(), thrust::minus<double>());

    // mean
    double mean = thrust::reduce(diferenca.begin(), diferenca.end(), 0, thrust::plus<double>()) / N;

    // thrust::fill(mean_vector.begin(), mean_vector.end(), mean);

    thrust::transform(diferenca.begin(), diferenca.end(), thrust::constant_iterator<double>(mean), var.begin(), thrust::minus<double>());

    thrust::transform(var.begin(), var.end(), var.begin(),
                      var_double.begin(), thrust::multiplies<double>());

    // for (auto i = var_double.begin(); i != var_double.end(); i++)
    // {
    //     std::cout << *i / N << " "; // este acesso é rápido -- CPU
    // }
    double variancia = thrust::reduce(var_double.begin(), var_double.end(), 0, thrust::plus<double>()) / N;
    std::cout << "variancia: " << variancia << "\n";
}