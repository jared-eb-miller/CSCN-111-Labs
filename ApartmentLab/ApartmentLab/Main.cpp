/******************************************************************************
(Apartment problem) A real estate office handles, say, 50 apartment units.
When the rent is, say, $600 per month, all the units are occupied. However,
for each, say, $40 increase in rent, one unit becomes vacant. Moreover, each
occupied unit requires an average of $27 per month for maintenance. How many
units should be rented to maximize the profit?

Write a program that reads the following from an input file (provided)

	The total number of units.

	The rent to occupy all the units.

	The Amount to maintain a rented unit (maintenance fee).

And prompts the user to enter the following:

	The increase in rent that results in a vacant unit.

The program then outputs the number of units to be rented to maximize the profit.
Algorithm:
	while (profit goes up)
	{
		increase the monthly rent
		decrease number of units rented by one
		calculate the profit which is (rent - maintenance fee) * number of units rented
	}
	output the results (remember to back out the last changes made to monthly rent,
	number of units, and profit above -- why do you need to back out the last changes)
		number of units rented
		monthly rent
		total profit

Malik, Ch 6, Programming Exercise 28 (page 345)
******************************************************************************/
//Include statements
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
//include any missing standard libraries required to complete the program

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 5" << endl << endl;

	//Variable declarations
	int numUnits = 0;
	int totalUnits = 0;
	float rent = 0.0;
	float baseRent = 0.0;
	float maintenance = 0.0;
	float rentIncrease = 0.0;
	float profit = 0.0;
	ifstream in;

	//Program logic
	// Open, read, and close file
	in.open("input.dat");
	in >> totalUnits;
	in >> baseRent;
	in >> maintenance;

	if (in.fail())
		cout << "ERROR. Could not read input file.";

	in.close();

	// Prompt user for the increase in rent that results in a vacant unit
	cout << "Please enter the increase in rent that results in a vacant unit: $";
	cin >> rentIncrease;
	while (cin.fail() || rentIncrease < 0)
	{
		cout << "ERROR. Please enter a positive rent increase value: $";
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> rentIncrease;
	}

	// Calculate max profit scenario
	numUnits = totalUnits;
	rent = baseRent;
	do
	{
		profit = numUnits * (rent - maintenance);
		numUnits -= 1;
		rent += rentIncrease;
	} while (profit < numUnits * (rent - maintenance));

	numUnits += 1; //undo one loop iteration for accurate result
	rent -= rentIncrease;

	// Output the result
	cout << endl;
	cout << "Number of units rented: " << numUnits << endl;
	cout << "Monthly rent: $" << fixed << setprecision(2) << rent << endl;
	cout << "Total profit: $" << profit << endl << endl;

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