// main.cpp
// Jared Miller -- Lab 08
// CSCN 111-005
// 11-13-23

/*
ALGORITHM
	1. Bring in game board from a text file
		- create fstream variable & open file
		- read in the contents of the game board into the game board array
	2. Display the game board
		- show where the user has already fired at and their result
		- hide the unhit ships
	3. Ask the user to enter cordinates to fire at
	4. Notify the user of whether their shot was a hit or miss
	5. Update the game board
	6. Repeat steps 2-5 until all ships are sunk
	7. Display a message indicating the end of the game
*/

//Include statements
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const int GAME_BOARD_HEIGHT = 25;
const int GAME_BOARD_WIDTH = 25;

//Function prototypes
void wait(); // given

// Function 1 - displays the current state of the board to the user
void display_board(char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH]);

// Functino 2 - takes an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed.
void fire(int row, int column, char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH]);

// Function 4 - takes the game board array and returnns whether or not all ships are sunk
bool fleetSunk(char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH]);

// Function 5 - takes a string to be displayed and displays it rather boldly
void shout(string s);

int main()
{
	//In cout statement below substitute your name and lab number
	shout("Jared Miller -- Lab 08");

	//Variable declarations
	char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH] = { '~' };
	string rowString = "";
	char userRowChar = 'Z';
	int row = 0;
	int column = 0;
	fstream in;

	//Program logic
	// Bring in game board from a text file
	in.open("gameBoard.txt");
	for (int i = 0; i < GAME_BOARD_HEIGHT; i++)
	{
		getline(in, rowString);
		for (int j = 0; j < GAME_BOARD_WIDTH; j++)
		{
			gameBoard[i][j] = rowString[j];
		}
	}

	// Enter game loop
	do {
		display_board(gameBoard);
		cout << "Enter the cordinates you would like to strike in the form 'A1': ";
		cin >> userRowChar >> column;
		row = toupper(userRowChar) - 64; // 'A' has an ASCII value of 65, 'A' -> 1

		// error check user input
		while (
			cin.fail() ||
			row > GAME_BOARD_HEIGHT || row < 1 ||
			column > GAME_BOARD_WIDTH || column < 1
			) 
		{
			cout << "ERROR. Please enter a valid cordinate string: " << endl;
			cin.clear();
			cin.ignore(1000000, '\n');
			cin >> userRowChar >> column;
			row = toupper(userRowChar) - 64; // 'A' has an ASCII value of 65, 'A' -> 1
		}

		system("CLS");
		fire(row, column, gameBoard);

	} while (!fleetSunk(gameBoard));

	display_board(gameBoard);

	// just a tiny bit of ASCII art courtesy of https://www.ascii-art-generator.org/
	cout << endl << "#     # ####### #     #    #     # ####### #     # ###";
	cout << endl << " #   #  #     # #     #    #  #  # #     # ##    # ###";
	cout << endl << "  # #   #     # #     #    #  #  # #     # # #   # ###";
	cout << endl << "   #    #     # #     #    #  #  # #     # #  #  #  #";
	cout << endl << "   #    #     # #     #    #  #  # #     # #   # #";
	cout << endl << "   #    #     # #     #    #  #  # #     # #    ## ###";
	cout << endl << "   #    #######  #####      ## ##  ####### #     # ###";
	cout << endl << endl;
	cout << endl << " #####  ####### #     #  #####     #    #######  #####  ###";
	cout << endl << "#     # #     # ##    # #     #   # #      #    #     # ###";
	cout << endl << "#       #     # # #   # #        #   #     #    #       ###";
	cout << endl << "#       #     # #  #  # #  #### #     #    #     #####   #";
	cout << endl << "#       #     # #   # # #     # #######    #          #";
	cout << endl << "#     # #     # #    ## #     # #     #    #    #     # ###";
	cout << endl << " #####  ####### #     #  #####  #     #    #     #####  ###";
	cout << endl << endl << endl;

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer 
	}
	cout << "Press the Enter key to continue ... ";
	cin.get();
}

// Function 1 - displays the current state of the board to the user
void display_board(char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH])
{
	// locals
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// display the top row of column numbers
	cout << "    ";
	for (int i = 1; i <= GAME_BOARD_WIDTH; i++)
	{
		// display column numbers with consistent width
		if (i >= 10)
			cout << " " << i;
		else
			cout << "  " << i;
	}
	cout << endl << endl;

	// display the game board with row letters
	for (int i = 0; i < GAME_BOARD_HEIGHT; i++)
	{
		// display row letter with padding to the right
		cout << alphabet[i] << "   ";
		// display game board row
		for (int j = 0; j < GAME_BOARD_WIDTH; j++)
		{
			switch (gameBoard[i][j])
			{
			case '#':
				cout << "  ~"; // hide ships that have not been sunk
				break;
			case 'H':
				cout << "  H";
				break;
			case 'M':
				cout << "  M";
				break;
			default: // should be '~' case
				cout << "  ~";
			}
		}
		cout << endl;
	}
	cout << endl;
}

// Functino 2 -  takes an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed.
void fire(int row, int column, char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH])
{
	switch (gameBoard[row-1][column-1])
	{
	case 'H':
		shout("HIT AGAIN");
		break;
	case 'M':
		shout("MISS AGAIN");
		break;
	case '#':
		shout("HIT");
		gameBoard[row - 1][column - 1] = 'H';
		break;
	default: // should be '~' case
		shout("MISS");
		gameBoard[row - 1][column - 1] = 'M';
	}
}

// Function 4 - takes the game board array and returnns whether or not all ships are sunk
bool fleetSunk(char gameBoard[GAME_BOARD_HEIGHT][GAME_BOARD_WIDTH])
{
	// checks all places on the game board for unhit ships
	for (int i = 0; i < GAME_BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_BOARD_WIDTH; j++)
		{
			if (gameBoard[i][j] == '#')
				return false;
		}
	}
	return true;
}

// Function 5 - takes a string to be displayed and displays it rather boldly
void shout(string msg)
{
	// locals
	int paddingSize = 12 - size(msg) / 2; // variable padding keeps the msg centered
	char bold = '-';

	// vertical padding 1
	cout << endl;

	// horizontal padding
	for (int i = 0; i < paddingSize; i++)
	{
		cout << " ";
	}

	// display msg
	for (int i = 0; i < GAME_BOARD_WIDTH; i++)
	{
		cout << bold;
	}
	cout << "  " << msg << "  ";
	for (int i = 0; i < GAME_BOARD_WIDTH; i++)
	{
		cout << bold;
	}

	// vertical padding 2
	cout << endl << endl;
}