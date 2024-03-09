#include <iostream>
#include <vector>

#include "Library.h"

bool checkSample(std::vector<double> vec)
{
	int N = vec.size();
	int k = 16;
	std::vector<int> Ni(k, 0);

	for (int i = 0; i < vec.size(); ++i)
		++Ni[k * vec[i]];

	double chi_square = 0;

	for (int i = 0; i < k; ++i)
		chi_square += (Ni[i] - N * 1. / k) * (Ni[i] - N * 1. / k) / (N * 1. / k);

	// alpha = 0.1
	// freedom = k - 1 = 19;
	double actual = 22.307;

	std::cout << chi_square << std::endl;

	return chi_square <= actual;
}

int main()
{
	int n = 40;
	std::vector<double> sample;

	for (int i = 0; i < n; i++)
		sample.push_back(getRandom());

	for (int i = 0; i < sample.size(); ++i)
		std::cout << sample[i] << std::endl;

	if (checkSample(sample))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}
