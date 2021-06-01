#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random/uniform_real_distribution.h>

// nvcc -arch=sm_70 -std=c++14 exemplo6_disc.cu -o exemplo6_disc && ./exemplo6_disc


struct raw_access {
    thrust::minstd_rand rng;
    thrust::uniform_real_distribution<double> dist;

    raw_access (thrust::uniform_real_distribution<double> dist, thrust::minstd_rand rng) : dist(dist), rng(rng) {};

    __device__ __host__
    double operator()(const int &i) {
        rng.discard(i * 2);
        
        double x = dist(rng);
        double y = dist(rng);
        double power = pow(x, 2) + pow(y, 2);
        if (power <= 1)
        {
            return 1.0;
        }

        return 0.0;
        
    }
};

// http://www.cplusplus.com/reference/random/linear_congruential_engine/discard/
int main(){

    int N = 10000;
    thrust::minstd_rand rng(100);
    thrust::uniform_real_distribution<double> dist(0.0, 1.0);

    thrust::device_vector<double> vetor(N);

    thrust::counting_iterator<int> iter(0);
    raw_access ra(dist, rng);
    thrust::transform(iter, iter+vetor.size(), vetor.begin(), ra);

    double sum = thrust::reduce(vetor.begin(), vetor.end(), 0.0, thrust::plus<double>());

    double pi = (double)4 * sum / N;
    std::cout << "pi de monte carlo " << pi; 
    printf("\n");
}
