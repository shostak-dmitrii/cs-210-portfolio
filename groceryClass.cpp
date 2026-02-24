#include "grocery.h"

// Function displayMenu displays the four menu options to the user
void Grocery::displayMenu() {
	cout << "1 - Find an item frequency" << endl;
	cout << "2 - List all items and quantities" << endl;
	cout << "3 - Print histogram" << endl;
	cout << "4 - Exit" << endl;
}

// Function openInputFile opens the input file and returns success status
bool Grocery::openInputFile(ifstream& t_inputFile, const string& t_fileName) {
	t_inputFile.open(t_fileName);
	return t_inputFile.is_open();
}

// Function openOutputFile opens the output file and returns success status
bool Grocery::openOutputFile(ofstream& t_outputFile, const string& t_fileName) {
	t_outputFile.open(t_fileName);
	return t_outputFile.is_open();
}

// Function readInputFile reads items from file and populates the map
map<string, int> Grocery::readInputFile(ifstream& t_inputFile) {
	map<string, int> tempMap; // Temporary map to store items and counts
	string item = ""; // Variable to hold the word read from file

	// Use getline in case of multiword items
	while (getline(t_inputFile, item)) {
		// macos fix. Remove hidden carriage return from windows files
		if (!item.empty() && item.back() == '\r') {
			item.pop_back();
		}

		if (!item.empty()) { 
			tempMap[item]++; 
		}
	}
	return tempMap;
}

// Function writeOutputFile backs up the map data to frequency.dat.
void Grocery::writeOutputFile(ofstream& t_outputFile, map<string, int> t_grocList) {
	// Iterate through the map and write pairs to the backup file
	for (const auto& entry : t_grocList) {
		t_outputFile << entry.first << " " << entry.second << endl;
	}
}

// findItem prompts user for a word and displays its purchase frequency
void Grocery::findItem(map<string, int> t_grocList) {
	string userItem = ""; // Store the item the user is looking for
	
	cout << "Enter the item you wish to find: ";
	cin >> userItem;

	// Check if item exists in map
	if (t_grocList.count(userItem)) {
		cout << userItem << " was purchased " << t_grocList[userItem] << " times" << endl;
	}
	else {
		cout << userItem << " was not found in todays records" << endl;
	}
	
	cout << "Press enter to continue ";
	cin.ignore(MAX_INTEGER, '\n');
	cin.get();
}

// Function listItems prints a list of all items and their numeric frequencies
void Grocery::listItems(map<string, int> t_grocList) {
	for (const auto& entry : t_grocList) {
		cout << entry.first << " " << entry.second << endl;
	}
}

//Function printHistogram prints a visual histogram using asterisks
void Grocery::printHistogram(map<string, int> t_grocList) {
	for (const auto& entry : t_grocList) {
		cout << left << setw(12) << entry.first << " ";
		// string constructor method
		cout << string(entry.second, '*') << endl;
	}
}