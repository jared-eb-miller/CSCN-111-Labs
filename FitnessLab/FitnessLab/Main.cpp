/*
The cost to become a member of a fitness center is as follows:
	(a) the senior citizens monthly membership discount is 30%;
	(b) the discount for chosing to prepay the annual membership cost is 15%; and
	(c) if more than five personal training sessions are bought and paid for, the discount on each session is 20% (the discounts in a and b above do not apply to personal
	training).

Write a menu-driven program that determines the annual cost of a new membership. Your program must contain
	a function that displays the general information about the fitness center and its charges,
	a function to get all of the necessary information to determine the membership cost, and (use pass-by-reference parameters)
	a function to determine the membership cost.

Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

Malik, Ch 6, Programming Exercise 25 (page 463)

ALGORITHM
	1) Display the general information about the fitness center and its charges
	2) Get the usere's preferences
		a. Display the menu of options
		b. Ask the user for their chioce (error check)
	3) Repeat Step 2 until the user's preferences have been eshausted
	4) Calculate the monthly membership cost
	5) Display calculated cost
*/

//Include statements
#include <iostream>
#include <iomanip> // needed to format the outputs in 'display_info' and TODO!!!

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const float MONTHLY_MEMBERSHIP_RATE = 25.00;
const float PERSONAL_SESSION_RATE = 50.00;
const float SENIOR_CITIZEN_DISCOUNT = 0.3;
const float ADVANCED_MEMBERSHIP_PAYMENT_DISCOUNT = 0.15;
const float	PERSONAL_SESSION_DISCOUNT = 0.2;

//Function prototypes

// Function 1 - display the initial information for the fitness center
void display_info();

// Function 2 - display and take input for the selection menu for user preferences
int main_menu(bool is_senior, bool is_annual, bool wants_training);

// Function 3 - recieves and checks the input from the user and then returns the checked value
int errorCheckInt();

// Function 4 - takes the user's chocie and carries out the control flow
void add_preference(
	int choice, 
	bool& is_senior,
	bool& is_annual,
	bool& wants_training,
	int& num_sessions
);

// Function 5 - calculates the membership cost given the user's preferences
float membership_cost(
	bool is_senior,
	bool is_annual,
	bool wants_training,
	int num_sessions
);

// Function - given
void wait();

int main()
{
	//Variable declarations
	bool is_senior = false;
	bool is_annual = false;
	bool wants_training = false;
	int user_choice = 0;
	int num_sessions = 0;

	//Program logic
	cout << fixed << setprecision(2) << left;

	do {
		display_info();
		user_choice = main_menu(is_senior ,is_annual, wants_training);
		add_preference(user_choice,
			is_senior,
			is_annual,
			wants_training,
			num_sessions
		);
		system("CLS");
	} while (user_choice != 4);

	display_info();

	cout << endl << "Your monthly cost of membership is: $" << membership_cost(
		is_senior,
		is_annual,
		wants_training,
		num_sessions
	) << endl << endl;

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
// Function 1 - display the initial information for the fitness center
void display_info()
{
	cout << "Jared Miller -- Lab 6" << endl << endl;
	cout << "******************** Swole is the Goal Fitness ********************" << endl << endl;
	cout << "              Size is the Prize - It's Gains O'Clock" << endl;
	cout << "At Swole is the Goal Fitness our goal is for you to get swole. It's" << endl;
	cout << "as simple as that. In keeping with our goal,  we want everyone to" << endl;
	cout << "get swole so we charge a fair price. We have nothing to hide." << endl << endl;
	cout << "Our monthly rate is $" << MONTHLY_MEMBERSHIP_RATE << ", but we do offer the following discounts:" << endl;
	cout << setw(55) << "\ta) Senior citizens (65 and older):" << "30%" << endl;
	cout << setw(55) << "\tb) Prepaid annual membership:" << "15%" << endl;
	cout << setw(55) << "\tc) Prepaid personal training sessions (5 or more):" << "20%" << endl << endl;
	cout << "*******************************************************************" << endl;
}

// Function 2 - display and take input for the selection menu for user preferences
int main_menu(bool is_senior, bool is_annual, bool wants_training)
{
	if (is_senior && is_annual && wants_training)
		return 4;
	
	cout << endl << "Membership Options Menu:" << endl;

	if (!is_senior)
		cout << "\tEnter '1' if you are a Senior Citizen (30% discount)" << endl;

	if (!is_annual)
		cout << "\tEnter '2' if you are interested in prepaying for your annual membership (15% discount)" << endl;

	if (!wants_training)
	{
		cout << "\tEnter '3' if you are interested in Personal Training Sessions" << endl;
		cout << "\t   ($50.00 per session -- more than 5 sessions earns you a 20% reduction in Personal Training Rates)" << endl;
	}

	cout << "\tEnter '4' if you are done" << endl;
	cout << "Please enter the number of your option above: ";

	return errorCheckInt();
}

// Function 3 - recieves and checks the input from the user and then returns the checked value
int errorCheckInt()
{
	int value = 0;
	cin >> value; // assumes that the prompt comes before the function call

	while (cin.fail() || value <= 0)
	{
		cout << endl << "ERROR. The value must be an integer from 1 to 4: ";
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> value;
	}
	return value;
}

// Function 4 - takes the user's chocie and carries out the control flow
void add_preference(
	int choice, 
	bool& is_senior, 
	bool& is_annual, 
	bool& wants_training, 
	int& num_sessoins
)
{
	switch (choice)
	{
	case 1: // Senior Citizen discount
		is_senior = true;
		break;
	case 2: // annual membership discount
		is_annual = true;
		break;
	case 3: // Personal Training Sessions discount
		wants_training = true;
		
		// ask the user how many sessoins to see if they qualify for the discount
		cout << "Please enter the number of sessions you would want: ";
		num_sessoins = errorCheckInt();
		break;
	case 4:
		break;
	default:
		cout << "ERROR. Please enter a number out of the available options." << endl;
		break;
	}
}

// Function 5 - calculates the membership cost given the user's preferences
float membership_cost(
	bool is_senior,
	bool is_annual,
	bool wants_training,
	int num_sessions
)
{
	// locals
	float running_cost = MONTHLY_MEMBERSHIP_RATE;
	float monthly_discount = 0;
	float personal_training_cost = num_sessions * PERSONAL_SESSION_RATE;

	if (is_senior)
		monthly_discount += SENIOR_CITIZEN_DISCOUNT;
	if (is_annual)
		monthly_discount += ADVANCED_MEMBERSHIP_PAYMENT_DISCOUNT;
	if (wants_training)
		personal_training_cost *= 1 - PERSONAL_SESSION_DISCOUNT;

	running_cost *= 1 - monthly_discount;
	running_cost += personal_training_cost;
	return running_cost;
}

// given
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
