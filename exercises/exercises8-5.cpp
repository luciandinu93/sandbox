/*
 * Rewrite the previous progam to store each word in a separate element
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void open_read(const string& filename, vector<string>& vec, bool write=false)
{
	string buffer;
	ifstream inputFile;
	inputFile.open(filename);
	if(inputFile.is_open()) {
		while(getline(inputFile, buffer))
		{
			vec.push_back(buffer);
		}
	} else {
		cerr << "Could not open the file " << endl;
	}
	
	if(write){
		ofstream outputFile;
		outputFile.open("output.txt");
		for(const auto& line : vec) {
			outputFile << line << "\n";
		}
	}
}

int main() {
	vector<string> vec;
	open_read("to_remember.txt", vec, true);
	cout << "Content of to_remember.txt file" << endl;
	for(const auto& line : vec) {
		cout << line << endl;
	}
	vec = {};
	open_read("output.txt", vec);
	cout << "Content of output.txt file" << endl;
	for(const auto& line : vec) {
		cout << line << endl;
	}
}