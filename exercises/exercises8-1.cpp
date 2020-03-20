/*
 * Write a function that takes and returns an istream&. The function should read the stream until it hits
 * end-of-file. The function should print what it reads to the standard output. Reset the stream so that
 * it is valid before returning stream.
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
	return is;
}
 
int main() {
}
	