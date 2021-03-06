//g++ -O3 vetor_insert.cpp -o vetor_insert -fopenmp && time ./vetor_insert
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
	int N = 10000;
	std::vector<double> vec;

#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		vec.push_back(conta_complexa(i));
	}
	// #pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		std::cout << i << " ";
	}

	return 0;
}
