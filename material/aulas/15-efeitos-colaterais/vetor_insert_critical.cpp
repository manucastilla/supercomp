//g++ -O3 vetor_insert_critical.cpp -o vetor_insert_critical -fopenmp && time ./vetor_insert_critical
#include <vector>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

double conta_complexa(int i)
{
	sleep(0.1);
	return 2 * i;
}

int main()
{
	int N = 100;
	std::vector<double> vec;

#pragma omp parallel for //default(none) shared(vec)
	for (int i = 0; i < N; i++)
	{
#pragma omp critical
		{
			vec.push_back(conta_complexa(i));
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << i << " ";
	}

	return 0;
}
