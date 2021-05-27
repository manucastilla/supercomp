#include <thrust/copy.h>

struct limiar {
    int cols;
    __host__ __device__
    unsigned operator(const unsigned char *el){
        return 255;

    }
}

int main(int argc, char *argv[]){
    Imagem im = Imagem::read(std::string(argv[1]));

    // quero copiar pixels, total_size e cols
    // copiar para a gpu
    thrust::device_vector<unsigned char> pixels_gpu(im.pixels, im.pixels + im.total_size);

    // transform
    thrust::transform(pixels_gpu.begin(), pixels_gpu.end(), pixels_gpu.begin(), limiar());

    // copia de volta para a cpu
    thrust::copy(pixels_gpu.begin(), pixels_gpu.end(), im.pixels);
    im.write("out.pgm")
}