//Main.cpp -- brief statement as to the file’s purpose -- See assignment below.
/*	Assignment Description
	The cost of renting a room at a hotel is, say $100.00 per night. For special occasions,
	such as a wedding or conference, the hotel offers a special discount as follows: If
	the number of rooms booked is at least 10, the discount is 10%; at least 20, the discount
	is 20%; and at least 30, the discount is 30%. Also if rooms are booked for at least three
	days, then there is an additional 5% discount.

	Write a program that
		- loads the cost of renting one room and the sales tax rate
			from an input file (provided),
		- prompts the user to enter the number of rooms booked, and
		- prompts the user to enter the number of days the rooms are booked.

	The program outputs to an output file named (output.dat)
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.

	Your program must use appropriate named constants to store special values such as various discounts.
*/

//Include statements
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

//include the standard library file needed to read and write files

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 04" << endl << endl;

	//Variable declarations
	double roomRate, taxRate, discountRate, salesTax, totalRoomCost;
	int roomsBooked, days;
	//Add an ifstream variable to read the input file "input.dat" and open it.
	ifstream in;
	in.open("input.dat");

	//Add an ofstream variable to output the final results to output.dat.
	ofstream out;
	out.open("output.dat");

	//Program logic
	/*
		Open and read input.dat to get the cost of renting one room
		  and the sales tax rate.
		Prompt the user to provide the following:
		-the number of rooms booked and
		-the number of days the rooms are booked.
	*/

	in >> roomRate;
	in >> taxRate;

	cout << "Please enter the number of hotel rooms booked:" << endl;
	cin >> roomsBooked;
	cout << "Please enter the number of days the rooms are booked:" << endl;
	cin >> days;

	// Complete the appropriate calculations
	//   Calculate the discount rate
	if (roomsBooked < 10)
		discountRate = 0.0;
	else if (roomsBooked < 20)
		discountRate = 0.1;		//10% discount
	else if (roomsBooked < 30)
		discountRate = 0.2;		//20% discount
	else
		discountRate = 0.3;		//30% discount

	if (days >= 3)
		discountRate += 0.05;

	// Calculate totalRoomCost and salesTax

	totalRoomCost = (roomRate * days) * (1 - discountRate);
	salesTax = totalRoomCost * taxRate;

	/*
		Output to output.dat
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.
		Your output should look nice and neat
	*/

	out << fixed << setprecision(2);
	out << right << setw(30) << "Cost of renting one room ($):" << setw(8) << roomRate << endl;
	out << setw(30) << "Discount rate per room (%):" << setw(8) << discountRate << endl;
	out << setw(30) << "Number of rooms booked:" << setw(8) << roomsBooked << endl;
	out << setw(30) << "Number of days booked:" << setw(8) << days << endl;
	out << setw(30) << "Total cost of the rooms ($):" << setw(8) << totalRoomCost << endl;
	out << setw(30) << "Sales Tax ($):" << setw(8) << salesTax << endl;
	out << setw(30) << "Total billing amount ($):" << setw(8) << totalRoomCost + salesTax << endl;

	//Closing program statements
	in.close(); //Close the input and output files
	out.close();
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