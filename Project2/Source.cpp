/*
	github.com/amattu2
	03/05/2019
	Revision V3 (9:29am, in class)
*/
/*
* Class: CMSC140 CRN
* Instructor:
* Project: #2
* Description: A simple program to interpret and convert different types of measurements
* Due Date: 03/03/2019

I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here:
*/

/*
List of Input for the program:
	1. country
	2. option_code:
		1 (Option 1) => cel
		2 (Option 2) => km
		3 (Option 3) => kg


List of Output from the program:
	1. far
	2. mi
	3. lb

Pseudocode or Algorithm for the program:
	1. greet()
	2. output()
	3. calcTemperature()
	4. calcDistance()
	5. calcWeight()
	6. main()
*/


// Files
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

// Namespaces
using namespace std;

// Variables (Static)
string college = "";
string class_name = "CMSC 140";
string class_instructor = "";
string coder_name = "";

// Variables (SBTC)
string project_no = "#2";
string project_name = "CMSC Project #2";
string project_desc = "A simple conversion toolkit designed to convert Distance, Weight, & Temperature.";
string project_due = "03/03/2019";

// Greet Function
int greet() {
	// Output
	cout << "<<------------------------------------->>" << "\n";
	cout << "Welcome to " << project_name << "\n";
	cout << "College: " << college << "\n";
	cout << "Class: " << class_name << "\n";
	cout << "Instructor: " << class_instructor << "\n";
	cout << "Author: " << coder_name << "\n";
	cout << "Project Name/Num: " << project_no << "\n";
	cout << "Description: " << project_desc << "\n";
	cout << "Due Date: " << project_due << "\n";
	cout << "<<------------------------------------->>" << "\n";

	// Return
	return 1;
}

// Output Text
int output(string str, bool newline = true) {
	if (newline)
		cout << str << "\n";
	else
		cout << str;

	return 1;
}


// Calculate Temperature (Cel => Far)
int calcTemperature() {
	// Variables
	float far;
	float cel;

	// Input
	output(">> Please enter the temperature in celsius: ", false);
	cin >> cel;

	// Calculate
	far = ((cel * 9) / 5) + 32;
	output(">> " + to_string(cel) + "c is " + to_string(static_cast<int>(far)) + "f");

	// Return
	return 1;
}

// Calculate Distance (Km => Mi)
int calcDistance() {
	// Variables
	float km;
	float mi;

	// Input
	output(">> Please enter the distance in kilometers: ", false);
	cin >> km;

	// Checks / Validation
	if (km < 0) {
		output(">> You may not enter a negative number here.", true);
		calcDistance();
		return 0;
	}

	// Calculate
	mi = km / 1.609;
	output(">> " + to_string(km) + "km is approx ", false);
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << mi;
	output("mi");

	// Return
	return 1;
}

// Calculate Weight (Kg => lb)
int calcWeight() {
	// Variables
	float kg;
	float lb;

	// Input
	output(">> Please enter the weight in kilograms: ", false);
	cin >> kg;

	// Checks / Validation
	if (kg < 0) {
		output(">> You may not enter a negative number here.", true);
		calcWeight();
		return 0;
	}

	// Calculate
	lb = kg * 2.205;
	output(">> " + to_string(kg) + "kg is approx ", false);
	cout << fixed << showpoint;
	cout << setprecision(1);
	cout << lb;
	output("lb");

	// Return
	return 1;
}

// Get User Country
string getCountry() {
	// Variable(s)
	string country;

	// Get Input
	output(">> What country are currently in? ", false);
	getline(cin, country);

	// Return
	return country;
}

// Main Function
int main() {
	// Variable(s)
	int option_code;
	string country;

	// Intro Greeting, Get country
	greet();
	country = getCountry();

	// Instructions
	output(">> Conversion Toolkit");
	output("\t1). Enter 1 to convert Temperature");
	output("\t2). Enter 2 to convert Distance");
	output("\t3). Enter 3 to convert Weight");
	output("\t4). Enter 4 to quit");
	output(">> To begin, enter the corresponding number/option: ", false);
	cin >> option_code;

	// Checks
	if (option_code == 1)
		calcTemperature();
	else if (option_code == 2)
		calcDistance();
	else if (option_code == 3)
		calcWeight();
	else if (option_code == 4)
		output(">> Goodbye");
	else
		output(">> You have entered an invalid option.");

	// Freeze UI
	system("pause");
	return 0;
}
