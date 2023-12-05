#pragma once

#include <string>

class StudentType
{
private:
	std::string studentFName;
	std::string studentLName;
	int testScore; // Test score must be between 0 and 100
	char grade; // Ex. 'A', 'B', etc.

public:
	// Function 1 - takes a string as an argument and sets the private data member, 
	//    'studentFName', to the string passed in
	void setFirstName(std::string firstName);

	// Function 2 - takes a string as an argument and sets the private data member, 
	//    'studentLName', to the string passed in
	void setLastName(std::string lastName);

	// Function 3 - takes an int as an argument and sets the private data member, 
	//    'testScore', to the int passed in
	void setTestScore(int score);

	// Function 4 - takes a char as an argument and sets the private data member, 
	//    'grade', to the char passed in
	void setGrade(char gr);

	// Function 5 - takes no arguments and returns the value of the private data 
	//    member, 'studentFName'
	std::string getFirstName() const;

	// Function 6 - takes no arguments and returns the value of the private data 
	//    member, 'studentLName'
	std::string getLastName() const;

	// Function 7 - takes no arguments and returns the value of the private data 
	//    member, 'testScore'
	int getTestScore() const;

	// Function 8 - takes no arguments and returns the value of the private data 
	//    member, 'grade'
	char getGrade() const;

	// Function 9 - takes no arguments and returns nothing. It prints the student object
	//    and all of its data members
	void print() const;
};
