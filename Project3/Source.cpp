/*
	github.com/amattu2
	3/26/2019
	Revision 5 (9:25am 04/02/2019)
*/
/*
Class: CMSC140 CRN
Instructor:
Project: 3
Description: A simple hotel occupancy calculator.
Due Date: 3/31/2019

I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here:
*/

/*
List of Input for the program:
	1. floor_count
	2. occ_single
	3. occ_double
	4. occ_king
	5. occ_suite
	6. hotel_city

List of Output from the program:
	1. hotel_city
	2. college
	3. class_name
	4. class_instructor
	5. coder_name (x2)
	6. project_no
	7. project_name
	8. project_desc
	9. project_due
	10. occ_single
	11. occ_double
	12. occ_king
	13. occ_suite
	14. unoccupied
	15. least_rooms
	16. least_rooms_floor
	17. total_rooms

Pseudocode or Algorithm for the program:
	1. output
	2. getOccupancy
	3. getLocation
	4. getFloors
	5. main
	6. greet
	7. Goto (Label)
	8. If-Stmt
	9. For (Loop)
*/


// Files
#include <iostream>
#include <iomanip>
#include <string>

// Namespaces
using namespace std;

// Variables (Static to course)
string college = "";
string class_name = "CMSC 140";
string class_instructor = "";
string coder_name = "";

// Variables (Static to project)
string project_no = "3";
string project_name = "CMSC Project 3";
string project_desc = "A simple hotel occupancy calculator.";
string project_due = "03/31/2019";
const int floor_max = 5;
const int floor_min = 1;
const int room_max = 30;
const int room_min = 1;
const int cost_single = 60;
const int cost_double = 75;
const int cost_king = 100;
const int cost_suite = 150;
string hotel_city = "";
int floor_count = 0;
int unoccupied = 0;
int occ_single = 0;
int occ_double = 0;
int occ_king = 0;
int occ_suite = 0;
int total_rooms = 0;
int least_rooms = 0;
int least_rooms_floor = 0;

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
int output(string str, bool newline = true, bool car = false) {
	if (newline)
		cout << (car == true ? ">> " : "") << str << "\n";
	else
		cout << (car == true ? ">> " : "") << str;

	return 1;
}

// Get Hotel Location
string getLocation() {
	retryLocation:

	// Variables
	string location;

	// Get Input
	output(">> Please enter the location (city) of this hotel chain: ", false);
	getline(cin, location);

	// Checks
	if (location.empty()) {
		goto retryLocation;
		return false;
	} else {
		return location;
	}
}

// Get Hotel floors
int getFloors() {
	retryFloors:

	// Variables
	int floors;

	// Get Input
	output(">> Please enter the total number of floors in this hotel: ", false);
	cin >> floors;

	// Checks
	if (!cin.good() || floors > floor_max || floors < floor_min) {
		cin.clear();
		cin.ignore(10000, '\n');
		output("Maximum number of floors is " + to_string(floor_max) + " and minimum is " + to_string(floor_min) + ".");
		goto retryFloors;
		return 0;
	} else {
		return floors;
	}
}

