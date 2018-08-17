#include<iostream>
void printBoard();

//Declare global variables
char blank = (char)254;
char x = 'X';
char o = 'O';
char spaces[3][3] = { { blank, blank, blank },
					{ blank, blank, blank },
					{ blank, blank, blank } };


int main()
{
	//Declaring the selection variables
	char columnChar;
	int columnNum;
	int row;

	std::cout << "This is the game board" << std::endl;
	printBoard();


	//Prompt the user for their input
	//Row
	std::cout << "It is X's turn. Please enter your row of choice. (eg. 2)" << std::endl;
	std::cin >> row;
	//Validate the input as an int
		while (!std::cin || (!(row >= 1 && row <= 3)) )
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "That's not recognized input. Please try again." << std::endl;

			std::cout << "It is X's turn. Please enter your row of choice. (eg. 2)" << std::endl;
			std::cin >> row;
		}



	//Column
	printBoard();
	std::cout << "It is X's turn. Please enter your column of choice. (eg. A)" << std::endl;
	std::cin >> columnChar;
	columnNum = (int)columnChar;
	columnNum -= 65;
	std::cout << columnNum << std::endl;
	//Validate the input as an int
	while (!std::cin || (!((int)columnNum >= 1 && (int)columnNum <= 3)) )
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "That's not recognized input. Please try again." << columnNum << columnChar<< std::endl;

		std::cout << "It is X's turn. Please enter your column of choice. (eg. A)" << std::endl;
		std::cin >> columnChar;
	}
	spaces[columnNum][row] = x;

	return 0;
}

void printBoard()
{
	std::cout << "----------------------" << std::endl;
	std::cout << "  1 2 3" << std::endl;
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)(i + 65) << ' ';
		for (int j = 0; j < 3; j++)
		{
			std::cout << spaces[i][j] << ' ';
		}

		std::cout << std::endl;
	}
	std::cout << "----------------------" << std::endl;
}


//Dump of ascii garbage
/*
//line one
std::cout << (char)201 << (char)205 << (char)205 << (char)203  << (char)205 << (char)205 << (char)203 << (char)205 << (char)187 << std::endl;

//line two
std::cout << (char)186 << (char)00 << (char)186 << (char)00 << (char)186 << (char)00 << (char)186 << std::endl;

//line three

std::cout << (char)204 << (char)205 << (char)202 << (char)205 << (char)202 << (char)205 << (char)185 << std::endl;
*/