#include <iostream>
#include <cmath>
#include <vector>

#include "Library.h"

double func(double alpha)
{
	// 8 * x / (PI * (4 + x^4))
	//
	// x
	// S (8 * x / (PI * (4 + x^4)))du = 2 arctg(x^2/2)/PI
	// 0
	//
	// ksi = sqrt(2 * tg(PI * a / 2)

	return sqrt(2 * tan(PI * alpha / 2));
}

std::pair<double, double> test(int K)
{
	std::pair<double, double> ans = std::make_pair<double, double>(0, 0);

	for (int k = 0; k < K; ++k)
	{
		int N = 10000;
		std::vector<double> arr;
		arr.resize(N);

		double avg = 0.0f;

		for (int i = 0; i < N; ++i)
		{
			arr[i] = getContinuous(&func, 0, 10);
			//std::cout << arr[i] << std::endl;
			avg += arr[i] / N;
		}

		double var = 0.0f;

		for (int i = 0; i < N; ++i)
		{
			var += (arr[i] - avg) * (arr[i] - avg) / (N - 1);
		}

		ans.first += avg / K;
		ans.second += var / K;
	}

	return ans;
}

int main()
{
	auto ans = test(1000);

	std::cout << "Average: " << ans.first << std::endl;
	std::cout << "Variance: " << ans.second << std::endl;

	return 0;
}