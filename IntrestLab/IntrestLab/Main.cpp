/* -- See assignment instructions below for the purpose of this assignment.

Interest on a credit card's unpaid balance is calculated using the average daily balance.
Suppose that netBalance is the balance shown in the bill, payment is the payment made,
d1 is the number of days in the billing cycle, and d2 is the number of days payment is
made before billing cycle. Then, the average daily balance is:

	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

If the interest rate per month is, say, 0.0152, then the interest on the unpaid balance is:

	interest = averageDailyBalance * 0.0152;

Write a program that accepts as input netBalance, payment, d1, d2, and interest rate per
month from the provided input file "input.dat". Place input.dat in the same directory as
the .cpp file when the Visual Studios project is created.

The program outputs the interest.

Format output to two decimal places.

*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Function prototypes
void wait();

int main()
{
	cout << "Jared Miller -- Lab 3" << endl << endl;
	//Variables
	double netBalance, payment, interestRatePerMonth, averageDailyBalance, interest;
	int d1, d2;
	ifstream in;

	//Open the input file using in.open()
	in.open("input.dat");

	//Get input for netBalance, payment, d1, d2, and interest rate per month using "in"
	//variable.
	in >> netBalance;
	in >> payment;
	in >> d1;
	in >> d2;
	in >> interestRatePerMonth;

	//Calculate averageDailyBalance using the formula in the heading above
	averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

	//Calculate interest using the formula in the heading above
	interest = averageDailyBalance * 0.0152;

	//Output the interest formatted to two decimal places
	//	Formatting cout
	//	cout "The interest is $##.##" replacing ##.## with the actual interest calculated
	cout << setprecision(2);
	cout << fixed;
	cout << "The interest is $" << interest << endl << endl;

	//Close the program
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