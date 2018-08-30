#include<iostream>
#include "candles.h"

int blow(int num1, int num2, int num3, int num4, int num5, int num6)
{
	int candles[6] = { num1, num2, num3, num4, num5, num6 };
	int blownCandles = 0;
	int currentHeight = 0;

	for (int i = 0; i < 6; i++)
	{
		if (candles[i] >= currentHeight)
		{
			currentHeight = candles[i];
			blownCandles++;
		}
	}
	std::cout << "Blown candles: " << blownCandles << std::endl;
	return blownCandles;
}