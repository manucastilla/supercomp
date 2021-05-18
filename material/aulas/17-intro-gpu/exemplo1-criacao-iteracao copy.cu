//  g++ -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_OMP -I../../../thrust/ -fopenmp -x c++ exemplo1-criacao-iteracao.cu -o exemplo1-criacao-iteracao-cpu && ./exemplo1-criacao-iteracao-cpu

#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>

int main()
{
    thrust::host_vector<double> host(5, 0);
    host[4] = 35;

    /* na linha abaixo os dados são copiados
       para GPU */
    thrust::device_vector<double> dev(host);
    /* a linha abaixo só muda o vetor na CPU */
    host[2] = 12;

    printf("Host vector: ");
    for (auto i = host.begin(); i != host.end(); i++)
    {
        std::cout << *i << " "; // este acesso é rápido -- CPU
    }
    // i iterator:
    // host.begin() te ddar o iterador (aponta para o primeiro elemento)
    // para pegar o conteúdo do iterador para que oq está sendo apontado
    // isso serve o *
    // HOST - cpu: tua máquina, aonde programa , totalmente alocado na máquina da rápida

    printf("\n");

    printf("Device vector: ");
    // cada vez que faz *i vai buscar na gpu e fazer na cpu (mostrar na tela) tem que copiar, por isso
    // que o processo é lento.
    for (auto i = dev.begin(); i != dev.end(); i++)
    {
        std::cout << *i << " "; // este acesso é lento! -- GPU
    }
    printf("\n");
    // DEVICE - gpu: fica mais longe
}
