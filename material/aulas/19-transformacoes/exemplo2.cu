// nvcc -arch=sm_70 -std=c++14 exemplo2.cu -o exemplo2 && ./exemplo2
#include "imagem.hpp"
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/reduce.h>
#include <iostream>

struct limiar
{
    // essas marcações indicam que o código deve ser compilado para CPU (host) 
    // e GPU (device)
    // IMPORTANTE: somente código com a marcação __device__ é compilado para GPU
        
        __device__ __host__
        unsigned char operator() (const unsigned char &p) {
            if(p > 127){
                return 255;
            }
            else{
                return 0;
            }
        }
        
};

int main(){
    Imagem img = Imagem::read("Manuela07.jpg");


    thrust::device_vector<unsigned char> image(img.pixels, img.pixels + img.total_size);
    thrust::device_vector<unsigned char> resultado(img.pixels, img.pixels + img.total_size);

    thrust::transform(image.begin(), image.end(), resultado.begin(), limiar());
    thrust::copy(resultado.begin(), resultado.end(), img.pixels);
    img.write("teste.pgm");
}