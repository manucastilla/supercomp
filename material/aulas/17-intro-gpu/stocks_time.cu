//  g++ -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -I../../../thrust/ -fopenmp -x c++ stocks_time.cu -o stocks_time-cpu && ./stocks_time-cpu < stocks.txt
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
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

    std::cout << N << "\n";

    // alocado na CPU

    // aloca vetor na GPU e transfere dados CPU->GPU
    std::chrono::time_point<std::chrono::system_clock> start, end, start_c, end_c;
    start = std::chrono::system_clock::now();

    thrust::device_vector<double>
        vec_gpu(vec_cpu);

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "elapsed time da alocação e cópia: " << elapsed_seconds.count() << "s\n";
    //processa vec_gpu

    // ver os tempos separados
    // apenas alocação
    //thrust::device_vector<double>
    //   vec_gpu(sizeof(vec_cpu));
    //apenas cópia
    // vec_gpu = ve= cpu;
}