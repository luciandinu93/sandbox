/*
 * Input: You will be given two positive integers, a and b separated by a new line
 * Output: For each integer in n in the interval [a, b]:
 * if 1 <= n <= 9 then print English representation in lower case 
 * else if n > 9 it is even number print "even"
 * else if n > 9 it is odd number print "odd"
 */
 
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<int, string> digits = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"},
							   {7, "seven"}, {8, "eight"}, {9, "nine"}};
	int a, b;
	cin >> a >> b;
	for(auto i = a; i <= b; i++) {
		if(i < 10) {
			cout << digits.find(i)->second << endl;
		} else if (i % 2 == 0) {
			cout << "even" << endl;
		} else {
			cout << "odd" << endl;
		}
	}
}