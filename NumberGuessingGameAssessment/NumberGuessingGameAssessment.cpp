#include <iostream>

bool detectCheat(int min, int max)
{
	int difference = max - min;
	if (difference <= 1)
	{
		std::cout << "YOU FILTHY CHEAT" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}