// Get Hotel occupancy
int getOccupancy() {
	for (int i = 1; i <= floor_count; i++) {
		// Variables
		int floor_rooms = 0;
		int floor_occupied = 0;
		int floor_single = 0;
		int floor_double = 0;
		int floor_king = 0;
		int floor_suite = 0;

		// Get Room Count
		output(">> Please enter the total number of rooms on the " + to_string(i) + (i == 1 ? "st" : "") + (i == 2 ? "nd" : "") + (i == 3 ? "rd" : "") + (i == 4 || i == 5 ? "th" : "") + " floor: ", false);
		cin >> floor_rooms;

		// Check Room Count
		if (!cin.good()) {
			output("Invalid input");
			cin.clear();
			cin.ignore(10000, '\n');
			i--;
			continue;
		} else if (floor_rooms > room_max || floor_rooms < room_min) {
			output("Maximum number of rooms is " + to_string(room_max) + " and minimum is " + to_string(room_min) + ".");
			cin.clear();
			cin.ignore(10000, '\n');
			i--;
			continue;
		}

		// Get Single Rooms
		output("\tHow many SINGLE rooms are occupied? ", false);
		cin >> floor_single;
		while ((cin.good() == false || floor_single < 0)) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("\tInvalid input\n\tHow many SINGLE rooms are occupied? ", false);
			cin >> floor_single;
		}

		// Get Double Rooms
		output("\tHow many DOUBLE rooms are occupied? ", false);
		cin >> floor_double;
		while ((cin.good() == false || floor_double < 0)) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("\tInvalid input\n\tHow many DOUBLE rooms are occupied? ", false);
			cin >> floor_double;
		}

		// Get King Rooms
		output("\tHow many KING rooms are occupied?   ", false);
		cin >> floor_king;
		while ((cin.good() == false || floor_king < 0)) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("\tInvalid input\n\tHow many KING rooms are occupied? ", false);
			cin >> floor_king;
		}

		// Get Suite Rooms
		output("\tHow many SUITE rooms are occupied?  ", false);
		cin >> floor_suite;
		while ((cin.good() == false || floor_suite < 0)) {
			cin.clear();
			cin.ignore(10000, '\n');
			output("\tInvalid input\n\tHow many SUITE rooms are occupied? ", false);
			cin >> floor_suite;
		}

		// Check Total Floor Rooms
		if ((floor_single + floor_double + floor_king + floor_suite) > floor_rooms) {
			// Variables
			int option_code;

			// Message
			output("The total number of rooms is less than the occupied number of rooms you entered.");
			output(">> Your Options:");
			output("\tEnter 1 to re-configure this floor");
			output("\tEnter 2 to automatically adjust the total number of rooms");
			output(">> Option: ", false);
			cin >> option_code;

			// Checks
			if (option_code == 1) {
				i--;
				continue;
			} else if (option_code == 2 && (floor_single + floor_double + floor_king + floor_suite) <= room_max) {
				// Variables
				floor_rooms = (floor_single + floor_double + floor_king + floor_suite);
				floor_occupied = (floor_single + floor_double + floor_king + floor_suite);
				occ_single += floor_single;
				occ_double += floor_double;
				occ_king += floor_king;
				occ_suite += floor_suite;
				total_rooms += floor_rooms;
			} else if ((option_code != 2 || option_code != 1) || (floor_single + floor_double + floor_king + floor_suite) > room_max) {
				output("Oops. Either you entered an invalid option or the corrected number of rooms exceeds the maxiumum.");
				output("Retrying the configuration for this floor.");
				i--;
				continue;
			}
		} else {
			// Variables
			floor_occupied = (floor_single + floor_double + floor_king + floor_suite);
			occ_single += floor_single;
			occ_double += floor_double;
			occ_king += floor_king;
			occ_suite += floor_suite;
			total_rooms += floor_rooms;
		}

		// Check least number of rooms
		if (least_rooms_floor == 0) {
			least_rooms = floor_occupied;
			least_rooms_floor = i;
		} else if (least_rooms_floor != 0 && floor_occupied < least_rooms) {
			least_rooms = floor_occupied;
			least_rooms_floor = i;
		}
	}

	return 1;
}

// Main Function
int main() {
	// Intro Greeting
	greet();

	// Variables
	hotel_city = getLocation();
	floor_count = getFloors();
	int occ_status = getOccupancy();
	int total_income = (occ_single * cost_single) + (occ_double * cost_double) + (occ_king * cost_king) + (occ_suite * cost_suite);
	int total_occ = (occ_single + occ_double + occ_king + occ_suite);
	int total_vac = total_rooms - total_occ;
	float perc_occ = static_cast<float>(total_occ) / static_cast<float>(total_rooms) * 100;

	// Insight Message
	output("<<------------------------------------->>", true, false);
	output("Hotel Occupancy Insight: [Location " + hotel_city + "]", true, false);
	output("Single Room\tDouble Room\tKing Room\tSuite Room\t", true, false);
	output("      " + to_string(occ_single) + "\t\t      " + to_string(occ_double) + "\t\t   " + to_string(occ_king) + "\t\t    " + to_string(occ_suite));
	output("Total Income: $" + to_string(total_income));
	output("Total Rooms: " + to_string(total_rooms));
	output("Total Occupancy: " + to_string(total_occ) + " [", false, false);
	cout << setprecision(2) << fixed << perc_occ;
	output("% Occupied]", true, false);
	output("Total Vacancy: " + to_string(total_vac));
	output("Floor with the least occupied rooms: #" + to_string(least_rooms_floor) + " with only " + to_string(least_rooms) + " rooms occupied.", true, false);
	if (perc_occ <= 60) { output("** Try to increase occupancy", true, false); }
	output("<<------------------------------------->>", true, false);

	// Freeze UI
	output(coder_name);
	system("pause");
	return 0;
}
