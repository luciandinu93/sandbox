/*
 * Input: will contain four integers a, b, c, d
 * Output: Print the greatest of the four
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_value(const vector<int>& values) {
	int max = values[0];
	for(const auto& n : values) {
		if(n > max) {
			max = n;
		}
	}
	return max;
}

int main() {
	int ret;
	vector<int> values;
	for(int i = 0; i < 4; i++) {
		cin >> ret;
		values.push_back(ret);
	}
	cout << *(max_element(values.begin(), values.end()));
}