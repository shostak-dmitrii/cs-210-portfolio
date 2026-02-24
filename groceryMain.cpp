/*
* Dmitrii Shostak
* Project Three Corner Grocer
* Analyzes grocery purchase records and provides frequency data and histogram
*/

#include "grocery.h"

using namespace std;

// Prototypes for helper functions
int getInteger(int, int, string);
string printStars(int);
void pause(string = "Press enter to continue ");
void cls();

const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
const string OUTPUT_FILE = "frequency.dat"; // .dat

int main() {
	Grocery myGrocery; // Class instance
	ifstream inputFile; // Input file stream
	ofstream outputFile; // Output file stream
	map<string, int> grocList; // Map to store item frequencies
	int selection = 0; // User menu choice

	// Open Input File
	if (myGrocery.openInputFile(inputFile, INPUT_FILE)) {
		cout << "Input File Opened " << endl;
	}
	else {
		cerr << "Error in file " << endl;
		return EXIT_FAILURE;
	}

	// Open Output File (Backup)
	if (myGrocery.openOutputFile(outputFile, OUTPUT_FILE)) {
		cout << "Output File Opened " << endl;
	}
	else {
		cerr << "Error in file " << endl;
		return EXIT_FAILURE;
	}

	// Pause, Clear, Read, Write sequence
	pause("Press enter to read the file ");
	cls();
	grocList = myGrocery.readInputFile(inputFile);
	myGrocery.writeOutputFile(outputFile, grocList);

	// Loop menu until exit
	do {
		myGrocery.displayMenu();
		selection = getInteger(1, 4, "Please select menu option ");

		switch (selection) {
		case 1:
			myGrocery.findItem(grocList);
			cls(); // Clears screen after finding item
			break;
		case 2:
			myGrocery.listItems(grocList);
			break;
		case 3:
			myGrocery.printHistogram(grocList);
			break;
		case 4:
			break; // Exit
		default:
			cout << "Opps we should never get here ...." << endl;
			break;
		}
	} while (selection != 4);

	// Cleanup
	inputFile.close();
	outputFile.close();

	return 0;
} //main

// Validates integer within range
int getInteger(int lowest, int highest, string prompt) {
	int number = 0;
	bool needNumber = true;
	prompt = prompt + to_string(lowest) + " and " + to_string(highest) + " ";
	
	do {
		cout << prompt;
		cin >> number;
		if (cin.fail()) {
			cout << "Must be a number " << endl;
			cin.clear();
			cin.ignore(MAX_INTEGER, char(10));  // '\n'
			continue;
		}
		cin.ignore(MAX_INTEGER, '\n');
		needNumber = ((number < lowest) || (number > highest)); //check if in bounds
		if (needNumber) {
			cout << "\aInvalid number" << endl;
		}
	} while (needNumber);
	return number;
}

string printStars(int numStars) {
	return string(numStars, '*');
}

void pause(string prompt) {
	cout << prompt;
	cin.get();
}

void cls() {
	std::cout << "\x1B[2J\x1B[H";  // ANSI escape codes to clear screen and move cursor to top-left
	std::cout.flush();
}
