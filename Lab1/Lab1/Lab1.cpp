#include <iostream>
#include <random>
#include <vector>

double getRandom()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(0, 1);

	auto ret = dist(gen);
	while (ret == 0.0f || ret == 1.0f)
	{
		ret = dist(gen);
	}

	return ret;
}

bool checkSample(std::vector<double> vec)
{
	int N = vec.size();
	int k = 16;
	std::vector<int> Ni(k);

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
	std::vector<double> sample;

	for (int i = 0; i < 30; i++)
		sample.push_back(getRandom());

	if (checkSample(sample))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}
