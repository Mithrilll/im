#include <iostream>

#include "Library.h"

double Play()
{
	double A[2][2] = { {8, -3},{ -1, 5} };

	int i = getDiscrete({ 6.0f / 17.0f, 11.0f / 17.0f });
	int j = getDiscrete({ 8.0f / 17.0f, 9.0f / 17.0f });

	return A[i][j];
}

int main()
{
	int N = 100000;
	double game_price = 37.0f / 17.0f;
	double winnings = 0.0f;

	for (int i = 0; i < N; ++i)
		winnings += Play();

	std::cout << "Average winnings of the first player : " << winnings / N << std::endl;
	std::cout << "Game price: " << game_price << std::endl;

	return 0;
}