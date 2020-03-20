/*
 * Write a function to open a file for input and read its contents into a vector of strings,
 * storing each line as a separate element in the vector.
 */
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void open_read(const string& filename, vector<string>& lineVector)
{
	string buffer;
	ifstream inputFile;
	inputFile.open(filename);
	if(inputFile.is_open()) {
		while(getline(inputFile, buffer))
		{
			lineVector.push_back(buffer);
		}
	} else {
		cerr << "Could not open the file " << endl;
	}
}

int main() {
	vector<string> lineVector;
	open_read("input.txt", lineVector);
	for(const auto& line : lineVector) {
		cout << line << endl;
	}
}