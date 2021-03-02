#include <iostream> // std::cout, std::fixed
#include <iomanip>  // std::setprecision
#include <math.h>   // std::setprecision
#include <vector>

int main()
{
    //tarefa 1
    // int a = 10;
    // double b = 3.2;
    // std::cout << "Saída: " << a << ";" << b << "\n";

    // int a;
    // double b;
    // std::cin >> a >> b;
    // std::cout << "Saída: " << a << ";" << b << "\n";

    // tarefa 2
    // int n;
    // double resultado;
    // std::cin >> n;

    // resultado = double(n) / 2.0;
    // std::cout << "Saída: " << resultado << "\n";

    // tarefa 3
    // int n;
    // double s;
    // std::cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     s += 1 / pow(2, double(i));
    // }

    // std::cout << "Saída: " << std::setprecision(15) << s << '\n';

    // tarefa 4
    int n;
    std::cin >> n;
    double *vec = new double[n];

    // values[0] = 0.5402024957828215;
    // values[1] = 0.5269142113097988;
    // values[2] = 0.9733788638376613;

    for (int j = 0; j < n; j++)
    {
        std::cin >> vec[j];
        std::cout << "VECTOR: " << vec[j] << "\n";
    }

    double soma_media = 0;
    // double soma_sigma = 0;
    double media;
    for (int i = 0; i < n; i++)
    {
        soma_media += vec[i];
    }
    media = double(soma_media) / n;
    std::cout << "Saída: " << std::setprecision(15) << media << '\n';
    delete[] vec;
}