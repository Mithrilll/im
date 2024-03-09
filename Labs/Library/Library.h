#pragma once

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

int getDiscrete(std::vector<double> distribution)
{
	double r = getRandom();

	double sum = 0.0f;

	for (int i = 0; i < distribution.size(); ++i)
	{
		if (r >= sum && r <= sum + distribution[i])
			return i;

		sum += distribution[i];
	}

	return -1;
}