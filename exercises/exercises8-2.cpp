/*
 * Exercise 8-2: Test your function by calling it, passing cin as argument.
 */
 
#include <iostream>
#include <string>
using namespace std;

istream& read_stream(istream& is) {
	string buffer;
	while(!is.eof()) {
		is >> buffer;
		cout << buffer << endl;
	}
	is.clear();
	cout << "end of stream" << endl;
	return is;
}
 
int main() {
	read_stream(cin);
}
	