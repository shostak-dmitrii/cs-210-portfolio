#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <limits>

using namespace std;
const int MAX_INTEGER = numeric_limits<int>::max();

// Class Grocery handles file i/o and data processing for the grocer item tracker
class Grocery {
private:
	// Private members (Pascal Case)
	string DataBackupFile = "frequency.dat"; // file name for data backup

public:
	// Public methods (camelCase)
	void displayMenu();
	bool openInputFile(ifstream& t_inputFile, const string& t_fileName);
	bool openOutputFile(ofstream& t_outputFile, const string& t_fileName);
	map<string, int> readInputFile(ifstream& t_inputFile);
	void writeOutputFile(ofstream& t_outputFile, map<string, int> t_grocList);
	void findItem(map<string, int> t_grocList);
	void listItems(map<string, int> t_grocList);
	void printHistogram(map<string, int> t_grocList);

};