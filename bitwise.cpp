#include <iostream>
using namespace std;

int main() {
	bool a = true;
	bool b = true;
	bool c;
	int carry = 1;
	int sum = 0;
	
	cout << "a + b = " << a + b << endl;
	// cout << "a & b = " << a & b << endl; - error 
	// cout << "a && b = " << a && b << endl; - error
	cout << "!a = " << !a << endl;
	cout << "~a = " << ~a << endl;
	cout << "a + b + carry = " << a + b + carry << endl;
	c = a + b;
	cout << "c = " << c << endl;
	cout << "c % 2 = " << c % 2 << endl;
	cout << "c / 2 = " << c / 2 << endl;
	c = a + b;
	cout << "c = a + b = " << c << endl;
}