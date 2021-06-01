#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random/uniform_real_distribution.h>

// nvcc -arch=sm_70 -std=c++14 exemplo2.cu -o exemplo2 && ./exemplo2

struct random_ex{
    thrust::minstd_rand rng;
    thrust::uniform_real_distribution<double> dist;

    random_ex(thrust::uniform_real_distribution<double> dist, thrust::minstd_rand rng) : dist(dist), rng(rng) {}
    __host__ __device__ 
    double operator()(const double& x){
         // default_random_engine is currently an alias for minstd_rand, and may change in a future version.
        
        return dist(rng);
    }
};

int main(){
    int seed;
    std::cin >> seed;

    thrust::minstd_rand rng(seed);
    thrust::uniform_real_distribution<double> dist(25, 40);
    
    thrust::host_vector<double> host(10, 0);
    thrust::transform(host.begin(), host.end(), host.begin(), random_ex(dist, rng));

    printf("Host vector: ");
    for (auto i = host.begin(); i != host.end(); i++)
    {
        std::cout << *i << " "; // este acesso é rápido -- CPU
    }
}