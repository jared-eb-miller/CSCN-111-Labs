//StudentTypeTest.cpp -- driver used to test StudentType implementation.
//CSIS 111-005


//Include statements
#include <iostream>
#include <string>
#include "StudentType.h"

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 10" << endl << endl;

	//Variable declarations
	StudentType student;	//declare your StudentType variable

	//Program logic -- set your StudentType instance variables using your set functions
	// then display your student data using you StudentType get functions.
	student.setFirstName("Jared");
	student.setLastName("Miller");
	student.setTestScore(92);
	student.setGrade('A');

	student.print();

	cout << endl;

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
