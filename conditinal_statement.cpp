#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int digit;
	map<int, string> digits = { {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
	{6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};
	cin >> digit;
	if(digit < 10 && digit > 0) {
		cout << digits.find(digit)->second;
	}
	else {
		cout << "Greater than 9";
	}
}
