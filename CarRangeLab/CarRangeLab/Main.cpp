// CarRangeLab -- Write a program that prompts the capacity, in gallons, 
//  of an automobile fuel tank and the miles per gallon the automobile 
//  can be driven. The program outputs the number of miles the automobile 
//  can be driven without refueling.
// CSIS 111-005


//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 2" << endl << endl;

	//Variable declarations
	int tankCapacity = 0;
	int milesPerGallon = 0;
	int range = 0;

	//Program logic
	//	Prompt user for tank capacity and miles per gallon
	cout << "Enter your car's tank capacity (in gallons):" << endl;
	cin >> tankCapacity;

	cout << "Enter your car's fuel economy (in miles per gallon):" << endl;
	cin >> milesPerGallon;

	//	Calculate the car's range and assign it to the variable range
	range = tankCapacity * milesPerGallon;

	//	Output the cars range as well as what the user entered.
	cout << endl << "-- Entered values --" << endl;
	cout << "Tank capacity:  " << tankCapacity << " gal" << endl;
	cout << "Fuel economy:   " << milesPerGallon << " mpg" << endl << endl;
	cout << "Theoretical range: " << range << " mi" << endl;

	//Closing program statements
	wait();
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
