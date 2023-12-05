#include "StudentType.h"
#include <string>
#include <iostream>
#include <iomanip>

// class implementation functions


// Function 1 - takes a string as an argument and sets the private data member, 
	//    'studentFName', to the string passed in
void StudentType::setFirstName(std::string firstName)
{
	studentFName = firstName;
}

// Function 2 - takes a string as an argument and sets the private data member, 
//    'studentLName', to the string passed in
void StudentType::setLastName(std::string lastName)
{
	studentLName = lastName;
}

// Function 3 - takes an int as an argument and sets the private data member, 
//    'testScore', to the int passed in
void StudentType::setTestScore(int score)
{
	testScore = score;
}

// Function 4 - takes a char as an argument and sets the private data member, 
//    'grade', to the char passed in
void StudentType::setGrade(char gr)
{
	grade = gr;
}

// Function 5 - takes no arguments and returns the value of the private data 
//    member, 'studentFName'
std::string StudentType::getFirstName() const
{
	return studentFName;
}

// Function 6 - takes no arguments and returns the value of the private data 
//    member, 'studentLName'
std::string StudentType::getLastName() const
{
	return studentLName;
}

// Function 7 - takes no arguments and returns the value of the private data 
//    member, 'testScore'
int StudentType::getTestScore() const
{
	return testScore;
}

// Function 8 - takes no arguments and returns the value of the private data 
//    member, 'grade'
char StudentType::getGrade() const
{
	return grade;
}

// Function 9 - takes no arguments and returns nothing. It prints the student object
//    and all of its data members
void StudentType::print() const
{
	const int DATA_COLUMN_WIDTH = 3;

	std::cout << studentFName << " " << studentLName << ":" << std::endl;
	std::cout << std::right;
	std::cout << "  Grade:      " << std::setw(DATA_COLUMN_WIDTH) << grade << std::endl; 
	std::cout << "  Test Score: " << std::setw(DATA_COLUMN_WIDTH) << testScore << std::endl; 
}