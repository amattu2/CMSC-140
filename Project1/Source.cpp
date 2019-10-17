/*
* Class: CMSC140 CRN
* Instructor:
* Project: #1 (Rev. 1.1a)
* Description: A simple chat/conversion bot
* Due Date: 2/17/2019

I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: 
*/

/*
List of Input for the program:
	1. visitor_name
	2. visitor_age
	3. number_1
	4. number_2

List of Output from the program:
	1. [All header info]
	2. Welcome to my program
	3. Nice to meet you <visitor_name>
	4. I want to do math for you [...]
	5. [Did you know] x 4
	6. Please enter a single number
	7. Cool. Please enter one more single number
	8. Divide number_2 / number_1

Pseudocode or Algorithm for the program: (be sure to indent items with control structure)
	1. greet
	2. output
	3. main
*/


// Files / Includes
#include <iostream>
#include <string>

// Namespaces
using namespace std;

// Variables (Static)
const string college = "";
const string class_name = "CMSC 140";
const string class_instructor = "";
const string coder_name = "";

// Variables (Semi-Static, Change with each project)
const string project_no = "#1";
const string project_name = "CMSC Project #1";
const string project_desc = "A simple chat/conversion bot";
const string project_due = "02/17/2019";

// Variables (Project Dependant)
const string did_you_know_prefix = "[Did you know?] ";
const string did_you_know = did_you_know_prefix + "The age you entered is equivelent to: ";
const string robot_name = "Computer";
const int days_per_month = 30;
const int months_per_year = 12;
const int dog_years_per_year = 7;
const int fish_years_per_year = 5;
string visitor_name;
int visitor_age;
int number_1;
int number_2;

// Greet Function, Designed to make outputting project information easier
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

// Output Text Function, Makes outputting (using cout) easier
int output(string str, bool newline = true) {
	if (newline)
		cout << "[" << robot_name << "]: " << str << "\n";
	else
		cout << "[" << robot_name << "]: " << str;

	return 1;
}

// Main Function
int main() {
	// Intro Greeting
	greet();

	// Get Name
	output("Hello, welcome to my program. Please enter your name: ", false);
	getline(cin, visitor_name);
	output("Nice to meet you, " + visitor_name + ".");

	// Get Age
	output("I want to do some math for you. Please enter your age in years: ", false);
	cin >> visitor_age;
	output("You entered: " + to_string(visitor_age) + "yrs.");
	output(did_you_know + to_string(visitor_age * months_per_year) + " months old");
	output(did_you_know + to_string(visitor_age * months_per_year * days_per_month) + " (aprx) days old");
	output(did_you_know + to_string(visitor_age * dog_years_per_year) + " dog years old");
	output(did_you_know + to_string(visitor_age * fish_years_per_year) + " fish years old");

	// Get Numbers / Perform Operations
	output("Lets play a game, " + visitor_name + ". Please enter a single number (Eg. 4): ", false);
	cin >> number_1;
	output("Cool. Please enter one more single number (Eg. 9): ", false);
	cin >> number_2;
	output("Using standardized C++ operators (Like: '+' or '/'), we can add or divide the numbers you just gave me.");
	output(did_you_know_prefix + "If we divide " + to_string(number_1) + " by " + to_string(number_2) + " we get " + to_string(static_cast<float>(number_1 / number_2)));
	output(did_you_know_prefix + "If we add " + to_string(number_1) + " to " + to_string(number_2) + " we get " + to_string(number_1 + number_2));

	// Freeze UI
	system("pause");
	system("cls");
	main();
	return 0;
}
