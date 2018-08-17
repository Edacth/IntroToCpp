#include<iostream>
void printBoard(int i);
void clearScreen();

//Declare global variables
char blank = (char)254;
char x = 'X';
char o = 'O';
char whosTurn = x;
char spaces[3][3] = { { blank, blank, blank },
					{ blank, blank, blank },
					{ blank, blank, blank } };


int main()
{
	//Declaring the selection variables
	char columnChar;
	int columnNum;
	int row;

	bool showColumnMessage = true;
	bool boardFull = false;

	while (boardFull == false)
	{
		//Prompt the user for their input

		//Column
		if (showColumnMessage == true)
		{
			clearScreen();
			printBoard(1);
		}
		showColumnMessage = true;
		
		std::cin >> columnChar;
		columnNum = (int)(toupper(columnChar));
		columnNum -= 65;
		//Validate the input as an int
		while ( (!std::cin) || (!((int)columnNum >= 0 && (int)columnNum <= 2)) )
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			clearScreen();
			printBoard(3);
			std::cin >> columnChar;
			columnNum = (int)(toupper(columnChar));
			columnNum -= 65;
		}


		//Row
		clearScreen();
		printBoard(2);
		std::cin >> row;
		row--;
		//Validate the input as an int
		while (!std::cin || (!(row >= 0 && row <= 2)))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			clearScreen();
			printBoard(4);
			std::cin >> row;
			row--;
		}


		

		if (spaces[columnNum][row] == blank)
		{
			spaces[columnNum][row] = whosTurn;
			switch (whosTurn)
			{
			case 'X':
				whosTurn = o; break;
			case 'O':
				whosTurn = x; break;

			}
		}
		else
		{
			clearScreen();
			printBoard(5);
			showColumnMessage = false;
		}

		boardFull = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (spaces[i][j] == blank)
				{
					boardFull = false;
				}
			}

			
		}

	}

	if (boardFull == true)
	{
		clearScreen();
		printBoard(6);
	}
	
	return 0;
}

void printBoard(int i)
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
	switch (i)
	{
	case 1:
		std::cout << "It is " << whosTurn << "'s turn. Please enter your column of choice. (eg. A)" << std::endl;
		break;
	case 2:
		std::cout << "It is " << whosTurn << "'s turn. Please enter your row of choice. (eg. 2)" << std::endl;
		break;
	case 3:
		std::cout << "That's not recognized input. Please try again." << std::endl;
		std::cout << "It is " << whosTurn << "'s turn. Please enter your column of choice. (eg. A)" << std::endl;
		break;
	case 4:
		std::cout << "That's not recognized input. Please try again." << std::endl;
		std::cout << "It is " << whosTurn << "'s turn. Please enter your row of choice. (eg. 2)" << std::endl;
		break;
	case 5:
		std::cout << "That space is taken. Please try again." << std::endl;
		std::cout << "It is " << whosTurn << "'s turn. Please enter your column of choice. (eg. A)" << std::endl;
		break;
	case 6:
		std::cout << "The board is full!" << std::endl;		break;
	}
}

void clearScreen()
{
	for (int i = 0; i <= 30; i++)
	{
		std::cout << std::endl;

	}
}