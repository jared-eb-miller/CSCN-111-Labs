/*
	Write a program to help a local restaurant automate its breakfast billing system. 
	The program should do the following:

	1. Show the customer the different breakfast items offered by the restaurant.

	2. Allow the customer to select more than one item from the menu.

	3. Calculate and print the bill.

	Use an array menuList of type MenuItemType. MenuItemType consists of three components:
		menuItem of type string,
		menuPrice of type double, and
		isOrdered of type bool.

	Your program must contain at least the following functions:

	1. Function getData: This function loads the data into the array menuList from the file 
	menu.txt.

	2. Function showMenu: This function shows the different items offered by the restaurant 
	and tells the user how to select the items.

	3. Function printCheck: This function calculates and prints the check. (Note that the 
	billing amount should include a 5% tax.)

	Format your output with two decimal places. The name of each item in the output must be 
	left justified. You may assume that the user selects only one item of a particular type.

	Algorithm:
		main
		{
			GetData
			do {
				showMenu
			} while not done
			printCheck
		}
*/

//Include statements
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const string FILE_NAME = "menu.txt";
const int MENU_LEN = 8;
const float TAX_RATE = 0.05; // 5% tax
struct MenuItemType
{
	string menuItem;
	double menuPrice;
	bool isOrdered;
};

//Function prototypes
void wait(); // given

// Function 1 - loads the data into the array menuList from the text file
void getData(MenuItemType menuArray[MENU_LEN]);

// Function 2 - shows the different items offered by the restaurant and tells 
//  the user how to select the items.
void showMenu(MenuItemType menuArray[MENU_LEN]);

// Function 3 - asks the user if they are finished and returns the parsed and 
//  error checked result
bool userIsFinished();

// Function 4 - calculates and prints the check. (Note that the billing amount 
//  should include a 5% tax.)
void printCheck(MenuItemType menuArray[MENU_LEN]);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 09" << endl << endl;

	//Variable declarations
	MenuItemType menuList[MENU_LEN];

	//Program logic
	cout << "-- Welcome to Jared's Restaurant --" << endl << endl;

	getData(menuList);

	do {
		showMenu(menuList);
	} while (!userIsFinished());

	printCheck(menuList);

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

// Function 1 - loads the data into the array menuList from the text file
void getData(MenuItemType menuArray[MENU_LEN])
{
	// locals
	ifstream inFile;
	inFile.open(FILE_NAME);

	// extract data out of file and into correct location
	for (int i = 0; i < MENU_LEN; i++)
	{
		getline(inFile, menuArray[i].menuItem); // stores string
		inFile >> menuArray[i].menuPrice; // stores price
		menuArray[i].isOrdered = false;
		inFile.ignore(1);
	}
}

// Function 2 - shows the different items offered by the restaurant and tells 
//  the user how to select the items.
void showMenu(MenuItemType menuArray[MENU_LEN])
{
	// locals
	const int COLUMN_WIDTH = 20;
	int itemNumber = 0;

	// Format upcoming display
	cout << fixed << setprecision(2) << left;

	cout << "Menu:" << endl;

	for (int i = 0; i < MENU_LEN; i++)
	{
		// don't display menu itens that have already been ordered
		if (menuArray[i].isOrdered) 
		{
			string s;
			// construct the string
			for (int j = 0; j < COLUMN_WIDTH; j++)
			{
				if (j < menuArray[i].menuItem.length())
				{
					s += '-';
				}
				else
				{
					s += ' ';
				}
			}

			cout << " -- " << setw(COLUMN_WIDTH) << s << "-----" << endl;
			continue;
		} 

		cout << " " << i+1 << ". " << setw(COLUMN_WIDTH) << menuArray[i].menuItem;
		cout << "$" << menuArray[i].menuPrice << endl;
	}

	cout << endl;

	// Get user choice
	cout << "Please enter the number of the item you would like to order: ";
	cin >> itemNumber;
	// Error check the input
	while (cin.fail() || itemNumber > MENU_LEN || itemNumber < 1)
	{
		cout << "ERROR. Please enter a valid item number: ";
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> itemNumber;
	}

	menuArray[itemNumber - 1].isOrdered = true;
}

// Function 3 - asks the user if they are finished and returns the parsed and 
//  error checked result
bool userIsFinished()
{
	// locals
	char resp = ' ';

	// Ask to continue
	cout << "Would you like to another item? (y/n) ";
	cin >> resp;
	// Error check the input
	while (cin.fail() || (resp != 'y' && resp != 'n'))
	{
		cout << "ERROR. Please enter either 'y' or 'n': ";
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> resp;
	}

	cout << endl;

	return (resp == 'n');
}

// Function 4 - calculates and prints the check. (Note that the billing amount 
//  should include a 5% tax.)
void printCheck(MenuItemType menuArray[MENU_LEN])
{
	// locals
	const int COLUMN_WIDTH = 20;
	double total = 0;
	double tax = 0;

	// Format upcoming display
	cout << fixed << setprecision(2) << left;

	// Print out the user's order
	cout << "Your order:" << endl;

	for (int i = 0; i < MENU_LEN; i++)
	{
		// don't display menu itens that were not ordered
		if (!menuArray[i].isOrdered) { continue; }

		cout << " " << i + 1 << ". " << setw(COLUMN_WIDTH) << menuArray[i].menuItem;
		cout << "$" << menuArray[i].menuPrice << endl;

		total += menuArray[i].menuPrice;
	}
	
	// Calculate and add tax
	tax = total * TAX_RATE;
	total += tax;

	// Display tax
	cout << "------------------------------" << endl;
	cout << " Tax (5%)               $" << tax << endl;
	cout << " Total                  $" << total << endl << endl;

	// Say goodbye
	cout << "Thank you for your order at Jared's Restaurant!" << endl << endl;
}