//<main.cpp>
//CSIS 111-007

/*
ALGORITHM
- Get user's weight on Earth
- Get the user's planet choice as a string
	- Use a function to validate the user's planet name and return true if the name is 
	  valid and false if not using the following prototype:
		- bool validPlanet(string userInput, PlanetType& planet)
	- If the user does not input a correct planet output an error message (hint: put 
	  this error message in your validPlanet() function)
	- Keep prompting the user until you get a valid planet name (hint: use your 
	  validPlanet() function in a do-loop test condition):
		- do { //Prompt user for a planet name } while (!validPlanet(...));
- Identify the user's selected planet and set your planet enum variable accordingly 
  (hint: do this in validPlanet() using the PlanetType variable you passed by reference)
- Using a switch statement and the planet enum variable that was set by validPlanet() 
  calculate the user's weight on the selected planet in a function called calculateWeight(), 
  which takes a PlanetType and a float (the user’s weight on Earth) and returns a float 
  (the user’s weight on the selected planet).
- Output the result
*/


//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const double MERCURY_WEIGHT_MULTIPLE = 0.4155;
const double VENUS_WEIGHT_MULTIPLE = 0.8975;
const double EARTH_WEIGHT_MULTIPLE = 1.0;
const double MOON_WEIGHT_MULTIPLE = 0.166;
const double MARS_WEIGHT_MULTIPLE = 0.3507;
const double JUPITER_WEIGHT_MULTIPLE = 2.5374;
const double SATURN_WEIGHT_MULTIPLE = 1.0677;
const double URANUS_WEIGHT_MULTIPLE = 0.8947;
const double NEPTUNE_WEIGHT_MULTIPLE = 1.1794;
const double PLUTO_WEIGHT_MULTIPLE = 0.0899;

enum PlanetType {
	MERCURY,
	VENUS,
	EARTH,
	MOON,
	MARS,
	JUPITER,
	SATURN,
	URANUS,
	NEPTUNE,
	PLUTO,
	DEFAULT
};

//Function prototypes
void wait(); // given

// Function 1 - validates the user input and assigns the correct PlanetType to the planet argument
bool validPlanet(string userInput, PlanetType& planet);

// Function 2 - takes a PlanetType and a float (the user’s weight on Earth) and returns a float (the user’s weight on the selected planet).
float calculateWeight(PlanetType planet, float weight);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jared Miller -- Lab 07" << endl << endl;
	cout << fixed << setprecision(2);

	//Variable declarations
	float userWeight = 0.0;
	string userChoice = "";
	PlanetType planet = DEFAULT;

	//Program logic
	// Get user's weight on Earth
	cout << "Please enter your weight (in lbs): ";
	cin >> userWeight;
	while (cin.fail() || userWeight <= 0)
	{
		cin.clear();
		cin.ignore(10000000, '\n');
		cout << endl << "ERROR. Please enter a valid weight: " << endl;
		cin >> userWeight;
	}
	
	// Get the user's planet choice as a string
	cout << "Please enter a planet of your choosing:" << endl;
	cin.ignore(1);
	getline(cin, userChoice);

	// Validate and parse user choice
	while (!validPlanet(userChoice, planet))
	{
		cout << "ERROR. Please enter a valid planet: " << endl;
		cin.ignore(1);
		getline(cin, userChoice);
		cin.clear();
	}

	// Calculate and output new weight
	cout << "Your weight on " << userChoice << " would be ";
	cout << calculateWeight(planet, userWeight) << " lbs." << endl << endl;

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait() // given
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

// Function 1 - validates the user input and assigns the correct PlanetType to the planet argument
bool validPlanet(string userInput, PlanetType& planet)
{
	char leadingChar = toupper(userInput[0]);
	char secondChar = toupper(userInput[1]);

	switch (leadingChar)
	{
	case 'M':
		if (secondChar == 'E')
			planet = MERCURY;
		else if (secondChar == 'O')
			planet = MOON;
		else if (secondChar == 'A')
			planet = MARS;
		else
			return false;
		break;
	case 'V':
		planet = VENUS;
		break;
	case 'E':
		planet = EARTH;
		break;
	case 'J':
		planet = JUPITER;
		break;
	case 'S':
		planet = SATURN;
		break;
	case 'U':
		planet = URANUS;
		break;
	case 'N':
		planet = NEPTUNE;
		break;
	case 'P':
		planet = PLUTO;
		break;
	default:
		return false;
	}
	return true;
}

// Function 2 - takes a PlanetType and a float (the user’s weight on Earth) and returns a float (the user’s weight on the selected planet).
float calculateWeight(PlanetType planet, float weight)
{
	switch (planet)
	{
	case MERCURY:
		return weight * MERCURY_WEIGHT_MULTIPLE;
		break;
	case VENUS:
		return weight * VENUS_WEIGHT_MULTIPLE;
		break;
	case EARTH:
		return weight * EARTH_WEIGHT_MULTIPLE;
		break;
	case MOON:
		return weight * MOON_WEIGHT_MULTIPLE;
		break;
	case MARS:
		return weight * MARS_WEIGHT_MULTIPLE;
		break;
	case JUPITER:
		return weight * JUPITER_WEIGHT_MULTIPLE;
		break;
	case SATURN:
		return weight * SATURN_WEIGHT_MULTIPLE;
		break;
	case URANUS:
		return weight * URANUS_WEIGHT_MULTIPLE;
		break;
	case NEPTUNE:
		return weight * NEPTUNE_WEIGHT_MULTIPLE;
		break;
	case PLUTO:
		return weight * PLUTO_WEIGHT_MULTIPLE;
		break;
	default:
		cout << "ERROR. Invalid planet type";
		return 0.0;
		break;
	}
}