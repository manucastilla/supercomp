#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random/uniform_real_distribution.h>

// nvcc -arch=sm_70 -std=c++14 exemplo1.cu -o exemplo1 && ./exemplo1


int main()
{
    int seed;
    std::cin >> seed;
    
    // default_random_engine is currently an alias for minstd_rand, and may change in a future version.
    thrust::minstd_rand rng(seed);
    thrust::uniform_real_distribution<double> urd(25, 40);

    for(int i = 0; i< 10; i ++)
    {
        std::cout << urd(rng) << " ";
    }    

    std::cout << "\n";
}