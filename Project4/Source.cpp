/*
	github.com/amattu2
	4/4/2019
	Revision 2 (9:15am 4/9/19)
*/
/*
Class: CMSC140 CRN
Instructor:
Project: 4
Description: A simple employee absence calculator.
Due Date: 04/14/2019

I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here:
*/

/*
List of Input for the program:
	1. employeeCount
	2. employeeAbsenses
	3. eID
	4. eAB

List of Output from the program:
	1. display a students� full name
	2. display a due date
	3. display the user full name
	4. Each employee number (ID) and the number of days missed
	5. The average number of days a company's employees are absenting


Pseudocode or Algorithm for the program:
	1. int getEmployeeCount()
	2. int getEmployeeAbsenses(int employees)
	3. double getEmployeeAbsenseAvg(int employees, int absenses)
	4. void greet()
	5. int main()
	6. void output()
*/


// Files
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// Namespaces
using namespace std;

// Variables (Static to course)
string college = "";
string class_name = "CMSC 140";
string class_instructor = "";
string coder_name = "";

// Variables (Static to project)
string project_no = "4";
string project_name = "CMSC Project 4";
string project_desc = "A employee absense calculator.";
string project_due = "04/14/2019";
ofstream logFile("employeeAbsences.txt");
int employeeCount = 0;
int employeeAbsences = 0;

// Prototypes
int getEmployeeCount(); // NumOfEmployees
int getEmployeeAbsenses(int employees); // TotDaysAbsent
double getEmployeeAbsenseAvg(int employees, int absenses);
void greet();

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

	// Variables
	employeeCount = getEmployeeCount();
	employeeAbsences = getEmployeeAbsenses(employeeCount);

	// Write to log
	logFile << "\nThe " << employeeCount << " employees were absent from work for a total of " << employeeAbsences << " work days.\n";
	logFile << "The average number of days spent absent are " << getEmployeeAbsenseAvg(employeeAbsences, employeeCount) << " days\n\n";
	logFile << "Coded by: " << coder_name;

	// Freeze UI
	output(coder_name);
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

// Get Organization Employee Count
int getEmployeeCount() {
	// Variables
	int employees;

	// Get input
	output("Please enter the total number of employees in your organization: ", false, true);
	cin >> employees;
	while (!cin.good() || employees <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		output("Please enter a valid number above 0.", true, false);
		output("Please enter the total number of employees in your organization: ", false, true);
		cin >> employees;
	}

	// Return
	return employees;
}

// Get Employee Personal Absenses
int getEmployeeAbsenses(int employees) {
	// Variables
	int totalAbsenes = 0;

	// Write Log File Header
	logFile << "COMPANY INSIGHT REPORT\n";
	logFile << "ID\t\tAbsenses\n";

	// Loop
	for (int i = 1; i <= employees; i++) {
		// Variables
		string eID = "";
		int eAB = 0;

		// Get Employee ID
		output("Please enter the reference ID for employee #" + to_string(i) + ": ", false, true);
		cin.ignore(10000, '\n');
		getline(cin, eID);
		while (!cin.good()) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("For one reason or another, that was invalid.", true, false);
			output("Please enter a valid 4-digit reference number/code: ", false, true);
			cin.ignore(10000, '\n');
			getline(cin, eID);
		}

		// Get Employee Absenses
		output("Please enter the TOTAL number of absenses for this employee: ", false, true);
		cin >> eAB;
		while (!cin.good() || eAB < 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("Please enter a valid number above -1.", true, false);
			output("Please enter the TOTAL number of absenses for this employee: ", false, true);
			cin >> eAB;
		}

		// Write to file
		logFile << eID << "\t\t\t" << eAB << "\n";

		// Calculate totals
		totalAbsenes += eAB;
	}

	// Return
	return totalAbsenes;
}

// Calculate employee absense averages
double getEmployeeAbsenseAvg(int absenses, int employees) {
	// Variables
	double average;

	// Calculation
	average = static_cast<double>(absenses) / static_cast<double>(employees);

	// Return
	return average;
}
