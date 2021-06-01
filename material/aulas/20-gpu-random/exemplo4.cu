#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random/uniform_real_distribution.h>

// nvcc -arch=sm_70 -std=c++14 exemplo4.cu -o exemplo4 && ./exemplo4

struct raw_access {
    thrust::minstd_rand rng;
    thrust::uniform_real_distribution<double> dist;

    raw_access (thrust::uniform_real_distribution<double> dist, thrust::minstd_rand rng) : dist(dist), rng(rng) {};

    __device__ __host__
    double operator()(const int &i) {
        rng.seed(i*1000);
        return dist(rng);
        
    }
};

int main(){

    thrust::minstd_rand rng;
    thrust::uniform_real_distribution<double> dist(25, 40);

    thrust::device_vector<double> vetor(100000, 0);

    thrust::counting_iterator<int> iter(0);
    raw_access ra(dist, rng);
    thrust::transform(iter, iter+vetor.size(), vetor.begin(), ra);

    thrust::host_vector<double> host(vetor);

    for (auto i = host.begin(); i != host.end(); i++)
    {
        std::cout << *i << " "; // este acesso é rápido -- CPU
    }
    printf("\n");
}
