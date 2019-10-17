/*
	github.com/amattu2
	4/19/2019
	Revision 2 (10am 4-25-19)
*/
/*
Class: CMSC140 CRN
Instructor:
Project: 5
Description: A simple powerball simulator game
Due Date: 05/02/2019

I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here:
*/

/*
List of Input for the program:
	1.

List of Output from the program:
	1.


Pseudocode or Algorithm for the program:
	1.
*/


// Files
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <array>

// Namespaces
using namespace std;

// Variables (Static to course)
string college = "";
string class_name = "CMSC 140";
string class_instructor = "";
string coder_name = "";

// Variables (Static to project)
string project_no = "5";
string project_name = "CMSC Project 5";
string project_desc = "A simple powerball simulator";
string project_due = "05/02/2019";
int option_self_white = 0;
int option_self_red = 0;
int options_white[5];
int option_red = 0;
int options_white_pb[5];
int options_red_pb;

// Prototypes
void greet();
void sortArray(int array[], int size);
void displayArray(int arr1[], int size);
int getRandom(int min, int max); // getArandNum
int matching(int arr1[], int arr2[], int size); // compareArrays
void getRedSelection();
void getOptions();
void getWhiteSelection();
void generateWPB();
void generateRPB();

// Output Text
void output(string str, bool newline = true, bool car = false) {
	if (newline)
		cout << (car == true ? ">> " : "") << str << "\n";
	else
		cout << (car == true ? ">> " : "") << str;
}

// Main Function
int main() {
	// Intro Greeting
	greet();

	// Instructions
	output("Game instructions:", true, true);
	output("\tSelect 5 numbers from 1 to 69 for white balls.", true, false);
	output("\tSelect 1 number from 1 to 26 for the red ball.", true, false);
	output("\tThe prize is determined by how many of your numbers match the winning numbers.", true, false);

	// Get Input
	getOptions();
	getWhiteSelection();
	getRedSelection();
	generateWPB();
	generateRPB();

	// Results
	output("************ POWERBALL RESULTS ************\n", true, false);
	output("Your PowerBall Numbers:", true, true);
	displayArray(options_white, 5);
	output("[" + to_string(option_red) + "]", true, false);
	output("Winning PowerBall Numbers:", true, true);
	displayArray(options_white_pb, 5);
	output("[" + to_string(options_red_pb) + "]", true, false);
	output("This means you won " + to_string(matching(options_white, options_white_pb, 5)) + " point(s).", true, true);
	output("\n** NOTE: The last number in the set is the Power Ball Number.", true, false);
	output("******************************************\n", true, false);

	// Freeze UI
	output(coder_name);
	output(project_due);
	system("pause");
	return 0;
}

// Greet Function
void greet() {
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
}

// Get Options
void getOptions() {
	// Variables
	string o1, o2;

	// Get Option 1 (option_self_white)
	output("Would you like to pick the numbers for the white balls? (Y/N): ", false, true);
	getline(cin, o1);
	while (!cin.good() || (o1 != "Y" && o1 != "N")) {
		cin.clear();
		output("Invalid input.", true, false);
		output("Would you like to pick the numbers for the white balls? (Y/N): ", false, true);
		getline(cin, o1);
	}
	if (o1 == "Y") {
		option_self_white = 1;
	} else {
		option_self_white = 0;
	}

	// Get Option 2 (option_self_red)
	output("Would you like to pick the numbers for the red ball? (Y/N): ", false, true);
	getline(cin, o2);
	while (!cin.good() || (o2 != "Y" && o2 != "N")) {
		cin.clear();
		output("Invalid input.", true, false);
		output("Would you like to pick the numbers for the red ball? (Y/N): ", false, true);
		getline(cin, o2);
	}
	if (o2 == "Y") {
		option_self_red = 1;
	} else {
		option_self_red = 0;
	}
}

// Get Selection For White
void getWhiteSelection() {
	// Loops
	for (int i = 0; i < 5; i++) {
		if (option_self_white == 1) {
			// Variables
			int number;

			// Get Option
			output(to_string(i+1) + " Please enter a valid number between 1 and 69: ", false, true);
			cin >> number;
			while (!cin.good() || number < 1 || number > 69) {
				cin.clear();
				cin.ignore(10000, '\n');
				output("Invalid input.", true, false);
				output(to_string(i+1) + " Please enter a valid number between 1 and 69: ", false, true);
				cin >> number;
			}
			options_white[i] = number;
		} else {
			options_white[i] = getRandom(1, 69);
		}
	}
}

// Return random number
int getRandom(int min, int max) {
	return rand() % max + min;
}

// Get user red ball selection
void getRedSelection() {
	// Variables
	int number;

	// Checks
	if (option_self_red == 1) {
		output("Please enter a valid number between 1 and 26: ", false, true);
		cin >> number;
		while (!cin.good() || number < 1 || number > 26) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("Invalid input.", true, false);
			output("Please enter a valid number between 1 and 26: ", false, true);
			cin >> number;
		}
	} else {
		number = getRandom(1, 26);
	}

	// Return
	option_red = number;
}

// Generates White Winner PB
void generateWPB() {
	// Loops
	for (int i = 0; i < 5; i++) {
		options_white_pb[i] = getRandom(1, 69);
	}
}

// Generates Red Winner PB
void generateRPB() {
	options_red_pb = getRandom(1, 26);
}

// Compares two arrays
int matching(int arr1[], int arr2[], int length) {
	// Variables
	int matches = 0;

	// Checks
	if (length <= 0) { return 0; }

	// Loop
	for (int i = 0; i <= length; i++) {
		for (int x = 0; x <= length; x++) {
			if (arr1[i] == arr2[x]) {
				matches++;
			}
		}
	}

	// Return
	return matches;
}

// Displays a array
void displayArray(int arr[], int length) {
	// Checks
	if (length <= 0) { return; }

	sortArray(arr, length);

	// Loop
	for (int i = 0; i < length; i++) {
		output(to_string(arr[i]) + " ", false, false);
	}
}

// Sorts an array
void sortArray(int array[], int size) {
	bool swap;
	int temp;

	do {
		swap = false;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
