//g++ -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -I../../../thrust/ -fopenmp -x c++ stock-apple-micro.cu -o stock-apple-micro-cpu && ./stock-apple-micro-cpu < stocks2.csv

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>

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

    // diference
    thrust::transform(MSFT.begin(), MSFT.end(), AAPL.begin(), diferenca.begin(), thrust::minus<double>());

    // mean
    double mean = thrust::reduce(diferenca.begin(), diferenca.end(), 0, thrust::plus<double>()) / N;
    std::cout << "diferença média entre os preços das ações AAPL e MSFT: " << mean << "\n";
}