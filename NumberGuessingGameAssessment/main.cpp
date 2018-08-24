#include <iostream>
#include "NumberGuessingGameAssessment.h"


int main()
{
	int guess;
	float guessFloat;
	int min = 1;
	int max = 100;
	int difference;
	char playerInput;
	bool guessCorrect = false;
	bool validInput = false;

	//Display instructions
	std::cout << "Please guess a number between 1 and 100 (Inclusive)" << std::endl
		<< "Press enter when you've thought of one." << std::endl;
	//system("pause");

	while (guessCorrect == false)
	{
		//Calculate the guess
		difference = max - min;
		guess = max - (difference / 2);
		guessFloat = (float)max - ((float)difference / 2.0f);

		//Display the guess and prompt input 
		validInput = false;
		while ( validInput == false)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "My guess is: " << guess << "  " << guessFloat << "  " << min << "  " << max << "  " << difference << std::endl
				<< "Is my guess high (H), low (L), or spot on equal (E)" << std::endl;
			std::cin >> playerInput;
			playerInput = toupper(playerInput);

			switch (playerInput)
			{
			case 'H':
				max = guess;
				validInput = true;
				break;
			case 'L':
				min = guess;
				validInput = true;
				break;
			case 'E':
				guessCorrect = true;
				validInput = true;
				break;
			default:
				std::cout << "I don't recocnize that input. Please try again." << std::endl;
			}
		}
		

		


		//Detect if there is no more space and call the player a cheater
		difference = max - min;
		if (difference <= 1)
		{
			std::cout << "YOU FILTHY CHEAT" << std::endl;
			guessCorrect = true;
		}
	}

	//Display the end state message
	std::cout << "Thank you for playing with me " << std::endl;
	system("pause");
	return 0;
}