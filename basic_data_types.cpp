/* 
 * Basic Data Types challange from HACKERRANK.COM
 * Input format: Input consists of following space-separated values: int, long, char, float, and double
 * Output format: Print each element on a new line in the same order as received from input.
 * Note that the floating point should be up to 3 decimals places and the double up to 9 decimal places. 
 */
 
 // the approach will be template usage and function overriding for float and double values
 #include <iostream>
 #include <fstream> // input will be read from file
 #include <string>
 #include <iomanip>
 #define FLOAT_PRECISION (3)
 #define DOUBLE_PRECISION (9)
 using namespace std;
 
class Input {
private:
	int int_element;
	long long int long_element;
	char char_element;
	float float_element;
	double double_element;
public:
	Input(const string& file_path);
	void display_input();
 };

Input::Input(const string& file_path) {
	ifstream inputFile;
	inputFile.open(file_path);
	if(inputFile.is_open()) {
		inputFile >> this->int_element;
		inputFile >> this->long_element;
		inputFile >> this->char_element;
		inputFile >> this->float_element;
		inputFile >> this->double_element;
	} else {
		cerr << "Could not open " << file_path << " file." << endl;
	}
}

void Input::display_input() {
	cout << this->int_element << endl;
	cout << this->long_element << endl;
	cout << this->char_element << endl;
	cout << fixed;
	cout << setprecision(3) << this->float_element << endl;
	cout << setprecision(9) << this->double_element << endl;
}
 
 int main() {
	Input input = Input("input.txt");
	input.display_input();
 }