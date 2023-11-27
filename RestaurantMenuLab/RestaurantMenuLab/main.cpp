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
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const string FILE_NAME = "menu.txt";
struct MenuItemType
{
	string menuItem;
	double menuPrice;
	bool isOrdered;
};

//Function prototypes
void wait(); // given

// Function 1 - 
void getData();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 09" << endl << endl;

	//Variable declarations

	//Program logic

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
