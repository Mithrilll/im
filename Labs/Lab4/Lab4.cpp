#include <iostream>
#include <cmath>
#include <vector>

#include "Library.h"

void showGistogram(const std::vector<int> &gist, int offset)
{
	int num_gists = gist.size() + offset;
	int max_height = 0;
	for (int i = 0; i < gist.size(); ++i)
		if (gist[i] / 10 > max_height)
			max_height = gist[i] / 10;

	std::vector<std::vector<char>> temp(num_gists);

	for (int i = 0; i < offset; ++i)
		temp[i].resize(max_height, ' ');

	for (int i = offset; i < num_gists; ++i)
	{
		temp[i].resize(max_height, ' ');
		for (int j = 0; j < gist[i - offset] / 10; ++j)
			temp[i][j] = '*';
	}

	
	std::vector<std::vector<char>> gistogram(max_height);
	for(int i = 0; i < max_height; ++i)
	{
		gistogram[i].resize(num_gists);
		for (int j = 0; j < num_gists; ++j)
			gistogram[i][j] = temp[j][max_height - i - 1];
	}

	for (int i = 0; i < gistogram.size(); ++i)
	{
		for (int j = 0; j < gistogram[i].size(); ++j)
			std::cout << gistogram[i][j];
		std::cout << std::endl;
	}
}

bool sigmaRuleCheck(const std::vector<double>& sample, const double average, const double deviation)
{
	int cnt = 0;
	for (int i = 0; i < sample.size(); ++i)
		if (abs(sample[i] - average) < 3 * deviation)
			cnt++;

	return (cnt * 1.0 / sample.size()) >= 0.9973;
}

int main()
{
	int N = 10000;
	double a = 0;
	double b = 2;

	double avg = 0.0f;

	std::vector<double> sample(N);
	for (int i = 0; i < N; ++i)
	{
		sample[i] = getNormal(a, b);
		avg += sample[i] / N;
	}

	double var = 0.0f;

	for (int i = 0; i < N; ++i)
	{
		var += (sample[i] - avg) * (sample[i] - avg) / (N - 1);
	}

	double dev = sqrt(var);

	std::cout << "Average: " << avg << std::endl;
	std::cout << "Deviation: " << dev << std::endl;

	if (sigmaRuleCheck(sample, avg, dev))
		std::cout << "Corresponds sigma rule"  << std::endl;
	else
		std::cout << "Not corresponds sigma rule"  << std::endl;

	// Gistogram
	double min = -5.0;
	double max = 5.0;
	double h= 0.1;
	int gists_count = (max - min) / h + 1;

	std::vector<int> gist(gists_count, 0);

	for (int i = 0; i < gists_count; ++i)
	{
		gist[i] = 0;
		double local_min = min + i * h;
		double local_max = local_min + h;

		for (int j = 0; j < N; ++j)
			if (local_min < sample[j] && sample[j] < local_max)
				++gist[i];
	}

	showGistogram(gist, 4);
	std::cout << min << " |";
	for (int i = 0; i < gist.size(); ++i)
		std::cout << "-";
	std::cout << "| " << max << std::endl;

	return 0;
}